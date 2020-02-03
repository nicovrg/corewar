/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_determine_token_type.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 04:13:33 by nivergne          #+#    #+#             */
/*   Updated: 2020/02/02 04:59:11 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"
#include "ft_printf.h"

static int (*g_token_type_determination_func_array[NB_TOKEN_TYPE])(t_token *) = {
	[TOKEN_TYPE_SEPARATOR] = is_separator,
	[TOKEN_TYPE_LABEL] = is_label,
	[TOKEN_TYPE_INSTRUCTION] = is_instructions,
	[TOKEN_TYPE_DIRECT] = is_direct,
	[TOKEN_TYPE_REGISTER] = is_register,
	[TOKEN_TYPE_INDIRECT] = is_indirect,
	[TOKEN_TYPE_LABEL_CALL] = is_label_call,
	[TOKEN_TYPE_UNKNOWN] = is_unknown,
};

void		determine_token_type_and_length(t_token *token)
{
	t_token_type	current_token_type;
		
	token->type = TOKEN_TYPE_UNDEFINED;
	current_token_type = TOKEN_TYPE_SEPARATOR;
	while (token->type == TOKEN_TYPE_UNDEFINED)
	{
		token->length = g_token_type_determination_func_array[current_token_type](token);
		current_token_type++;
	}
}
