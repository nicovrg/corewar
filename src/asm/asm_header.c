/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_header.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasv <nicolasv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 23:44:32 by amamy             #+#    #+#             */
/*   Updated: 2020/01/25 02:37:07 by nicolasv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"
#include "op.h"

int		is_comment(char c)
{
	if (c == COMMENT_CHAR)
		return (1);
	return (0);
}

int		is_whitespace(char c)
{
	if (c => 10 && c =< 13 || c == ' ')
		return (1);
	return (0);
}

int		is_dirty()
{
	
}

int		get_string(t_data **data, char *str)
{
	//  .name                 "   fsfjsf s s fs fjsfk js "
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[i])
	{
		while (line[i] && is_whitespace(line[i]))
			i++;
		if (str[i] && str[i] == '\"')
		{
			while (str[i] && str[i] != '\"')
				j++;
			if (is_dirty(str[i + j]))
				return (0);
			else
			{
				(*data)->name_line = ft_strndup(str[i], j);
				return (1);
			}
		}
		i++;
	}
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

	if (!(ft_memalloc(sizeof(t_data))))
		return (0);
	while ((!((*data)->name_line)) && (!((*data)->comment_line)) && (get_next_line(fd, line) > 0))
	{
		if (!is_comment(line[0]))
		{
			while (line[i])
			{
				while (is_whitespace(line[i]))
					i++;
				if ((ft_strncmp(".name", line + i, 5) == 0) || (ft_strncmp(".comment", line + i, 8) == 0))
					if (!get_string(data, line + i + 5))
						return (error_msg("invalid syntax", 0);
			}
		}
		(*data)->index_line++;
	}
	return (1);
}
