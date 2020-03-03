/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 20:26:54 by qgirard           #+#    #+#             */
/*   Updated: 2020/02/11 01:28:17 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include "libft.h"
#include "ft_printf.h"

/*
** ==================== introduce_champs ====================
** introduce champs by printing size, name, and comment of the champion
*/

int		introduce_champs(t_champion **champions)
{
	t_champion	*tmp;

	tmp = (*champions);
	ft_putendl("Introducing contestants...");
	while (tmp)
	{
		ft_printf("* Player %d weighing %lu bytes, \"%s\" (\"%s\") !\n",
		tmp->player, tmp->size, tmp->name, tmp->comment);
		tmp = tmp->next;
	}
	return (1);
}
