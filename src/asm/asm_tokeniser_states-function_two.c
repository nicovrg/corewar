/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_tokeniser_states-function_two.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 05:57:28 by amamy             #+#    #+#             */
/*   Updated: 2020/01/27 05:02:06 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"
#include "ft_printf.h"
	
int						is_label_call(t_lexer *lex, t_data *data, int current_token)
{
	(void)lex;
	(void)data;
	(void)current_token;
	// ft_printf("%s\n", "label_call");

	return (0);
}

int						is_separator(t_lexer *lex, t_data *data, int current_token)
{
	(void)lex;
	(void)data;
	(void)current_token;
	// ft_printf("%s\n", "separator");

	return (0);
}

int						is_unknown(t_lexer *lex, t_data *data, int current_token)
{
	(void)lex;
	(void)data;
	(void)current_token;
	// ft_printf("%s\n", "unknown");

	return (1);
}
