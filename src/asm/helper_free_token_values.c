/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_free_token_values.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 09:09:43 by amamy             #+#    #+#             */
/*   Updated: 2020/03/01 18:50:03 by amamy            ###   ########.fr       */
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
	if (token->values)
	ft_memdel((void*)&token->values->instruction->lexeme);
	ft_memdel((void*)&token->values->instruction);
	(void)token;
}

static void	free_parameter(t_token *param)
{
	if (param->type == TOKEN_TYPE_DIRECT)
		ft_memdel((void*)&param->values->direct);
	if (param->type == TOKEN_TYPE_INDIRECT)
		ft_memdel((void*)&param->values->indirect);
	if (param->type == TOKEN_TYPE_REGISTER)
		ft_memdel((void*)&param->values->registr);

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
	[TOKEN_TYPE_DIRECT] = free_parameter,
	[TOKEN_TYPE_REGISTER] = free_parameter,
	[TOKEN_TYPE_INDIRECT] = free_parameter,
	[TOKEN_TYPE_LABEL_CALL] = free_label_call,
	[TOKEN_TYPE_UNKNOWN] = free_unknown,
};