/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 15:02:06 by nivergne          #+#    #+#             */
/*   Updated: 2018/11/13 16:09:40 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*elem_to_del;
	t_list	*next_elem_to_del;

	if (alst != NULL)
	{
		elem_to_del = *alst;
		while (elem_to_del)
		{
			next_elem_to_del = elem_to_del->next;
			del(elem_to_del->content, elem_to_del->content_size);
			free(elem_to_del);
			elem_to_del = next_elem_to_del;
		}
		*alst = NULL;
	}
}

/*
** DESCRIPTION
** Delete the list.
*/
