/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 15:26:46 by nivergne          #+#    #+#             */
/*   Updated: 2018/11/13 12:13:20 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new_lst;

	if (lst && f)
	{
		new_lst = f(lst);
		new_lst->next = ft_lstmap(lst->next, f);
		return (new_lst);
	}
	return (NULL);
}

/*
** DESCRIPTION
** Apply the f function to each element of the list,
** creating a new "fresh" list
*/
