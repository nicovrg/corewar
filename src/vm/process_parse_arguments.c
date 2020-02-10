/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_parse_arguments.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 03:55:12 by amamy             #+#    #+#             */
/*   Updated: 2020/02/10 04:35:33 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include "libft.h"

/*
** ==================== parse_args ====================
** parse args to know which kind of arguments we have
** and also allows to check errors
*/

static int		parse_args(char *argv, t_corewar **stock, t_champion **champions)
{
	if (argv && argv[0] != '-' && !ft_isdigit(argv[0])
	&& (!ft_strrchr(argv, '.') || ft_strcmp(ft_strrchr(argv, '.'), ".cor")))
		return (vm_error_champion(argv, 1, 0));
	if (argv[0] == '-')
	{
		if (!check_flags(argv, *stock))
			return (error_msg(ERR_VM_USAGE, 0, NULL));
	}
	else if (check_if_number(argv))
	{
		if (!check_player_or_cycles(argv, *stock))
			return (0);
	}
	else
	{
		if (count_champions(champions) < 4)
		{
			if (!(add_champions(argv, *stock, champions)))
				return (0);
		}
		else
			return (error_msg(ERR_CHAMPS_NB, 0, NULL));
	}
	return (1);
}


int				process_parse_arguments(t_corewar *stock, t_champion **champions, char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (!parse_args(argv[i], &stock, champions))
			return (vm_free(champions));
		if (!check_champion_size(argv[i], champions))
			return (vm_free(champions));
		i++;
	}
	if (!(find_nb_player(stock, champions)))
		return (vm_free(champions));
	return (1);
}