/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_splitter copy.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 04:42:59 by nivergne          #+#    #+#             */
/*   Updated: 2020/01/31 15:51:33 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"
#include "ft_printf.h"

/*
** ==================== count_tokens ====================
** This function count the number of token in one line
*/

static int			count_tokens(char *line)
{
	int i;
	int j;
	int ret;

	i = 0;
	ret = 0;
	while (line[i])
	{
		j = 0;
		while (line[i] && is_whitespace(line[i]))
			i++;
		while (!is_whitespace(line[i + j]) && line[i + j] != ',')
		{
			if (line[i + j] == '#')
				return (ret);
			j++;
		}
		if (line[i + j] == ',') //ret++;
			j++;
		ret++;
		(j == 0) ? (i++) : (i = i + j);
	}
	return (ret);
}

/*
** ==================== allocate_token ====================
** This function count the number of token, then allocate a table
** of pointers on structure s_token, then allocate each cell
** of this table.
*/

static int			allocate_token(t_code_line **tmp_lex, char *line)
{
    int	i;
	int nb_token;

    i = 0;
	nb_token = count_tokens(line);
	if (!((*tmp_lex)->token = ft_memalloc((sizeof(t_token) * nb_token) + 1)))
        return (0);
    while (i < nb_token)
    {
        if (!((*tmp_lex)->token[i] = ft_memalloc(sizeof(t_token))))
            return (0);
        i++;
    }
	(*tmp_lex)->nb_token = nb_token;
    return (1);
}

/*
** ==================== add_token ====================
** This function set the lexeme value of a token
*/

int					add_token(t_code_line **tmp_lex, char *line, int i, int j)
{
	ft_printf("sssssss = %c\n", line[i + j - 1]);
	// if (line[i + j - 1] == ',')
		// j--;
	if (!((*tmp_lex)->token[1]->lexeme = ft_strndup(line + i, j)))
		return (error_msg("fail alloc token->lexeme with strndup", 0));
	// ft_printf("nb token = %d\ntoken = |%s|\nline = %s\ni = %d\nj = %d\n", (*tmp_lex)->nb_token, (*tmp_lex)->token[1]->lexeme, line, i, j);
	return (1);
}

/*
** ==================== splitter ====================
** This function takes a lexer node and a line, split the line
** around spaces and commas, then return a table of all the
** tokens lexeme
*/

int					splitter(t_code_line **tmp_lex, char *line)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (!allocate_token(tmp_lex, line))
		return (0);
	while (line[i])
	{
		j = 0;
		while (line[i] && is_whitespace(line[i]))
			i++;
		while (!is_whitespace(line[i + j]) && line[i + j] != ',')
		{
			if (line[i + j] == '#')
				return (1);
			j++;
		}
		if (line[i + j] == ',')
			j++;
		if (!add_token(tmp_lex, line, i, j))
			return (0);
		(j == 0) ? (i++) : (i = i + j);
	}
	return (1);
}

// entree:	live	%42,%42  %42    ,    %42 # entree
// entree:	live	%42		# entree
// 	ld	%0,r5
// 	ld	%0,r5
// 	zjmp	%:lebocal_lesgrosgamins



























































// NEW
















/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_splitter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasv <nicolasv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 04:42:59 by nivergne          #+#    #+#             */
/*   Updated: 2020/01/27 03:41:35 by nicolasv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"
#include "ft_printf.h"

/*
** ==================== count_tokens ====================
** This function count the number of token in one line
*/

static int			count_tokens(char *line)
{
	int i;
	int j;
	int ret;

	i = 0;
	ret = 0;
	while (line[i])
	{
		j = 0;
		while (line[i] && is_whitespace(line[i]))
			i++;
		while (!is_whitespace(line[i + j]) && line[i + j] != ',')
		{
			if (line[i + j] == '#')
				return (ret);
			j++;
		}
		if (line[i + j] == ',') //ret++;
		{
			j++;
			ret++;
		}
		(j == 0) ? (i++) : (i = i + j);
	}
	return (ret);
}

/*
** ==================== allocate_token ====================
** This function count the number of token, then allocate a table
** of pointers on structure s_token, then allocate each cell
** of this table.
*/

static int			allocate_token(t_code_line **tmp_lex, char *line)
{
    int	i;
	int nb_token;

    i = 0;
	nb_token = count_tokens(line);
	if (!((*tmp_lex)->token = ft_memalloc((sizeof(t_token) * nb_token) + 1)))
        return (0);
    while (i < nb_token)
    {
        if (!((*tmp_lex)->token[i] = ft_memalloc(sizeof(t_token))))
            return (0);
        i++;
    }
	(*tmp_lex)->nb_token = nb_token;
    return (1);
}

/*
** ==================== add_token ====================
** This function set the lexeme value of a token
*/

int					add_token(t_code_line **tmp_lex, char *line, int i, int j)
{
	// ft_printf("sssssss = %c\n", line[i + j - 1]);
	if (!(line[i + j - 1] == ','))
	{
		if (!((*tmp_lex)->token[1]->lexeme = ft_strndup(line + i, j)))
			return (error_msg("fail alloc token->lexeme with strndup", 0));
	}
	else
	{
		if (!((*tmp_lex)->token[1]->lexeme = ft_strndup(",", 1)))
			return (error_msg("fail alloc token->lexeme with strndup", 0));
	}
	return (1);
}

/*
** ==================== splitter ====================
** This function takes a lexer node and a line, split the line
** around spaces and commas, then return a table of all the
** tokens lexeme
*/

int					splitter(t_code_line **tmp_lex, char *line)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (!allocate_token(tmp_lex, line))
		return (0);
	while (line[i])
	{
		j = 0;
		while (line[i] && is_whitespace(line[i]))
			i++;
		while (!is_whitespace(line[i + j]) && line[i + j] != ',')
		{
			if (line[i + j] == '#')
				return (1);
			j++;
		}
		if (line[i + j] == ',')
			j++;
		if (!add_token(tmp_lex, line, i, j))
			return (0);
		(j == 0) ? (i++) : (i = i + j);
	}
	return (1);
}

// entree:	live	%42,%42  %42    ,    %42 # entree
// entree:	live	%42		# entree
// 	ld	%0,r5
// 	ld	%0,r5
// 	zjmp	%:lebocal_lesgrosgamins