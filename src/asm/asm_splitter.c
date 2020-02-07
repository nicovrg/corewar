/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_splitter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 04:42:59 by nivergne          #+#    #+#             */
/*   Updated: 2020/02/06 23:09:34 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"
#include "ft_printf.h"

/*
** ==================== count_tokens ====================
** This function count the number of token in one line
** If there are multiples commas following each others, return an error
*/

static int			count_tokens(char *line)
{
	int i;
	int j;
	int ret;

	i = 0;
	ret = 0;
	if (ft_strnstr(line, ",,", ft_strlen(line)))
		return (error_msg("invalid line, multiples commas in a row", -1));
	while (line[i])
	{
		j = 0;
		while (line[i] && is_whitespace(line[i]))
			i++;
		while (line[i + j] && (!is_whitespace(line[i + j]) && !is_comma(line[i + j])))
		{
			if (is_comment_char(line[i + j]))
				return (ret);
			j++;
		}
		(line[i + j - 1] > 0 && is_comma(line[i + j - 1])) ? (j++) : (0);
		(line[i + j - 1] > 0 && is_comma(line[i + j - 1])) ? (ret++) : (0);
		(j == 0) ? (i++) : (i = i + j);
		ret++;
	}
	return (ret);
}

/*
** ==================== allocate_token ====================
** This function count the number of token, then allocate a table
** of pointers on structure s_token, then allocate each cell
** of this table.
*/

// static int			allocate_token(t_lexer **tmp_lex, char *line)
// {
//     int	i;
// 	int nb_token;

//     i = 0;
// 	nb_token = count_tokens(line);
// 	if (!((*tmp_lex)->token = ft_memalloc((sizeof(t_token) * nb_token) + 1)))
//         return (0);
//     while (i < nb_token)
//     {
//         if (!((*tmp_lex)->token[i] = ft_memalloc(sizeof(t_token))))
//             return (0);
//         i++;
//     }
// 	(*tmp_lex)->nb_token = nb_token;
//     return (1);
// }

/*
** ==================== add_token ====================
** This function set the lexeme value of a token
*/

int					add_token(t_lexer **tmp_lex, char *line, int i, int j)
{
	// ft_printf("sssssss = %c\n", line[i + j - 1]);
	// ft_printf("sssssss = %s\n", line);
	if (!((*tmp_lex)->token[1]->lexeme = ft_strndup(line + i, j)))
		return (error_msg("fail alloc token->lexeme with strndup", 0));
	if (!(line[i + j - 1] == ','))
	{
		if (!((*tmp_lex)->token[1]->lexeme = ft_strndup(",", 1)))
			return (error_msg("fail alloc token->lexeme with strndup", 0));
	}
	return (1);
}

// check if line is not empty or invalid
// skip all whitespaces
// if whitespace convert white separtor
// if coma convert coma separtor
// repeat

/*
** ==================== is_empty ====================
** check if the line is empty or if it contain a token
** even if this token is invalid
** at this point, anything could be considered a token
*/

static int			is_empty(char *line)
{
	int i;

	i = 0;
	while (is_whitespace(line[i]))
		i++;
	if (!line[i])
		return (1);
	return (0);
}

/*
** ==================== splitter ====================
** This function takes a lexer node and a line, split the line
** around spaces and commas, and the following instructions are under modification
*/

int					splitter(t_lexer **tmp_lex, char *line)
{
	int i;
	int j;
	int position;

	i = 0;
	while (line[i] && is_whitespace(line[i]))
		i++;
	while (line[i] && !is_comment_char(line[i]))
	{
		j = 0;

		// allocate a token node and increment position
		// while (is_token[i++])
		// lexme_type(line + i, j, position, tmp_lex)

		// if !is_comma() 
		// nouveau token => checker => allouer => arreij => tokenzier
		while (line[i] && is_whitespace(line[i]))
			i++;

		// if (line[i] == ',')
			// if (!allocate_token(tmp_lex, line))
				// return (0);
		// }
			//add separator coma
		// while (!is_whitespace(line[i + j]) && line[i + j] != ',')
		// {
			// if (line[i + j] == '#')
				// return (1);
			// if (line[i + j] == ',')
				// do something
			// j++;
		// }
		i++;
	}
	return (1);
}

while (j > 0)
	

// int					splitter(t_lexer **tmp_lex, char *line)
// {
// 	int i;
// 	int j;

// 	i = 0;
// 	j = 0;
// 	if (!allocate_token(tmp_lex, line))
// 		return (0);
// 	while (line[i])
// 	{
// 		j = 0;
// 		while (line[i] && is_whitespace(line[i]))
// 			i++;
// 		while (!is_whitespace(line[i + j]) && line[i + j] != ',')
// 		{
// 			if (line[i + j] == '#')
// 				return (1);
// 			// if (line[i + j] == ',')
// 				// do something
// 			j++;
// 		}
// 		if (line[i + j] == ',')
// 			j++;
// 		if (!add_token(tmp_lex, line, i, j))
// 			return (0);
// 		(j == 0) ? (i++) : (i = i + j);
// 	}
// 	return (1);
// }

// entree:	live	%42,%42  %42    ,    %42 # entree
// entree:	live	%42		# entree
// 	ld	%0,r5
// 	ld	%0,r5
// 	zjmp	%:lebocal_lesgrosgamins

// int					splitter(t_lexer **tmp_lex, char *line)
// {
// 	int i;
// 	int j;

// 	i = 0;
// 	j = 0;
// 	if (!allocate_token(tmp_lex, line))
// 		return (0);
// 	while (line[i])
// 	{
// 		j = 0;
// 		while (line[i] && is_whitespace(line[i]))
// 			i++;
// 		while (!is_whitespace(line[i + j]) && line[i + j] != ',')
// 		{
// 			if (line[i + j] == '#')
// 				return (1);
// 			j++;
// 		}
// 		if (line[i + j] == ',')
// 			j++;
// 		if (!add_token(tmp_lex, line, i, j))
// 			return (0);
// 		(j == 0) ? (i++) : (i = i + j);
// 	}
// 	return (1);
// }
