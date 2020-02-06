/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tokens_from_current_line.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 04:42:59 by nivergne          #+#    #+#             */
/*   Updated: 2020/02/06 02:24:57 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"
#include "ft_printf.h"

/*
** ==================== create_tokens ====================
** 
*/

static t_token		*create_token(t_code_line **current_line, int position)
{
	t_token		*new;

	if (!(new = (t_token *)ft_memalloc(sizeof(t_token))))
		return (0);
	new->position = position;
	new->code_line = (*current_line);
	determine_token_type_and_length(new);
	new->next = NULL;
	return (new);
}

/*
** ==================== chain_token ====================
** 
*/

static void		chain_token(t_token **current_token, t_token *new)
{
	if ((*current_token))
	{
		(*current_token)->next = new;
		(*current_token) = new;
	}
	else
		(*current_token) = new;
}

/*
** ==================== get_tokens_from_current_line ====================
** 
*/

int					get_tokens_from_current_line(t_code_line **current_c_line, char *line)
{
	int			i;
	t_token		*new_token;
	t_token		*current_token;

	i = 0;
	current_token = NULL;
	while (line[i] && !is_comment(line[i]))
	{
		while (line[i] && is_whitespace(line[i]))
			i++;
		if (!(new_token = create_token(current_c_line, i)))
			return (error_msg("error in tokeniser", 0));
		chain_token(&current_token, new_token);
		if (!(*current_c_line)->token)
			(*current_c_line)->token = new_token;
		(new_token->length > 0) ? (i += new_token->length) : (i++);
	}
	return (1);
}
