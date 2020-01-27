/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_lexer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasv <nicolasv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 04:24:28 by nivergne          #+#    #+#             */
/*   Updated: 2020/01/27 01:50:08 by nicolasv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"
#include "ft_printf.h"

/*
** ==================== is_empty ====================
** This function return 1 if the string is full of whitespaces
** and 0 otherwise. 
*/

static int			is_empty(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
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

static t_lexer		**new_lexer_node(t_lexer **lex)
{
	t_lexer		*new;
	t_lexer		*tmp_lex;

	tmp_lex = (*lex);
	while (tmp_lex && tmp_lex->next)
		tmp_lex = tmp_lex->next;
	if (!(new = (t_lexer *)ft_memalloc(sizeof(t_lexer))))
		return (0);
	if ((*lex))
	{
		tmp_lex->next = new;
		return (&(tmp_lex->next));
	}	
	else
	{
		(*lex) = new;
		return (lex);
	}
	return (NULL);
}

/*
** ==================== lexer ====================
** 
*/

int					lexer(int fd, t_data **data, t_lexer **lex) 
{
	int		index;
	char	*line;
	t_lexer **tmp_lex;

	index = (*data)->index_line;
	line = NULL;
	tmp_lex = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		if (line && !line[0] && is_empty(line) && index++)
			continue ;
		if (!(tmp_lex = new_lexer_node(lex)))
			return (error_msg(ERR_LEXER_NODE_CREATE, 0));
		(*tmp_lex)->nb_line = index;
		(*tmp_lex)->line = ft_strdup(line);
	 	if (!splitter(tmp_lex, line))
            return (0);
		return (1);
		// if (!tokenizer(*lex))
        //     return (0);
		ft_strdel(&line);
		index++;
	}
	return (1);
}