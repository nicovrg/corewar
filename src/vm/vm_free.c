/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 20:03:56 by qgirard           #+#    #+#             */
/*   Updated: 2020/01/24 20:08:44 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include "libft.h"

int		vm_free(t_champion **champions)
{
	t_champion	*tmp;

	while (*champions)
	{
		tmp = *champions;
		ft_strdel(&(tmp->name));
		ft_strdel(&(tmp->comment));
		*champions = (*champions)->next;
		free(tmp);
	}
	return (1);
}