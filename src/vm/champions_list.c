/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   champions_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 05:40:42 by qgirard           #+#    #+#             */
/*   Updated: 2020/02/10 04:31:44 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include "libft.h"
#include "ft_printf.h"


/*
** ==================== count_champions ====================
** count the number of champions
** it allows to check if we can add more champions
*/

int		count_champions(t_champion **champions)
{
	int			i;
	t_champion	*tmp;

	i = 0;
	tmp = (*champions);
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

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
