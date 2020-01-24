/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_lexer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 04:24:28 by nivergne          #+#    #+#             */
/*   Updated: 2020/01/24 06:11:59 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"
#include "../../ressources/op.h"

int		comment(char *line)
{
	if (line && line[0] == COMMENT_CHAR)
		return (1);
	return (0);
}

int		command(char *line)
{
	if (line && line[0] == '.' && ft_strncmp(NAME_CMD_STRING, line, 5) == 0)
	{
		if (flag == 1 || flag == 3)
			return (=1);
		else
		{
			line_split[0] = ft_strdup(NAME_CMD_STRING);
			flag++;
		}
	}
	else if (line && line[0] == '.' && ft_strncmp(COMMENT_CMD_STRING, line, 5) == 0)
	{
		if (flag == 2 || flag == 3)
			return (=1);
		else
			flag = flag + 2;
	}
	
}

int		commands(t_lexer **lex)
{
	int i;

	i = 0;
	while (*lex->line[i] >= 'a' && *lex->line[i] >= 'z')
	

	return (1);
}

/*
** ==================== lexer_header ====================
** Deals with the headerpart. after this function, GNL is 
** supposed to have read at least 2 lines (the 2 commands).
** comments lines will be ignored.
** The first 2 nodes of lexer will filled.
*/

int		lexer_header(t_lexer **lex, *int nb_line, int fd)
{
	int		flag;
	char	*words[2];

	commands = 0;
	lex->words = words;
	while ((get_next_line(fd, &((*lex))->line) > 0) && commands <= 2)
	{
		if (!(comment(&((*lex))->line)))
		{
			if (commands(*lex, commands))
				commands++;
			else
				return (0);
		}
	}
	*nb_line++;	

}

	return (1)
}
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
	if (!lexer_header(lex, &index_line))
		return (0);
	while (get_next_line(fd, &((*lex)->line)) > 0)
	{
		// ft_putendl(*(&(*lex)->line));
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