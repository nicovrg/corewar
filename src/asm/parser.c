/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 02:56:10 by amamy             #+#    #+#             */
/*   Updated: 2020/03/06 15:25:10 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"
#include "tokens.h"
#include "ft_printf.h"


static void	labels_calls_computing(t_data *data)
{
	t_label_call	*current;

	current = data->label_calls;
	if (!current)
		return ;
	while (current)
	{
		current->value = current->target->mem_address - current->token->code_line->mem_address;
		current = current->next;
	}
}

static void update_instruction_size_and_address(t_data *data, t_code_line *code_line, int current_byte[1])
{
	if (data->op_tab[code_line->op_code].encoding_byte)
		code_line->instruction_size = (code_line->instruction_size + 2);
	else
		code_line->instruction_size++;
	code_line->mem_address = current_byte[0];
}

static int	parse_line(t_data *data, t_code_line *code_line, int inst_position, int current_byte[1])
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
	*current_byte = *current_byte +code_line->instruction_size;
	if (code_line->errors)
		data->errors = 1;
	return (1);
}

static t_code_line	*skip_label_only_lines(t_code_line *code_line)
{
	while (is_only_label(code_line))
		code_line = code_line->next;
	return (code_line);
}

int	parser(t_data **data, t_code_line **code_line)
{
	int			current_byte;
	int			inst_token_position;
	t_code_line	*current_line;


	current_byte = 0;
	inst_token_position = 0;
	current_line = (*code_line);
	if (!(parse_label_declarations(*data, *code_line))) // need to check return, if label existe, will return -1, need to set up error here
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
	return (1);
}