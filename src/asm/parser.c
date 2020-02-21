/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 02:56:10 by amamy             #+#    #+#             */
/*   Updated: 2020/02/22 12:01:41 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"
#include "ft_printf.h"

int	parse_instruction(t_code_line *code_line,int current_token, int current_byte[1])
{
	ft_putendl("coucou");
	(void)code_line;
	(void)current_token;
	(void)current_byte;
	return (1);	
}

int	is_valid_instruction(t_code_line *code_line, int current_byte[1], int *contains_instruction)
{
	ft_putendl("coucou");
	(void)code_line;
	(void)current_byte;
	(void)contains_instruction;
	return (1);	
}

int	invalid_syntax(t_code_line *code_line, int contains_instruction)
{
	ft_putendl("coucou");
	(void)code_line;
	(void)contains_instruction;
	return (1);	
}

int		label_check(t_data *data, t_code_line *code_line)
{
	// if (is_label_only(code_line))
	// if (is_valid_label(code_line) && current_token < code_line->nb_token)
	// 	current_token++;
	(void)data;
	(void)code_line;
	return (1);
}

static int	parse_line(t_data *data, t_code_line *code_line, int current_byte[1])
{
	int			current_token;
	int			contains_instruction;;
	
	contains_instruction = 0;
	current_token = 0;
	ft_printf("=========\nLINE : |%s|\n", code_line->line);
	if(!label_check(data, code_line))
		return (0);
	if (is_valid_instruction(code_line, current_byte, &contains_instruction))
		parse_instruction(code_line, current_token, current_byte);
	else
		invalid_syntax(code_line, contains_instruction);
	ft_printf("=========\n\n");
	return (1);
}

int	parser(t_data **data, t_code_line **code_line)
{
	int			current_byte;
	t_code_line	*current_line;


	current_byte = 0;
	current_line = (*code_line);
	if (!(parse_labels_declaration(*data, *code_line)))
		return (0);
	while (current_line)
	{
		ft_putendl("coucou");
		parse_line(*data, current_line, &current_byte);
		if (current_line->errors)
			(*data)->errors = 1;
		if (current_line)
		current_line = current_line->next;
	}
	labels_calls_computing(*data, *code_line);
	return (1);
}