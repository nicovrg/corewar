/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_tokeniser_states-function_one.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 05:57:28 by amamy             #+#    #+#             */
/*   Updated: 2020/01/27 05:27:25 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"
#include "ft_printf.h"

int						is_label(t_lexer *lex, t_data *data, int current_token)
{
	(void)lex;
	(void)data;
	(void)current_token;
	// ft_printf("%s\n", "label");
	// ft_printf("\nlexeme : %s\n\n", lex->token[current_token]->lexeme);
	return (0);
}

int						is_instructions(t_lexer *lex, t_data *data, int current_token)
{
	(void)lex;
	(void)data;
	(void)current_token;
	// ft_printf("%s\n", "instructions");
	return (0);
}

int						is_direct(t_lexer *lex, t_data *data, int current_token)
{
	(void)lex;
	(void)data;
	(void)current_token;
	// ft_printf("%s\n", "direct");
	return (0);
}

int						is_registr(t_lexer *lex, t_data *data, int current_token)
{
	(void)lex;
	(void)data;
	(void)current_token;
	// ft_printf("%s\n", "register");
	return (0);
}

int						is_indirect(t_lexer *lex, t_data *data, int current_token)
{
	(void)lex;
	(void)data;
	(void)current_token;
	// ft_printf("%s\n", "indirect");
	return (0);
}
