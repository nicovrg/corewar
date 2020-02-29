/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   label_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takoumys <takoumys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 23:58:28 by amamy             #+#    #+#             */
/*   Updated: 2020/02/29 13:20:36 by takoumys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"
#include "tokens.h"
#include "ft_printf.h"

int	check_label_call_type(t_token *label_call, int is_this_type)
{
	if (label_call->type == TOKEN_TYPE_LABEL_CALL)
		if (label_call && label_call->values && label_call->values->label_call)
		{
			if (label_call->values->label_call->type == is_this_type)
				return (1);
		}
	return (0);
}

int		is_only_label(t_code_line *code_line)
{
	if (!code_line)
		return (0);
	if (code_line->token && code_line->token->type == TOKEN_TYPE_LABEL \
	&& code_line->nb_token == 1)
		return (1);
	return (0);
}
int		is_label_declaration(t_code_line *code_line)
{
	if (!code_line->next)
		return (0);
	if (code_line->token->type == TOKEN_TYPE_LABEL)
		return (1);
	return (0);
}

void	labels_calls_computing(t_data *data, t_code_line *code_line)
{
	(void)data;
	(void)code_line;
}
