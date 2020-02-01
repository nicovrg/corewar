/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_lexer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 04:24:28 by nivergne          #+#    #+#             */
/*   Updated: 2020/02/01 06:04:07 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"
#include "ft_printf.h"

/*
** ==================== is_useless ====================
** This function return 1 if the string is full of whitespaces
** or if it is a comment.
** and 0 otherwise. 
*/

static int			is_useless(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '#')
			return (1);
		if (!((str[i] >= 9 && str[i] <= 13) || str[i] == ' '))
			return (0);
		i++;
	}
	return (1);
}

/*
** ==================== new_lexer_node ====================
** if its the first line, instanciate the list
** else go at the end of the list and add a new node
*/

static t_code_line	*new_line_node(t_code_line **tmp_c_line, char *line, int index)
{
	t_code_line		*new;
	
	new = NULL;
	if (!(new = (t_code_line *)ft_memalloc(sizeof(t_code_line))))
		return (0);
	new->nb_line = index;
	new->line = ft_strdup(line);
	if ((*tmp_c_line))
	{
		(*tmp_c_line)->next = new;
		(*tmp_c_line) = new;
	}
	else
		(*tmp_c_line) = new;
	return (new);
}

/*
** ==================== lexer ====================
** 
*/

int					lexer(int fd, t_data **data, t_code_line **c_line)
{
	int			index;
	char		*line;
	t_code_line	*tmp;
	t_code_line *tmp_c_line;

	line = NULL;
	index = (*data)->index_line;
	tmp_c_line = *c_line;
	stuff_token_guns();
	while (get_next_line(fd, &line) > 0)
	{
		if (!(line && !line[0] && is_useless(line)))
		{
			if (!(tmp = new_line_node(&tmp_c_line, line, index)))
				return (error_msg(ERR_LEXER_NODE_CREATE, 0));
			if (!tokenizer(c_line, line))
				return (error_msg("error in lexer", 0));
			if (!(*c_line))
				*c_line = tmp;
		}
		ft_strdel(&line);
		index++;
	}
	return (1);
}

// N : nombre de lignes dans ton fichiers
// M : nombre de nodes actuellement dans ta liste
// N*N


/*
** ==================== steven tricks ====================
**	c_line[0]->nb_line = index;
** 	(*(c_line)->nb_line = index;
** 	(*(c_line + 0))->nb_line = index;
** 	(*(*c_line)).nb_line = index;
** 	(**c_line).nb_line = index;
** 	c_line[0][0].nb_line = index;


** memcpy(&b, &a, sizeof(int));
*/