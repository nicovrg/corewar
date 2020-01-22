/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 17:21:52 by qgirard           #+#    #+#             */
/*   Updated: 2020/01/22 05:36:21 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include "libft.h"

int		error_msg(char *error_msg, int i)
{
	ft_putendl(error_msg);
	return (i);
}

int		vm_error_champion(char *champion, int var, int size)
{
	ft_putstr("Error: File ");
	ft_putstr(champion);
	if (var == 1)
		ft_putendl(" is not a valid champion");
	else if (var == 2)
	{
		ft_putstr(" has too large a code (");
		ft_putnbr(size);
		ft_putendl(" bytes > 682 bytes)");
	}
	return (0);
}
