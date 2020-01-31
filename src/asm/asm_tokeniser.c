/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_tokeniser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 04:42:59 by nivergne          #+#    #+#             */
/*   Updated: 2020/01/31 21:43:15 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"
#include "ft_printf.h"

/*
** ==================== new_token_node ====================
** if it s the first token, instanciate the list
** else go at the end of the list and add a new node
** In case of success, return a pointer to the newly available node.
*/

static int		new_token_node(t_code_line *c_line, t_token **token)
{
	t_token		*new;
	while ((*token) && (*token)->next)
		*token = (*token)->next;
	if (!(new = (t_token *)ft_memalloc(sizeof(t_token))))
		return (0);
	new->parent = c_line;
	if ((*token))
	{
		(*token)->next = new;
		*token = (*token)->next;
	}
	else
		(*token) = new;
	return (1);
}

// char			*isolate_token(char *src, int i)
// {
	
// }

/*
** ==================== create_tokens ====================
** 
*/

int			create_token(t_code_line *c_line, t_token **token, char *line, int length)
{
	char	*lexeme;
	// ft_strncpy(&lexeme, line, length);
	lexeme = ft_strndup(line, length);
	ft_printf("length : %d, lexeme : ----> |%s|\n-------------\n", length, lexeme);
	token_machine_gun(c_line, lexeme);
	(void)token;
	(void)line;
	(void)lexeme;
	(void)length;
	(void)c_line;
	
	// ft_putendl(line);
	return (1);
}

void			store_token_quantity(t_code_line *c_line)
{
	(void)c_line;
}

/*
** ==================== count_tokens ====================
** This function count the number of token in one line
** If there are multiples commas following each others, return an error
*/

// static int			count_tokens(char *line)
// {
// 	int i;
// 	int j;
// 	int ret;

// 	i = 0;
// 	ret = 0;
// 	if (ft_strnstr(line, ",,", ft_strlen(line)))
// 		return (error_msg("invalid line, multiples commas in a row", -1));
// 	while (line[i])
// 	{
// 		j = 0;
// 		while (line[i] && is_whitespace(line[i]))
// 			i++;
// 		while (line[i + j] && (!is_whitespace(line[i + j]) && !is_comma(line[i + j])))
// 		{
// 			if (is_comment(line[i + j]))
// 				return (ret);
// 			j++;
// 		}
// 		(line[i + j - 1] > 0 && is_comma(line[i + j - 1])) ? (j++) : (0);
// 		(line[i + j - 1] > 0 && is_comma(line[i + j - 1])) ? (ret++) : (0);
// 		(j == 0) ? (i++) : (i = i + j);
// 		ret++;
// 	}
// 	return (ret);
// }

/*
** ==================== allocate_token ====================
** This function count the number of token, then allocate a table
** of pointers on structure s_token, then allocate each cell
** of this table.
*/

// static int			allocate_token(t_code_line **tmp_lex, char *line)
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

// int					add_token(t_code_line **tmp_lex, char *line, int i, int j)
// {
// 	// ft_printf("sssssss = %c\n", line[i + j - 1]);
// 	// ft_printf("sssssss = %s\n", line);
// 	if (!((*tmp_lex)->token[1]->lexeme = ft_strndup(line + i, j)))
// 		return (error_msg("fail alloc token->lexeme with strndup", 0));
// 	if (!(line[i + j - 1] == ','))
// 	{
// 		if (!((*tmp_lex)->token[1]->lexeme = ft_strndup(",", 1)))
// 			return (error_msg("fail alloc token->lexeme with strndup", 0));
// 	}
// 	return (1);
// }

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

// static int			is_empty(char *line)
// {
// 	int i;

// 	i = 0;
// 	while (is_whitespace(line[i]))
// 		i++;
// 	if (!line[i])
// 		return (1);
// 	return (0);
// }

/*
** ==================== splitter ====================
** This function takes a lexer node and a line, split the line
** around spaces and commas, and the following instructions are under modification
*/

int					tokenizer(t_code_line *c_line, char *line)
{
	int i;
	int j;
	t_token	*current_token;

	i = 0;
	j = 0;
	current_token = NULL;
	while (line[i] && is_whitespace(line[i]))
		i++;
	while (line[i] && !is_comment(line[i]))
	{
	// ft_printf("line = |%s|\n", &line[i]);
		ft_printf("line[i] |%c|\n", line[i]);
		j = 0;
		if (!new_token_node(c_line, &current_token))
			return (error_msg("error in asm_tokeniser.c -> new_token_node", 0));
		while (line[i + j] && !is_whitespace(line[i + j]) && !is_comment(line[i + j]) && !is_comma(line[i + j]))
			j++;
		if (is_comma(line[i + j]))
			j++;
		create_token(c_line, &current_token, line + i, j);
		i = i + j;
		while (line[i] && is_whitespace(line[i]))
			i++;
	}
	store_token_quantity(c_line);
	return (1);
}


// int					splitter(t_code_line **tmp_lex, char *line)
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

// int					splitter(t_code_line **tmp_lex, char *line)
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
