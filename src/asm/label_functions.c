/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   label_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 23:58:28 by amamy             #+#    #+#             */
/*   Updated: 2020/02/21 04:47:27 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"
#include "ft_printf.h"

int		is_label_only(t_code_line *code_line)
{
	ft_printf("code_line->nb_token : %d\n", code_line->nb_token);
	if (code_line->token->type == TOKEN_TYPE_LABEL \
	&& code_line->nb_token == 1)
	{
		ft_printf("%s\n", "is_label_only");
		return (1);
	}
	return (0);
}

int		is_valid_label(t_code_line *code_line)
{
	t_token *token;

	token = code_line->token;
	if (token->type == TOKEN_TYPE_LABEL)
		return (1);
	return 0;	
}

int		parse_labels_declaration(t_data *data, t_code_line *code_line)
{
	(void)data;
	(void)code_line;
	return (1);
}

void	labels_calls_computing(t_data *data, t_code_line *code_line)
{
	(void)data;
	(void)code_line;
}