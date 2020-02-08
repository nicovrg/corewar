/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   determine_token_type_and_length.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 18:14:15 by amamy             #+#    #+#             */
/*   Updated: 2020/02/08 22:18:24 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"
#include "ft_printf.h"

int (*g_token_type_determination_func_array[NB_TOKEN_TYPE])(t_token *) = {
	[TOKEN_TYPE_SEPARATOR] = is_separator,
	[TOKEN_TYPE_LABEL] = is_label,
	[TOKEN_TYPE_INSTRUCTION] = is_instructions,
	[TOKEN_TYPE_DIRECT] = is_direct,
	[TOKEN_TYPE_REGISTER] = is_register,
	[TOKEN_TYPE_INDIRECT] = is_indirect,
	[TOKEN_TYPE_DIRECT_LABEL_CALL] = is_direct_label_call,
	[TOKEN_TYPE_INDIRECT_LABEL_CALL] = is_indirect_label_call,
	[TOKEN_TYPE_UNKNOWN] = is_unknown,
};

/*
** ==================== determine_token_type_and_length ====================
** Receives a token, send it to bunch of identification function to 
** identify it.
*/

void		determine_token_type_and_length(t_token *token)
{
	t_token_type	current_token_type;

	token->type = TOKEN_TYPE_UNDEFINED;
	current_token_type = TOKEN_TYPE_SEPARATOR;
	while (token->type == TOKEN_TYPE_UNDEFINED)
	{
		g_token_type_determination_func_array[current_token_type](token);
		current_token_type++;
	}
}
