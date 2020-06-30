/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 02:56:10 by amamy             #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2020/03/07 01:06:23 by amamy            ###   ########.fr       */
=======
/*   Updated: 2020/03/07 20:00:14 by amamy            ###   ########.fr       */
>>>>>>> dc09d2502534d322ed60adfc9059ac93e8456b3f
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"
#include "tokens.h"
#include "ft_printf.h"

/*
** ==================== labels_calls_computing ====================
** Because labels alues can be calculated only at the last moment, we cannot
** get them during the parsing.
** This function goes through the list of label_call and assign their value.
*/

static void			labels_calls_computing(t_data *data)
{
	t_label_call	*current;
	int				line_mem_address;

	current = data->label_calls;
	if (!current)
		return ;
	while (current)
	{
		line_mem_address = current->token->code_line->mem_address;
		current->value = current->target->mem_address - line_mem_address;
		current = current->next;
	}
}

/*
** ==================== update_instruction_size_and_address ====================
** Used in parse_line() to keep memory count : to assign the adress of the instruction
** and the size of this instruction.
*/

static void			update_instruction_size_and_address(t_data *data, t_code_line *code_line, int current_byte[1])
{
	if (data->op_tab[code_line->op_code].encoding_byte)
		code_line->instruction_size = (code_line->instruction_size + 2);
	else
		code_line->instruction_size++;
	code_line->mem_address = current_byte[0];
}

/*
** ==================== parse_line ====================
** This functions parses a line containing an instruction.
** For this, it will verify that the syntax is valid, keep the count
** of the codes size and check for additional error if error.
*/

static int			parse_line(t_data *data, t_code_line *code_line, int inst_position, int current_byte[1])
{
	if (!check_instruction_validity(data, code_line, inst_position))
		return (0);
	update_instruction_size_and_address(data, code_line, current_byte);
	if (!code_line->errors)
	{
		if (!parse_instruction(data, code_line, inst_position))
			return (error_code_line(code_line, MEMORY_ALLOCATION_ERROR, 0));
	}
	check_for_additional_errors(data, code_line);
	*current_byte = *current_byte + code_line->instruction_size;
	if (code_line->errors)
		data->errors = 1;
	return (1);
}

/*
** ==================== skip_label_only_lines ====================
** Used in parser to skip lines containing only label declaration
** in it as we only parse instructions.
*/

static t_code_line	*skip_label_only_lines(t_code_line *code_line)
{
	while (is_only_label(code_line))
		code_line = code_line->next;
	return (code_line);
}

/*
** ==================== parser ====================
** The role of the parser is to retrieve the informations 
** related to the lexemes detected by lexer previously.
** To achieve this we send lines with instruction in parse_line()
*/

int					parser(t_data **data, t_code_line **code_line)
{
	int			current_byte;
	int			inst_token_position;
	t_code_line	*current_line;

	current_byte = 0;
	inst_token_position = 0;
	current_line = (*code_line);
	if (!(parse_label_declarations(*data, *code_line)))
		return (0);
	while ((current_line = skip_label_only_lines(current_line)))
	{
		if (current_line->token->type == TOKEN_TYPE_LABEL)
			inst_token_position = 1;
		else
			inst_token_position = 0;
		if (!(parse_line(*data, current_line, inst_token_position, &current_byte)))
			return (0);
		if (current_line)
			current_line = current_line->next;
	}
	labels_calls_computing(*data);
	(*data)->instruction_section_size = current_byte;
	return (1);
}
