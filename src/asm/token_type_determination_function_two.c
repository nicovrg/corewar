/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_type_determination_function_two.c            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 05:57:28 by amamy             #+#    #+#             */
/*   Updated: 2020/02/08 00:39:27 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include "asm.h"
#include "tokens.h"
#include "libft.h"
#include "ft_printf.h"

int						is_instructions(t_token *token)
{
	int		length;
	int 	position;
	char	*str;
	
	length = 0;
	position = token->position;
	str = token->code_line->line;
		if (!ft_strncmp(&str[position], "lfork", 5))
		length = 5;
	else if (!ft_strncmp(&str[position], "live", 4) || !ft_strncmp(&str[position], "zjmp", 4) \
		|| (!ft_strncmp(&str[position], "fork", 4)) || !ft_strncmp(&str[position], "lldi", 4))
		length = 4;
	else if (!ft_strncmp(&str[position], "lld", 3) || !ft_strncmp(&str[position], "add", 3) \
		|| !ft_strncmp(&str[position], "sub", 3) || !ft_strncmp(&str[position], "aff", 3) \
		|| !ft_strncmp(&str[position], "xor", 3) || !ft_strncmp(&str[position], "sti", 3) \
		|| !ft_strncmp(&str[position], "ldi", 3) || !ft_strncmp(&str[position], "and", 3))
		length = 3;
	else if (!ft_strncmp(&str[position], "ld", 2) || !ft_strncmp(&str[position], "or", 2) \
		|| (!ft_strncmp(&str[position], "st", 2)))
		length = 2;
	if 	(length != 0)
	{
		token->length = length;
		token->type = TOKEN_TYPE_INSTRUCTION;
		return (1);
	}
	return (0);
}

int						is_indirect(t_token *token)
{
	int		i;
	char	*str;
	
	i = token->position;
	str = token->code_line->line;
	if (ft_isdigit(str[i]) && i++)
	{
		while(str[i] && ft_isdigit(str[i]))
			i++;
		token->length = i - token->position;
		token->type = TOKEN_TYPE_INDIRECT;
		return (1);
	}
	return (0);
}

int						is_separator(t_token *token)
{
	if (token->code_line->line[token->position] == ',')
	{
		token->length = 1;
		token->type = TOKEN_TYPE_SEPARATOR;
		return (1);
	}
	return (0);
}

static void				detect_unknown_length(t_token *token)
{
	t_token_type	current_token_type;
	
	token->type = TOKEN_TYPE_UNDEFINED;
	current_token_type = TOKEN_TYPE_SEPARATOR;
	while (current_token_type < TOKEN_TYPE_UNKNOWN && token->type == TOKEN_TYPE_UNDEFINED)
	{
		g_token_type_determination_func_array[current_token_type](token);
		current_token_type++;
	}
}


int						is_unknown(t_token *token)
{
	int			i;
	int			length;
	char		*str;
	t_token		tmp;

	length = 0;
	i = token->position;
	str = token->code_line->line;
	tmp.code_line = token->code_line;
	tmp.type = TOKEN_TYPE_UNDEFINED;
	while (tmp.type == TOKEN_TYPE_UNDEFINED \
		&& (str[i] && (!is_comment_char(str[i]) && !is_whitespace(str[i++]))))
	{
		tmp.position = i;
		detect_unknown_length(&tmp);
		length++;
	}
	token->type = TOKEN_TYPE_UNKNOWN;
	token->length = length;
	token->code_line->errors = LINE_ERROR_LEXICAL;
	return (1);
}
