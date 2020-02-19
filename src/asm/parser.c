/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 02:56:10 by amamy             #+#    #+#             */
/*   Updated: 2020/02/19 04:24:31 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"
#include "ft_printf.h"


int	parse_label(t_code_line *code_line, int current_byte[1])
{
	t_token *token;

	token = code_line->token;
	if (token->type == TOKEN_TYPE_LABEL)
		code_line->label = ft_strndup(&(code_line->line[token->position]), token->length - 1);
	ft_printf("laebel |%s|\n", code_line->label);
	(void)current_byte;
	return (1);	
}

int	parse_instruction(t_code_line *code_line, int current_byte[1])
{
	ft_putendl("coucou");
	(void)code_line;
	(void)current_byte;
	return (1);	
}

int	wrong_first_token(t_code_line *code_line, int current_byte[1])
{
	ft_putendl("coucou");
	(void)code_line;
	(void)current_byte;
	return (1);	
}

static int	parse_line(t_code_line *code_line, int current_byte[1])
{
	ft_printf("=========\nLINE : |%s|\n", code_line->line);
	if (code_line->token->type == TOKEN_TYPE_LABEL \
	|| code_line->token->type == TOKEN_TYPE_INSTRUCTION)
	{
		parse_label(code_line, current_byte);
		if(!parse_instruction(code_line, current_byte))
			return (0);
	}
	else
	{
		ft_printf("%s\n", "Wrong_first");
		code_line->errors = 1;
		wrong_first_token(code_line, current_byte);
		return (0);
	}
	ft_printf("=========\n\n");
	return (1);
}

int	parser(t_data **data, t_code_line **code_line)
{
	int			current_byte[1];
	t_code_line	*current_line;

	*current_byte = 0;
	current_line = *code_line;
	while (current_line->next)
	{
		parse_line(current_line, current_byte);
		if (current_line->errors)
			(*data)->errors = 1;
		current_line = current_line->next;
	}
	return (1);
}