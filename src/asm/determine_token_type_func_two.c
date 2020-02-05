/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   determine_token_type_func_two.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasv <nicolasv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 05:57:28 by amamy             #+#    #+#             */
/*   Updated: 2020/02/05 05:30:45 by nicolasv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include "asm.h"
#include "libft.h"
#include "ft_printf.h"

int						is_label(t_token *token)
{
	int		i;
	char	*str;

	i = 0;
	str = token->code_line->line;
	while (str[i])
	{
		if (str[i] == LABEL_CHAR && !str[i + 1])
			return (1);
		if (str[i] != LABEL_CHARS)
			return (0);
		i++;
	}
	return (0);
}

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
	else if (!ft_strcmp(str, "zjmp") || !ft_strcmp(str, "aff"))
		return (1);
	else if (!ft_strcmp(str, "ldi") || !ft_strcmp(str, "and"))
		return (1);
	else if (!ft_strcmp(str, "fork") || !ft_strcmp(str, "lfork"))
		return (1);
	else if (!ft_strcmp(str, "lld") || !ft_strcmp(str, "lldi"))
		return (1);
	return (0);
}

int						is_direct(t_token *token)
{
	char	*str;
	
	str = token->code_line->line;
	if (str[0] == '%')
		if (is_digit(str + 1))
			return (1);
	return (0);
}

int						is_register(t_token *token)
{
	char	*str;
	
	str = token->code_line->line;
	if (str[0] == 'r')
		if (is_digit(str + 1))
			return (1);
	return (0);
}

int						is_indirect(t_token *token)
{
	char	*str;
	
	str = token->code_line->line;
	if (is_digit(str))
		return (1);
	return (0);
}
