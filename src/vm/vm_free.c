/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 20:03:56 by qgirard           #+#    #+#             */
/*   Updated: 2020/02/10 02:52:41 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include "libft.h"

/*
** ==================== vm_free ====================
** free function that free the chained list of champions
*/

int		vm_free(t_champion **champions)
{
	t_champion	*tmp;

	while (*champions)
	{
		tmp = *champions;
		ft_strdel(&(tmp->name));
		ft_strdel(&(tmp->comment));
		ft_strdel(&(tmp->instructions));
		*champions = (*champions)->next;
		free(tmp);
	}
	return (1);
}
