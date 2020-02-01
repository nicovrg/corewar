/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_lexer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 04:24:28 by nivergne          #+#    #+#             */
/*   Updated: 2020/02/01 02:02:36 by amamy            ###   ########.fr       */
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

static int			new_line_node(t_code_line **c_line)
{
	t_code_line		*new;
	
	while ((*c_line) && (*c_line)->next)
		(*c_line) = (*c_line)->next;
	if (!(new = (t_code_line *)ft_memalloc(sizeof(t_code_line))))
		return (0);
	if ((*c_line))
	{
		(*c_line)->next = new;
		(*c_line) = (*c_line)->next;
	}	
	else
		(*c_line) = new;
	return (1);
}

/*
** ==================== lexer ====================
** 
*/

int					lexer(int fd, t_data **data, t_code_line *c_line) 
{
	int			index;
	char		*line;
	t_code_line	*tmp_c_line;

	line = NULL;
	tmp_c_line = c_line;
	index = (*data)->index_line;
	stuff_token_guns();
	while (get_next_line(fd, &line) > 0)
	{
		if (line && !line[0] && is_useless(line) && index++)
			continue ;
		if (tmp_c_line->nb_line)
			if (!new_line_node(&tmp_c_line))
				return (error_msg(ERR_LEXER_NODE_CREATE, 0));
		tmp_c_line->nb_line = index;
	 	if (!tokenizer(tmp_c_line, line))
            return (0);
		ft_strdel(&line);
		// print_lexer(data, &c_line);
		index++;
	}
	ft_printf("(*c_line)->nb_line : %d\n", tmp_c_line->nb_line);
	return (1);
}