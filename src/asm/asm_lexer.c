/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_lexer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 04:24:28 by nivergne          #+#    #+#             */
/*   Updated: 2020/02/02 06:26:19 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"
#include "ft_printf.h"

/*
** ==================== is_useless ====================
** This function return 1 if the string is full of whitespaces
** or if it is a comment and 0 otherwise. 
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
** ====================  ====================
** 
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
** ====================  ====================
** 
*/

static void		chain_code_line(t_code_line **current_c_line, t_code_line *new)
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
** Read a line with gnl, then check if it's usefull
** if it doesm allocate a new node, store the address 
** in a tmp variable because at the start of the function
** the first node is pointing on null. 
** Then call the tokenizer function
*/

int					lexer(int fd, t_data **data, t_code_line **c_line)
{
	int				index;
	char			*line;
	t_code_line		*new_c_line;
	t_code_line 	*current_c_line;

	line = NULL;
	index = (*data)->index_line;
	current_c_line = *c_line;
	while (get_next_line(fd, &line) > 0)
	{
		if (!(line && !line[0] && is_useless(line)))
		{
			if (!(new_c_line = create_code_line(line, index)))
				return (error_msg(ERR_LEXER_NODE_CREATE, 0));
			chain_code_line(&current_c_line, new_c_line);
			if (!tokenizer(current_c_line, line))
				return (error_msg("error in lexer", 0));
			if (!(*c_line))
				*c_line = new_c_line;
		}
		ft_strdel(&line);
		index++;
	}
	return (1);
}

