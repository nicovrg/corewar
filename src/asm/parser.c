/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takoumys <takoumys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 02:56:10 by amamy             #+#    #+#             */
/*   Updated: 2020/03/01 02:26:08 by takoumys         ###   ########.fr       */
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
	{
		ft_printf("%s\n", "ENCODING");
		code_line->instruction_size = (code_line->instruction_size + 2);
	}
	else
	{
		ft_printf("%s\n", "PAS ENCODING");
		code_line->instruction_size++;
	}
	code_line->mem_address = current_byte[0];
}

static int	parse_line(t_data *data, t_code_line *code_line, int inst_position, int current_byte[1])
{
	ft_printf("=========\nLINE : |%s|\n", code_line->line);
	check_instruction_validity(data, code_line, inst_position);
	update_instruction_size_and_address(data, code_line, current_byte);
	if (!code_line->errors)
		parse_instruction(data, code_line, inst_position);
	else
		invalid_syntax(data, code_line);
	ft_printf("instruction size : |%d|\n", code_line->instruction_size);
	*current_byte = *current_byte +code_line->instruction_size;
	ft_printf("address : |%d|\n", code_line->mem_address);
	ft_printf("=========\n\n");
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
			return (-1);
		if (current_line->errors)
			(*data)->errors = 1;
		if (current_line)
		current_line = current_line->next;
	}
	labels_calls_computing(*data, *code_line);
	return (1);
}