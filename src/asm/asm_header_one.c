/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_header_one.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 23:44:32 by amamy             #+#    #+#             */
/*   Updated: 2020/01/26 02:00:40 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include "asm.h"
#include "libft.h"
#include "ft_printf.h"

/*
** ==================== get_name ====================
** if the commands is .name get the string associated
** if there is a syntax error, return an error
*/

int		get_name(int i, char *line, t_data **data)
{
	if (ft_strncmp(".name", line + i, 5) == 0)
	{
		i = i + 5;
		if (!get_string(data, line + i, 1))
			return (error_msg("invalid syntax for name", 0));
		(*data)->name_line = (*data)->index_line;
		return (1);
	}
	return (0);
}

/*
** ==================== get_comment ====================
** if the commands is .comment get the string associated
** if there is a syntax error, return an error
*/

int		get_comment(int i, char *line, t_data **data)
{
	if ((ft_strncmp(".comment", line + i, 8) == 0))
	{
		i = i + 8;
		if (!get_string(data, line + i, 2))
			return (error_msg("invalid syntax for comment", 0));
		(*data)->comment_line = (*data)->index_line;
		return (1);
	}
	return (0);
}

/*
** ==================== little_parsing ====================
** Skip whitespaces before commands and call functions to get
** the name or description of the corewar champion. If there is a
** syntax error, return an error.
*/

int		little_parsing(char *line, t_data **data)
{
	int i;

	i = 0;
	while (line[i])
	{
		while (is_whitespace(line[i]))
			i++;
		if (get_name(i, line, data))
		{
			i = i + 5;
			return (1);
		}
		if (get_comment(i, line, data))
		{
			i = i + 8;
			return (1);
		}		
		else if (line[i] != '.')
			return (error_msg("Unknown token in header", 0));
		i++;
	}
	return (1);
}

/*
** ==================== lexer_header ====================
** Deals with the headerpart. After this function, GNL is 
** supposed to have read at least 2 lines (the 2 commands).
** comments lines will be ignored.
** The first 2 nodes of lexer will filled.
*/

int		header(int fd, t_data **data)
{
	int		i;
	char	*line;

	i = 0;
	line = NULL;
	if (!(*data = ft_memalloc(sizeof(t_data))))
		return (0);
	(*data)->index_line = 1;
	while (((!((*data)->name)) || (!((*data)->comment))) && (get_next_line(fd, &line) > 0)) // (*data) && 
	{
		while (is_whitespace(line[i]))
			i++;
		if (line && (!is_comment(line[i]) || !ft_strcmp(line, "")))
			if (!little_parsing(line, data))
				return(error_msg("Fail in heder", 0));
		(*data)->index_line++;
	}
	print_data(data);
	return (1);
}
