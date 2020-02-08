/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_type_determination_function_three.c          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 04:21:46 by amamy             #+#    #+#             */
/*   Updated: 2020/02/08 04:54:56 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include "asm.h"
#include "tokens.h"
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

	i = token->position;
	str = token->code_line->line;
	if (!is_label_char(str[i]))
		return (0);
	while (is_label_char(str[i]))
		i++;
	if (str[i] != ':')
		return (0);
	token->length = (i + 1) - token->position;
	token->type = TOKEN_TYPE_LABEL;
	return (1);
}

static int				is_valid_label_call(t_token *token, int index, char *str)
{
		if (!is_label_char(str[index]))
			return (0);
		while (str[index] && is_label_char(str[index]))
			index++;
		token->length = index - token->position;
		return (1);
}


int						is_label_call(t_token *token)
{
	int		index;
	char	*str;

	index = token->position;
	str = token->code_line->line;
	if (str[index] && str[index + 1] && str[index] == '%' && str[index + 1] == ':')
	{
		index += 2;
		if (is_valid_label_call(token, index, str))
		{
			token->type = TOKEN_TYPE_DIRECT_LABEL_CALL;
			return (1);
		}
	}
	else if (str[index] && str[index] == ':')
	{
		index++;
		if (is_valid_label_call(token, index, str))
		{
			token->type = TOKEN_TYPE_INDIRECT_LABEL_CALL;
			return (1);
		}
	}
	return (0);
}

// int						is_label_call(t_token *token)
// {
// 	int		index;
// 	int		saved_index;
// 	char	*str;

// 	index = token->position;
// 	str = token->code_line->line;
// 	if (str[index] && str[index + 1] && str[index] == '%' && str[index + 1] == ':')
// 	{
// 		index += 2;
// 		if (!is_label_char(str[index]))
// 			return (0);
// 		saved_index = index;
// 		while (str[index] && is_label_char(str[index]))
// 			index++;
// 		token->length = index - token->position;
// 		token->type = TOKEN_TYPE_LABEL_CALL;
// 		return (1);
// 	}
// 	return (0);
// }
