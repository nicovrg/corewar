/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_nb_players.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 21:38:25 by qgirard           #+#    #+#             */
/*   Updated: 2020/01/24 22:08:26 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include "libft.h"

static int		find_nb_player(t_corewar *stock, t_champion **tmp)
{
	if (stock->first_player == 0)
		(*tmp)->player = 1;
	else if (stock->second_player == 0)
		(*tmp)->player = 2;
	else if (stock->third_player == 0)
		(*tmp)->player = 3;
	else if (stock->fourth_player == 0)
		(*tmp)->player = 4;
	stock->nb_player = (*tmp)->player;
	return (1);
}

static int		fill_nb_player(t_corewar *stock)
{
	if (stock->nb_player == 1)
		stock->first_player = 1;
	else if (stock->nb_player == 2)
		stock->second_player = 1;
	else if (stock->nb_player == 3)
		stock->third_player = 1;
	else if (stock->nb_player == 4)
		stock->fourth_player = 1;
	return (1);
}

static int		fix_nb_player(t_corewar *stock, t_champion **tmp)
{
	if (stock->nb_player == 1)
	{
		if (stock->first_player == 0)
			stock->first_player = 2;
	}
	else if (stock->nb_player == 2)
	{
		if (stock->second_player == 0)
			stock->second_player = 2;
	}
	else if (stock->nb_player == 3)
	{
		if (stock->third_player == 0)
			stock->third_player = 2;
	}
	else if (stock->nb_player == 4)
	{
		if (stock->fourth_player == 0)
			stock->fourth_player = 2;
	}
	(*tmp)->player = stock->nb_player;
	return (1);
}

int				add_nb_player(t_corewar *stock, t_champion **tmp)
{
	if (stock->nb_player > 0)
		fix_nb_player(stock, tmp);
	else
		find_nb_player(stock, tmp);
	fill_nb_player(stock);
	return (1);
}