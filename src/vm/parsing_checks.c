/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_checks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 12:23:03 by qgirard           #+#    #+#             */
/*   Updated: 2020/02/10 23:50:55 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include "op.h"
#include "libft.h"

/*
** ==================== check_champion_size ====================
** check if the size of the champion is over CHAMP_MAX_SIZE
** if it's the case return an error
*/

int		check_champion_size(char *argv, t_champion **champions)
{
	t_champion	*tmp;

	tmp = (*champions);
	while (tmp && tmp->next)
		tmp = tmp->next;
	if (tmp->size > CHAMP_MAX_SIZE)
		return (vm_error_champion(argv, 2, tmp->size));
	return (1);
}

/*
** ==================== check_if_number ====================
** check if argument is a number
*/

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

/*
** ==================== check_player_or_cycles ====================
** if flag -n is present check the validity of the player number and arena it
** else if flag -dump is present arena the cycles we have to pass before dump
** memory
*/

int		check_player_or_cycles(char *argv, t_corewar *arena)
{
	if (arena->n_option == 1)
	{
		arena->nb_player = ft_atoi(argv);
		if (arena->nb_player < 1 || arena->nb_player > 4)
			return (error_msg(ERR_VM_NB_PLAYERS, 0, NULL));
	}
	else if (arena->dump_option == 1)
		arena->dump_cycles = ft_atol(argv);
	return (1);
}

/*
** ==================== check_flags ====================
** check if arguments are existed flags
*/

int		check_flags(char *argv, t_corewar *arena)
{
	if (!ft_strcmp(argv, "-n"))
		arena->n_option = 1;
	else if (!ft_strcmp(argv, "-dump"))
		arena->dump_option = 1;
	else
		return (0);
	return (1);
}