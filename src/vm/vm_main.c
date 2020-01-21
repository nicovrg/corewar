/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 15:32:40 by qgirard           #+#    #+#             */
/*   Updated: 2019/11/13 13:34:51 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "libft.h"

int		parse_args(char *argv, t_corewar *stock)
{
	if (argv && argv[0] != '-' && !ft_isdigit(argv[0])
	&& (!ft_strchr(argv, '.') || ft_strcmp(ft_strchr(argv, '.'), ".cor")))
		return (vm_error_champion(argv, 1, 0));
	if (argv[0] == '-')
	{
		if (!check_flags(argv, stock))
			return (error_msg(ERR_VM_USAGE, 0));
	}
	else if (ft_isdigit(argv[0]))
	{
		if (!check_player_or_cycles(argv, stock))
			return (0);
	}
	else
		if (!(read_champions(argv, stock)))
			return (0);
	return (1);
}

/*
** ==================== init_stock ====================
** a remplacer par un ft_bzero de la structure mais a garder
** pour le moment pour une meilleure visibilite
*/

int		init_stock(t_corewar *stock)
{
	stock->first_player = 0;
	stock->second_player = 0;
	stock->third_player = 0;
	stock->last_player = 0;
	stock->dump_option = 0;
	stock->dump_cycles = 0;
	stock->n_option = 0;
	stock->nb_player = 0;
	stock->champs = NULL;
	return (1);
}

int		main(int argc, char **argv)
{
	int			i;
	t_corewar	stock;

	i = 1;
	init_stock(&stock);
	if (argc < 2)
		return (error_msg(ERR_VM_USAGE, 1));
	while (argv[i])
	{
		if (!parse_args(argv[i], &stock))
			return (1);	
		i++;
	}
	return (0);
}