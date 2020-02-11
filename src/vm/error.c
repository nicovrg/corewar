/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 17:21:52 by qgirard           #+#    #+#             */
/*   Updated: 2020/02/11 00:47:15 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include "libft.h"

/*
** ==================== error_header ====================
** close the file director when an error occures when reading the file
*/

int		error_header(int *fd)
{
	close(*fd);
	return (0);
}

/*
** ==================== error_msg_null ====================
** print an error message and return NULL.
*/

void	*error_msg_null(char *error_msg, t_header *state)
{
		if (state)
		state[0] = 0;
	ft_putendl(error_msg);
	return (NULL);
}
/*
** ==================== error_msg ====================
** print an error message
*/

int		error_msg(char *error_msg, int i, t_header *state)
{
	if (state)
		state[0] = 0;
	ft_putendl(error_msg);
	return (i);
}

/*
** ==================== vm_error_champion ====================
** error function that appears if the size of the champion is too big or
** if the file is not a valid champion
*/

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

int     inst_error(t_instruction **instruction, t_corewar *arena)
{
	(void)instruction;
	(void)arena;
    return (1);
}