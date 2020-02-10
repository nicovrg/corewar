/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_lists.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 05:40:42 by qgirard           #+#    #+#             */
/*   Updated: 2020/02/10 01:20:30 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include "libft.h"
#include "ft_printf.h"

/*
** ==================== champions_list ====================
** initialize and update the list of the champions
*/

t_champion		*champions_list(t_champion **champions)
{
	t_champion	*tmp;
	t_champion	*new;

	tmp = (*champions);
	while (tmp && tmp->next)
		tmp = tmp->next;
	if (!(new = (t_champion *)ft_memalloc(sizeof(t_champion))))
		return (NULL);
	if (*champions)
		tmp->next = new;
	else
		*champions = new;
	return (new);
}
