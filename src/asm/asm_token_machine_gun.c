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
** ==================== token_gun ====================
** Token_finder uses the input function to try to recognize
** a token.
*/

static int	(*token_gun[LEX_STATES_NB])(t_token **, char *);

/*
** ==================== stuff_token_guns ====================
** This function fills the *func() with all the functions to
** recognize tokens.
*/

void	stuff_token_guns()
{
	token_gun[0] = is_separator;
	token_gun[1] = is_label;
	token_gun[2] = is_instructions;
	token_gun[3] = is_direct;
	token_gun[4] = is_registr;
	token_gun[5] = is_indirect;
	token_gun[6] = is_label_call;
	token_gun[7] = is_unknown;
}

	/*
	** ==================== token_machine_gun ====================
	** Uses the t_token ** in t_code_line, takes lexeme(strings)
	** and identifies it as token_type from redcode grammar
	** or unknown.
	** If unknown, raises a lexical error (in data->error).
	** Returns (0) in case somethin unexpected happened.
	*/


// new tokenizer for lexeme
int		token_machine_gun(t_token **token, char *src)
{
	int		is_token_found;
	enum	token search_token;
		
	is_token_found = 0;
	search_token = label;
	while (search_token <= unknown && !is_token_found)
		is_token_found = token_gun[search_token++] (token, src);
	// if (!check_integrity)
	// 	return (0);
	return (1);	 //	maybe we can think qbout returning 0 if unknown token detected, 
				//	and if unknow token returned once, error_mode activated
}


//==============olds tokenizer for string ============
// int		tokenizer(t_code_line *lex, t_data *data)
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