/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_tokeniser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasv <nicolasv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 04:28:29 by nivergne          #+#    #+#             */
/*   Updated: 2020/01/25 03:16:35 by nicolasv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"

/*
** ==================== new_token_node ====================
** if it s the first token, instanciate the list
** else go at the end of the list and add a new node
*/

// int		new_token_node(t_token **token)
// {
// 	t_token		*new;
// 	t_token		*tmp_token;

// 	tmp_token = (*token);
// 	while (tmp_token && tmp_token->next)
// 		tmp_token = tmp_token->next;
// 	if (!(new = (t_token *)ft_memalloc(sizeof(t_token))))
// 		return (0);
// 	if ((*token))
// 		tmp_token->next = new;
// 	else
// 		(*token) = new;
// 	return (1);
// }








/*
** ==================== create_tokens ====================
** 
*/

int		create_tokens(char *line, t_token **token)
{
    (void)token;
    (void)line;
    ft_putendl(line);
    return (1);
}


