/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_tokeniser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasv <nicolasv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 04:28:29 by nivergne          #+#    #+#             */
/*   Updated: 2020/01/25 03:16:35 by nicolasv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"
#include "ft_printf.h"

/*
** ==================== new_token_node ====================
** if it s the first token, instanciate the list
** else go at the end of the list and add a new node
*/

//int		new_token_node(t_token **token)
//{
//	t_token		*new;
//	t_token		*tmp_token;
//	tmp_token = (*token);
//	while (tmp_token && tmp_token->next)
//		tmp_token = tmp_token->next;
//	if (!(new = (t_token *)ft_memalloc(sizeof(t_token))))
//		return (0);
//	if ((*token))
//		tmp_token->next = new;
//	else
//		(*token) = new;
//	return (1);
//}
/*
** ==================== create_tokens ====================
** 
*/

int			create_tokens(char *line, t_token **token)
{
	(void)token;
	(void)line;
	ft_putendl(line);
	return (1);
}

/*
** ==================== token_finder ====================
** Token_finder uses the input function to try to recognize
** a token.
*/

static int	(*token_finder[LEX_STATES_NB])(t_lexer *, char *src);

/*
** ==================== fill_token_finder ====================
** This function fills the *func() with all the functions to
** recognize tokens.
*/

static void	fill_token_finder()
{
	token_finder[0] = is_separator;
	token_finder[1] = is_label;
	token_finder[2] = is_instructions;
	token_finder[3] = is_direct;
	token_finder[4] = is_registr;
	token_finder[5] = is_indirect;
	token_finder[6] = is_label_call;
	token_finder[7] = is_unknown;
}

	/*
	** ==================== tokenizer ====================
	** Uses the t_token ** in t_lexer, takes lexeme(strings)
	** and identifies it as token_type from redcode grammar
	** or unknown.
	** If unknown, raises a lexical error (in data->error).
	** Returns (0) in case somethin unexpected happened.
	*/


// new tokenizer for lexeme
int		tokenizer(t_lexer *lex, char *src)
{
	int		is_token_found;
	enum	token search_token;
	
	is_token_found = 0;
	search_token = label;
	(void)src;
	fill_token_finder(); // don't do this in this function, call it before calling it in loop
	while (search_token <= unknown && !is_token_found)
		is_token_found = token_finder[search_token++] (lex, src);
	// if (!check_integrity)
	// 	return (0);
	return (1);	 //	maybe we can think qbout returning 0 if unknown token detected, 
				//	and if unknow token returned once, error_mode activated
}


//==============olds tokenizer for string ============
// int		tokenizer(t_lexer *lex, t_data *data)
// {
// 	int		current_token;
// 	int		lexical_error;
// 	int		is_token_found;
// 	enum	token search_token;
	
// 	lexical_error = 0;;
// 	current_token = 0;
// 	is_token_found = 0;
// 	search_token = label;
// 	fill_token_finder();
// 	while (current_token < lex->nb_token)
// 	{
// 		while (search_token <= unknown && !is_token_found)
// 			is_token_found = token_finder[search_token++] (lex, data, current_token);
// 		search_token = label;
// 		is_token_found = 0;
// 		current_token++;
// 	}
// 	// if (!check_integrity)
// 	// 	return (0);
// 	return (1);	 //	maybe we can think qbout returning 0 if unknown token detected, 
// 				//	and if unknow token returned once, error_mode activated
// }