/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_checks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 12:23:03 by qgirard           #+#    #+#             */
/*   Updated: 2019/11/07 15:23:43 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "libft.h"

int		check_if_number(char *argv)
{
	int		i;

	i = 0;
	while (argv[i])
	{
		if (!ft_isdigit(argv[i]))
			return (0);
		i++;
	}
	return (1);
}

int		check_player_or_cycles(char *argv, t_corewar *stock)
{
	if (!check_if_number(argv))
		return (error_msg(ERR_VM_NUMBERS, 0));
	if (stock->n_option == 1)
	{
		stock->nb_player = ft_atoi(argv);
		if (stock->nb_player < 1 || stock->nb_player > 4)
			return (error_msg(ERR_VM_NB_PLAYERS, 0));
	}
	else if (stock->dump_option == 1)
		stock->dump_cycles = ft_atol(argv);
	return (1);
}

int		check_flags(char *argv, t_corewar *stock)
{
	if (!ft_strcmp(argv, "-n"))
		stock->n_option = 1;
	else if (!ft_strcmp(argv, "-dump"))
		stock->dump_option = 1;
	else
		return (0);
	return (1);
}