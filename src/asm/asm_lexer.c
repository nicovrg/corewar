/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_lexer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasv <nicolasv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 04:24:28 by nivergne          #+#    #+#             */
/*   Updated: 2020/01/25 02:30:31 by nicolasv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"

/*
** ==================== new_lexer_node ====================
** if its the first line, instanciate the list
** else go at the end of the list and add a new node
*/

int		new_lexer_node(t_lexer **lex, int nb_line)
{
	t_lexer		*new;
	t_lexer		*tmp_lex;

	tmp_lex = (*lex);
	while (tmp_lex && tmp_lex->next)
		tmp_lex = tmp_lex->next;
	if (!(new = (t_lexer *)ft_memalloc(sizeof(t_lexer))))
		return (0);
	new->nb_line = nb_line;
	if ((*lex))
		tmp_lex->next = new;
	else
		(*lex) = new;
	return (1);
}

/*
** ==================== lexer ====================
** 
*/

int		lexer(int fd, t_lexer **lex) 
{
	int		index_line;

	index_line = 0;
	if (!new_lexer_node(lex, index_line))
		return (0);
	while (get_next_line(fd, &((*lex)->line)) > 0)
	{
		ft_putendl(*(&(*lex)->line));
		(*lex)->nb_line = index_line;
        //label
        if (!create_tokens((*lex)->line, &((*lex)->token)))
            return (0);
        //token    
		if (!new_lexer_node(lex, index_line))
			return (error_msg(ERR_LEXER_NODE_CREATE, 0));
		index_line++;
	}
	return (1);
}