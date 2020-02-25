/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_free_token_values.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 09:09:43 by amamy             #+#    #+#             */
/*   Updated: 2020/02/25 19:45:08 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "tokens.h"
#include "libft.h"
#include "ft_printf.h"

static void	free_label(t_token *token)
{
	if (token->values)
		ft_memdel((void*)&token->values->label->lexeme);
	ft_memdel((void*)&token->values->label);
	(void)token;
}

static void	free_instruction(t_token *token)
{
	int i;

	i = 0;
	if (token->values)
	{
		ft_memdel((void*)&token->values->instruction->lexeme);
		while (i < 3)
			ft_memdel((void*)&token->values->instruction->parameter[i++]);
	}
	ft_memdel((void*)&token->values->instruction);
	(void)token;
}



static void	free_label_call(t_token *token)
{
	if (token->values)
		ft_memdel((void*)&token->values->label_call->lexeme);
	ft_memdel((void*)&token->values->label_call);
}

static void	free_unknown(t_token *token)
{
	if (token->values)
		ft_memdel((void*)&token->values->unknown->lexeme);
	ft_memdel((void*)&token->values->unknown);
}

void 		(*g_token_free_values_func_array[NB_TOKEN_TYPE])(t_token *) = {
	[TOKEN_TYPE_LABEL] = free_label,
	[TOKEN_TYPE_INSTRUCTION] = free_instruction,
	[TOKEN_TYPE_LABEL_CALL] = free_label_call,
	[TOKEN_TYPE_UNKNOWN] = free_unknown,
};