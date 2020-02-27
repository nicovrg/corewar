/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 02:56:10 by amamy             #+#    #+#             */
/*   Updated: 2020/02/27 17:09:13 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"
#include "ft_printf.h"

int	parse_instruction(t_code_line *code_line,int current_token, int current_byte)
{
	ft_putendl("coucou");
	(void)code_line;
	(void)current_token;
	(void)current_byte;
	return (1);	
}

int	get_op_code(t_data *data, t_token *op)
{
	int	i;
	char	*line;

	i = 1;
	line = op->code_line->line;
	while (ft_strncmp(data->op_tab[i].name , &line[op->position], op->length))
		i++;
	return (i);
}

static int	is_param_type_accepted(t_data *data, t_token *param, int param_nb)
{
	int	param_allowed;

	param_allowed = (ft_itoa(data->op_tab[param->code_line->op_code].param_types)[param_nb] - '0');
	if (param->type == TOKEN_TYPE_REGISTER)
	{
		if (param_allowed != 1 && param_allowed != 3 && param_allowed != 5 && param_allowed != 7)
			return (0);
	}
	else if (param->type == TOKEN_TYPE_INDIRECT)
	{
		if (param_allowed != 2 && param_allowed != 3 && param_allowed != 6 && param_allowed != 7)
			return (0);
	}
	else if (param->type == TOKEN_TYPE_DIRECT)
	{
		if (param_allowed < 4)
			return (0);
	}
	return (1);
}

/*
** ==================== is_valid_instruction ====================
** Save the op code of the instruction in the code_line and check
** taht we have an op code and that the params sent to it are
** compatible with this instruction.
*/

int	is_valid_instruction(t_data *data, t_code_line *code_line, int current_byte)
{
	int	i;
	int	valid_params;
	int	instruction_index;

	i = 0;
	valid_params = 0;
	instruction_index = current_byte;
	if (code_line->tokens[instruction_index]->type !=  TOKEN_TYPE_INSTRUCTION)
		return (-1);
	i = 1;
	code_line->op_code = get_op_code(data, code_line->tokens[instruction_index]);
	while (valid_params < data->op_tab[code_line->op_code].param_nb)	
	{
		if (!is_param_type_accepted(data, code_line->tokens[instruction_index + i], valid_params))
			return (0);
		valid_params++;
		if (valid_params < data->op_tab[code_line->op_code].param_nb \
		&& (!is_separator(code_line->tokens[instruction_index + i + 1])))
			return (0);
		i = i + 2;
	}
	return (1);	
}

int	invalid_syntax(t_code_line *code_line)
{
	ft_putendl("INVALID_SYNTAX");
	(void)code_line;
	return (1);	
}


static int	parse_line(t_data *data, t_code_line *code_line, int current_byte)
{
	int			current_token;
	
	current_token = 0;
	ft_printf("=========\nLINE : |%s|\n", code_line->line);
	if (is_valid_instruction(data, code_line, current_byte))
		parse_instruction(code_line, current_token, current_byte);
	else
		invalid_syntax(code_line);
	ft_printf("=========\n\n");
	(void)data;
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
	t_code_line	*current_line;


	current_byte = 0;
	current_line = (*code_line);
	if (!(parse_label_declarations(*data, *code_line))) // need to check return, if label existe, will return -1, need to set up error here
		return (0);
	while ((current_line = skip_label_only_lines(current_line)))
	{
		if (current_line->token->type == TOKEN_TYPE_LABEL)
			current_byte = 1;
		else
			current_byte = 0;
		if (!(parse_line(*data, current_line, current_byte)))
			return (-1);
		if (current_line->errors)
			(*data)->errors = 1;
		if (current_line)
		current_line = current_line->next;
	}
	labels_calls_computing(*data, *code_line);
	return (1);
}