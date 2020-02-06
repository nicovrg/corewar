/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   determine_token_type_func_two.c                    :+:      :+:    :+:   */
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


static int				is_label_char(char c)
{
	int	i;
	int	label_char_nb;

	i = 0;
	label_char_nb = 37;
	while (i < label_char_nb)
	{
		if (c == LABEL_CHARS[i])
			return (1);
		i++;
	}
	return (0);
}

int						is_label(t_token *token)
{
	int		i;
	char	*str;

	i = 0;
	str = token->code_line->line;
	ft_printf("is_label : str %s\n", str);
	while (str[i] && is_label_char(str[i]))
		i++;
	if (str[i])
		return (0);
	else
		return (ft_strlen(str));
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
		while (str[i] && is_label_char(str[i]))
			i++;
	}
	return (str[i] ? 0 : 1);
}

int						is_direct(t_token *token)
{
	char	*str;
	
	str = token->code_line->line;
	if (str[0] == '%')
		if (is_number(str + 1))
			return (1);
	return (0);
}

int						is_register(t_token *token)
{
	char	*str;
	
	str = token->code_line->line;
	if (str[0] == 'r')
		if (is_number(str + 1))
			return (1);
	return (0);
}
