/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_type_determination_function_two.c            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 05:57:28 by amamy             #+#    #+#             */
/*   Updated: 2020/02/07 00:18:38 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include "asm.h"
#include "libft.h"
#include "ft_printf.h"

int						is_instructions(t_token *token)
{
	char	*str;
	int 	position;
	
	position = token->position;
	str = token->code_line->line;
		if (!ft_strncmp(&str[position], "lfork", 5))
		token->length = 5;
	else if (!ft_strncmp(&str[position], "live", 4) || !ft_strncmp(&str[position], "zjmp", 4) \
		|| (!ft_strncmp(&str[position], "fork", 4)) || !ft_strncmp(&str[position], "lldi", 4))
		token->length = 4;
	else if (!ft_strncmp(&str[position], "lld", 3) || !ft_strncmp(&str[position], "add", 3) \
		|| !ft_strncmp(&str[position], "sub", 3) || !ft_strncmp(&str[position], "aff", 3) \
		|| !ft_strncmp(&str[position], "xor", 3) || !ft_strncmp(&str[position], "sti", 3) \
		|| !ft_strncmp(&str[position], "ldi", 3) || !ft_strncmp(&str[position], "and", 3))
		token->length = 3;
	else if (!ft_strncmp(&str[position], "ld", 2) || !ft_strncmp(&str[position], "or", 2) \
		|| (!ft_strncmp(&str[position], "st", 2)))
		token->length = 2;
	if 	(token->length)
	{
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

int						is_unknown(t_token *token)
{
	ft_printf("THIS IS UNKONW TOKEN : |%s|\n", &token->code_line->line[token->position]);
	token->length = 1;
	token->type = TOKEN_TYPE_UNKNOWN;
	return (1);
}
