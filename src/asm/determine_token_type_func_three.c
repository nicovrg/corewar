/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   determine_token_type_func_three.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 05:57:28 by amamy             #+#    #+#             */
/*   Updated: 2020/02/06 00:38:59 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include "asm.h"
#include "libft.h"
#include "ft_printf.h"

int						is_instructions(t_token *token)
{
	char	*str;
	
	str = token->code_line->line;
	if (!ft_strcmp(str, "live") || !ft_strcmp(str, "ld"))
		return (1);
	else if (!ft_strcmp(str, "add") || !ft_strcmp(str, "sub"))
		return (1);
	else if (!ft_strcmp(str, "or") || !ft_strcmp(str, "xor"))
		return (1);
	else if (!ft_strcmp(str, "st") || ! ft_strcmp(str, "sti"))
		return (1);
	else if (!ft_strcmp(str, "zjmp") || !ft_strcmp(str, "aff"))
		return (1);
	else if (!ft_strcmp(str, "ldi") || !ft_strcmp(str, "and"))
		return (1);
	else if (!ft_strcmp(str, "fork") || !ft_strcmp(str, "lfork"))
		return (1);
	else if (!ft_strcmp(str, "lld") || !ft_strcmp(str, "lldi"))
		return (1);
	return (0);
}

int						is_indirect(t_token *token)
{
	char	*str;
	
	str = token->code_line->line;
	if (is_number(str))
		return (1);
	return (0);
}

int						is_separator(t_token *token)
{
	if (token->code_line->line[0] == ',')
	{
		token->type = TOKEN_TYPE_SEPARATOR;
		return (1);
	}
	return (0);
}

int						is_unknown(t_token *token)
{
	token->type = TOKEN_TYPE_UNKNOWN;
	return (1);
}
