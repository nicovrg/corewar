/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_lists.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 05:40:42 by qgirard           #+#    #+#             */
/*   Updated: 2020/01/22 06:10:10 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include "libft.h"

t_champion		*champions_list(t_champion **champions)
{
	t_champion	*tmp;
	t_champion	*new;

	tmp = (*champions);
	while (tmp && tmp->next)
		tmp = tmp->next;
	if (!(new = (t_champion *)malloc(sizeof(t_champion))))
		return (NULL);
	new->next = NULL;
	new->name = NULL;
	new->size = 0;
	new->player = 0;
	if (*champions)
		tmp->next = new;
	else
		*champions = new;
	return (new);
}