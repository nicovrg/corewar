/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_header.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasv <nicolasv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 23:44:32 by amamy             #+#    #+#             */
/*   Updated: 2020/01/25 04:51:02 by nicolasv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include "asm.h"
#include "libft.h"
#include "ft_printf.h"

int		is_comment(char c)
{
	if (c == COMMENT_CHAR)
		return (1);
	return (0);
}

int		is_whitespace(char c)
{
	if ((c >= 10 && c <= 13) || c == ' ')
		return (1);
	return (0);
}

int		is_dirty(char *str)
{
	int i;

	i = 0;
	ft_printf("is dirtystr = %s\n", str);
	if (!str)
		return (1);
	while (str[i] && str[i] != '#')
		i++;
	if (str[i] != '\0')
	{
		ft_printf("ca return de la merde la\n");
		return (0);
	}
	return (1);
}

int		get_string(t_data **data, char *str)
{
	int i;
	int j;

	i = 0;
	j = 0;
	ft_putstr("get_string says hello\n");
	ft_printf("str = |%s|\n", str);
	while (str[i])
	{
		while (str[i] && is_whitespace(str[i]))
			i++;
		if (str[i] && str[i++] == '\"')
		{
			while (str[i + j] && str[i + j] != '\"')
				j++;
			ft_printf("We feed is-dirty with ; |%s|\n", str[i + j + 1]);
			if (!(is_dirty(&str[i + j + 1])))
				return (0);
			else
			{
				(*data)->name = ft_strndup(&str[i], j);
				return (1);
			}
		}
		i++;
	}
	return (0);
}

int		little_parsing(char *line, t_data **data)
{
	int i;

	i = 0;
	while (line[i])
	{
		while (is_whitespace(line[i]))
			i++;
		if (ft_strncmp(".name", line + i, 5) == 0)
			if (!get_string(data, line + i + 5))
				return (error_msg("invalid syntax for name", 0));
		if ((ft_strncmp(".comment", line + i, 8) == 0))
			if (!get_string(data, line + i + 8))
				return (error_msg("invalid syntax for comment", 0));
		i++;
	}
	return (1);
}

/*
** ==================== lexer_header ====================
** Deals with the headerpart. after this function, GNL is 
** supposed to have read at least 2 lines (the 2 commands).
** comments lines will be ignored.
** The first 2 nodes of lexer will filled.
*/

int		header(int fd, t_data **data)
{
	char	*line;

	line = NULL;
	if (!(*data = ft_memalloc(sizeof(t_data))))
		return (0);
	while ((*data) && ((!((*data)->name_line)) || (!((*data)->comment_line))) && (get_next_line(fd, &line) > 0))
	{
		if (line && !is_comment(line[0]))
			little_parsing(line, data);
		(*data)->index_line++;
	}
	print_data(data);
	
	return (1);
}
