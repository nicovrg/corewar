/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 20:26:54 by qgirard           #+#    #+#             */
/*   Updated: 2020/01/24 20:37:47 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include "libft.h"
#include "ft_printf.h"

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