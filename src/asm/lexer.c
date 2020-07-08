/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 04:24:28 by nivergne          #+#    #+#             */
/*   Updated: 2020/07/08 23:33:45 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"
#include "ft_printf.h"

/*
** ==================== create_code_line ====================
** Allocate memory for a new line of code, give it its number
** and the content of the line.
*/

static t_code_line	*create_code_line(char *line, int index)
{
	t_code_line		*new;

	if (!(new = (t_code_line *)ft_memalloc(sizeof(t_code_line))))
		return (0);
	new->nb_line = index;
	new->line = ft_strdup(line);
	return (new);
}

/*
** ==================== chain_code_line ====================
** Receives 2 t_code_line, setting the line->next address of the 
** first one to point on the second.
** In case of first line, set the pointer himself.
*/

static void			chain_code_line(t_code_line **current_c_line, t_code_line *new)
{
	if ((*current_c_line))
	{
		(*current_c_line)->next = new;
		(*current_c_line) = new;
	}
	else
		(*current_c_line) = new;
}

/*
** ==================== lexer ====================
** Read a line with gnl, then check if there is something
** to get from it. If so, send it for token analyse.
** Raise error flag if line comes back with errors.
*/

int					lexer(int fd, t_data **data, t_code_line **c_line)
{
	int				index;
	char			*line;
	t_code_line		*new_c_line;
	t_code_line		*current_c_line;

	line = NULL;
	index = (*data)->index_line;
	current_c_line = *c_line;
	while (get_next_line(fd, &line) > 0)
	{
		if (!(line && (!line[0] || is_str_whitespace_or_comment(line))))
		{
			if (!(new_c_line = create_code_line(line, index)))
				error_msg_close_fd(ERR_LEXER_NODE_CREATE, 0, fd);
			chain_code_line(&current_c_line, new_c_line);
			if (!get_tokens_from_current_line(&current_c_line, line))
				error_msg_close_fd("error in lexer", 0, fd);
			if ((*current_c_line).errors && !(*data)->errors)
				(*data)->errors = LINE_ERROR_LEXICAL;
			if (!(*c_line))
				*c_line = new_c_line;
		}
		ft_strdel(&line);
		index++;
	}
	close(fd);
	return (1);
}
