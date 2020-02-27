/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   label_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 23:58:28 by amamy             #+#    #+#             */
/*   Updated: 2020/02/27 15:38:19 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"
#include "tokens.h"
#include "ft_printf.h"

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
