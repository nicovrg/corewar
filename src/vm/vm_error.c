/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 17:21:52 by qgirard           #+#    #+#             */
/*   Updated: 2019/11/07 12:01:14 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "libft.h"

int		vm_usage(int i)
{
	ft_putendl("Usage:  ./corewar [-dump nbr_cycles] [[-n number] champion1.cor]");
	return (i);
}

int		vm_error_champion(char *champion)
{
	ft_putstr("Error: File ");
	ft_putstr(champion);
	ft_putendl("is not a valid champion");
	return (0);
}