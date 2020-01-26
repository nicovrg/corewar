/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_tokeniser_states-function_two.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 05:57:28 by amamy             #+#    #+#             */
/*   Updated: 2020/01/26 06:36:24 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"
#include "ft_printf.h"
	
int						is_label_call(t_lexer *lex)
{
	(void)lex;
	ft_printf("%s\n", "label_call");

	return (0);
}

int						is_separator(t_lexer *lex)
{
	(void)lex;
	ft_printf("%s\n", "separator");

	return (0);
}

int						is_unknown(t_lexer *lex)
{
	(void)lex;
	ft_printf("%s\n", "unknown");

	return (0);
}

int						is_eol(t_lexer *lex)
{
	(void)lex;
	ft_printf("%s\n", "eol");

	return (0);
}