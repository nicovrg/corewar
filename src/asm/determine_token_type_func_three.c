/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   determine_token_type_func_three.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasv <nicolasv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 05:57:28 by amamy             #+#    #+#             */
/*   Updated: 2020/02/05 05:34:54 by nicolasv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include "asm.h"
#include "libft.h"
#include "ft_printf.h"
	
int						is_separator(t_token *token)
{
	if (token->code_line->line[0] == ',')
	{
		token->type = TOKEN_TYPE_SEPARATOR;
		return (1);
	}
	return (0);
}

int						is_label_call(t_token *token)
{
	int		i;
	char	*str;

	i = 0;
	str = token->code_line->line;
	if (str[0] && str[1] && str[0] == '%' && str[1] == ':')
	{
		i = 2;
		while (str[i])
		{
			if (str[i] != LABEL_CHARS)
				return (0);
			i++;
		}
	}
	return (1);
}


int						is_unknown(t_token *token)
{
	token->type = TOKEN_TYPE_UNKNOWN;
	return (1);
}
