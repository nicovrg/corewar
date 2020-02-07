/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tokens_from_current_line.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 04:42:59 by nivergne          #+#    #+#             */
/*   Updated: 2020/02/07 01:04:25 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"
#include "ft_printf.h"

/*
** ==================== create_tokens ====================
** 
*/

static t_token		*create_token(t_code_line **current_line, int position, int token_nb)
{
	t_token		*new;

	if (!(new = (t_token *)ft_memalloc(sizeof(t_token))))
		return (0);
	new->position = position;
	new->token_nb = token_nb;
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
	int			token_nb;
	t_token		*new_token;
	t_token		*current_token;

	i = 0;
	token_nb = 0;
	current_token = NULL;
	while (line[i] && !is_str_whitespace_or_comment(&line[i]))
	{
		while (line[i] && is_whitespace(line[i]))
			i++;
		if (!(new_token = create_token(current_c_line, i, token_nb++)))
			return (error_msg("error in tokeniser", 0));
		chain_token(&current_token, new_token);
		if (!(*current_c_line)->token)
			(*current_c_line)->token = new_token;
		(new_token->length > 0) ? (i += new_token->length) : (i++);
	}
	return (1);
}
