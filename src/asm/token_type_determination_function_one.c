/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_type_determination_function_one.c            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 05:57:28 by amamy             #+#    #+#             */
/*   Updated: 2020/02/06 02:37:42 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include "asm.h"
#include "libft.h"
#include "ft_printf.h"

int						get_token_length(int position, char *str)
{
	int i;

	i = position;
	ft_printf("get_token_length <sting :|%s|\n", str);
	while (str[i] && !is_comma(str[i]) && !is_whitespace(str[i]) && !is_comment(str[i]))
		i++;
	ft_printf("length ========================================> %d\n", i);
	return (i);
}

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
	int		length;
	char	*str;

	i = token->position;
	str = token->code_line->line;
	length = get_token_length(i, str);
	while (i < length && is_label_char(str[i]))
		i++;
	if (str[i] != ':')
		return (0);
	token->length = length;
	token->type = TOKEN_TYPE_LABEL;
	return (1);
}

int						is_label_call(t_token *token)
{
	int		index;
	int		saved_index;
	int		length;
	char	*str;

	index = token->position;
	str = token->code_line->line;
	length = get_token_length(index, str);
	if (str[index] && str[index + 1] && str[index] == '%' && str[index + 1] == ':')
	{
		index += 2;
		saved_index = index;
		while (str[index] && index < saved_index + length && is_label_char(str[index]))
			index++;
	}
	if (str[index])
		return (0);
	token->length = length;
	return (1);
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
