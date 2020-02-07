/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_type_determination_function_one.c            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 05:57:28 by amamy             #+#    #+#             */
/*   Updated: 2020/02/08 00:27:38 by amamy            ###   ########.fr       */
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

	// ft_printf("%s\n", "LA");
	i = token->position;
	str = token->code_line->line;
	while (is_label_char(str[i]))
		i++;
	if (str[i] != ':')
		return (0);
	token->length = (i + 1) - token->position;
	token->type = TOKEN_TYPE_LABEL;
	return (1);
}

int						is_label_call(t_token *token)
{
	int		index;
	int		saved_index;
	char	*str;

	index = token->position;
	str = token->code_line->line;
	if (str[index] && str[index + 1] && str[index] == '%' && str[index + 1] == ':')
	{
		index += 2;
		if (!is_label_char(str[index]))
			return (0);
		saved_index = index;
		while (str[index] && is_label_char(str[index]))
			index++;
		token->length = index - token->position;
		token->type = TOKEN_TYPE_LABEL_CALL;
		return (1);
	}
	return (0);
}

int						is_direct(t_token *token)
{
	int		i;
	char	*str;
	
	i = token->position;
	str = token->code_line->line;
	if (str[i] && str[i] == '%' && i++)
	{
		if  ((ft_isdigit(str[i]) || str[i] == '+' || str[i] == '-') && i++)
		{
			while(str[i] && ft_isdigit(str[i]))
				i++;
			token->length = i - token->position;
			token->type = TOKEN_TYPE_DIRECT;
			return (1);
			
		}
		// i += 2;
	}
	return (0);
}

int						is_register(t_token *token)
{
	int		i;
	char	*str;
	
	i = token->position;
	str = token->code_line->line;
	if (str[i] == 'r' && i++)
	{
		while(str[i] && ft_isdigit(str[i]))
			i++;
		token->length = i - token->position;
		token->type = TOKEN_TYPE_REGISTER;
		return (1);
	}
	return (0);
}
