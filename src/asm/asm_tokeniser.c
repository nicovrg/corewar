/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_tokeniser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 04:42:59 by nivergne          #+#    #+#             */
/*   Updated: 2020/02/01 01:35:27 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"
#include "ft_printf.h"

/*
** ==================== new_token_node ====================
** if it s the first token, instanciate the list
** else go at the end of the list and add a new node
** In case of success, return a pointer to the newly available node.
*/

static int		new_token_node(t_code_line *c_line, t_token **token)
{
	t_token		*new;
	while ((*token) && (*token)->next)
		*token = (*token)->next;
	if (!(new = (t_token *)ft_memalloc(sizeof(t_token))))
		return (0);
	new->parent = c_line;
	if ((*token))
	{
		(*token)->next = new;
		*token = (*token)->next;
	}
	else
		(*token) = new;
	return (1);
}

/*
** ==================== create_tokens ====================
** 
*/

static int			find_token(t_token **token, char *line, int length)
{
	// this is stack method, but rais	es conditional jumps
	// char	lexeme[length];
	// ft_strncpy(lexeme, line, length);
	char	*lexeme;
	lexeme = ft_strndup(line, length);
	ft_printf("length : %d, lexeme : ----> |%s|\n-------------\n", length, lexeme);
	token_machine_gun(token, lexeme);
	(void)token;
	
	// ft_putendl(line);
	return (1);
}

void			store_token_quantity(t_code_line *c_line)
{
	(void)c_line;
}

/*
** ==================== tokenizer ====================
** This function takes a code_line node and a line, split the line
** around spaces and commas, and the following instructions are under modification
*/

int					tokenizer(t_code_line *c_line, char *line)
{
	int i;
	int j;
	t_token	*current_token;

	i = 0;
	j = 0;
	current_token = NULL;
	while (line[i] && is_whitespace(line[i]))
		i++;
	while (line[i] && !is_comment(line[i]))
	{
	// ft_printf("line = |%s|\n", &line[i]);
		ft_printf("line[i] |%c|\n", line[i]);
		j = 0;
		if (!new_token_node(c_line, &current_token))
			return (error_msg("error in asm_tokeniser.c -> new_token_node", 0));
		while (line[i + j] && !is_whitespace(line[i + j]) && !is_comment(line[i + j]) && !is_comma(line[i + j]))
			j++;
		if (is_comma(line[i + j]))
			j++;
		find_token(&current_token, line + i, j);
		i = i + j;
		while (line[i] && is_whitespace(line[i]))
			i++;
	}
	store_token_quantity(c_line);
	// c_line = current_token->parent;
	return (1);
}
