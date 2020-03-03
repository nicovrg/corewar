/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 02:56:10 by amamy             #+#    #+#             */
/*   Updated: 2020/03/03 22:52:08 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"
#include "tokens.h"
#include "ft_printf.h"

int	invalid_syntax(t_data *data, t_code_line *code_line)
{
	ft_putendl("INVALID_SYNTAX");
	(void)code_line;
	(void)data;
	return (1);	
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
		return (error_code_line(code_line, MEMORY_ALLOCATION_ERROR, 0));
	update_instruction_size_and_address(data, code_line, current_byte);
	if (!code_line->errors)
	{
		if (!parse_instruction(data, code_line, inst_position))
			return (error_code_line(code_line, MEMORY_ALLOCATION_ERROR, 0));
	}	
	else
		invalid_syntax(data, code_line);
	*current_byte = *current_byte +code_line->instruction_size;
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
		if (current_line->errors)
			(*data)->errors = 1;
		if (current_line)
		current_line = current_line->next;
	}
	labels_calls_computing(*data, *code_line);
	return (1);
}