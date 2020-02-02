/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_tokeniser_states-function_two.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 05:57:28 by amamy             #+#    #+#             */
/*   Updated: 2020/02/02 05:53:31 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"
#include "ft_printf.h"
	
int						is_separator(t_token *token)
{
	// ft_printf("%s\n", "is_separator");
	if (token->code_line->line[0] == ',')
	{
		token->type = TOKEN_TYPE_SEPARATOR;
		return (1);
	}
	return (0);
}

int						is_label_call(t_token *token)
{
	(void)token;
	// ft_printf("%s\n", "is_label_call");

	return (0);
}


int						is_unknown(t_token *token)
{
	token->type = TOKEN_TYPE_UNKNOWN;
	// ft_printf("%s\n", "is_unknown");

	return (0);
}
