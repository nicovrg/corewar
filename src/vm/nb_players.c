/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nb_players.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 21:38:25 by qgirard           #+#    #+#             */
/*   Updated: 2020/02/10 23:50:55 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include "libft.h"

/*
** ==================== put_nb_player ====================
** will put nb_player to champions by checking if the slot is empty and then
** will fill it
*/

static int		put_nb_player(t_corewar *arena, t_champion **tmp)
{
	if (arena->first_player == 0)
	{
		(*tmp)->player = 1;
		arena->first_player = 1;
	}
	else if (arena->second_player == 0)
	{
		(*tmp)->player = 2;
		arena->second_player = 1;
	}
	else if (arena->third_player == 0)
	{
		(*tmp)->player = 3;
		arena->third_player = 1;
	}
	else if (arena->fourth_player == 0)
	{
		(*tmp)->player = 4;
		arena->fourth_player = 1;
	}
	return (1);
}

/*
** ==================== find_nb_player ====================
** this function will check if a number player is not bigger than
** the total number of champions
*/

int				find_nb_player(t_corewar *arena, t_champion **champions)
{
	t_champion	*tmp;

	tmp = (*champions);
	while (tmp)
	{
		if (tmp->player > 0)
			if (tmp->player > count_champions(champions))
				return (error_msg(ERR_VM_NB_PLAYERS_EXCEED, 0, NULL));
		if (tmp->player == 0)
			put_nb_player(arena, &tmp);
		tmp = tmp->next;
	}
	return (1);
}

/*
** ==================== fill_nb_player ====================
** will block the number_player that was assigned in fix_nb_player
*/

static int		fill_nb_player(t_corewar *arena)
{
	if (arena->nb_player == 1)
		arena->first_player = 1;
	else if (arena->nb_player == 2)
		arena->second_player = 1;
	else if (arena->nb_player == 3)
		arena->third_player = 1;
	else if (arena->nb_player == 4)
		arena->fourth_player = 1;
	return (1);
}

/*
** ==================== fix_nb_player ====================
** if flag -n is present this function will arena the size of the champion
*/

static int		fix_nb_player(t_corewar *arena, t_champion **champions,
t_champion **tmp)
{
	t_champion	*ptr;

	ptr = (*champions);
	while (ptr)
	{
		if (ptr->player == arena->nb_player)
			ptr->player = 0;
		ptr = ptr->next;
	}
	(*tmp)->player = arena->nb_player;
	fill_nb_player(arena);
	return (1);
}

int				add_nb_player(t_corewar *arena, t_champion **champions,
t_champion **tmp)
{
	fix_nb_player(arena, champions, tmp);
	return (1);
}
