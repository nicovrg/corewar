/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 15:32:40 by qgirard           #+#    #+#             */
/*   Updated: 2020/02/10 02:57:13 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include "libft.h"

/*
** ==================== count_champions ====================
** count the number of champions
** it allows to check if we can add more champions
*/

int		count_champions(t_champion **champions)
{
	int			i;
	t_champion	*tmp;

	i = 0;
	tmp = (*champions);
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

/*
** ==================== parse_args ====================
** parse args to know which kind of arguments we have
** and also allows to check errors
*/

int		parse_args(char *argv, t_corewar *stock, t_champion **champions)
{
	if (argv && argv[0] != '-' && !ft_isdigit(argv[0])
	&& (!ft_strrchr(argv, '.') || ft_strcmp(ft_strrchr(argv, '.'), ".cor")))
		return (vm_error_champion(argv, 1, 0));
	if (argv[0] == '-')
	{
		if (!check_flags(argv, stock))
			return (error_msg(ERR_VM_USAGE, 0, NULL));
	}
	else if (check_if_number(argv))
	{
		if (!check_player_or_cycles(argv, stock))
			return (0);
	}
	else
	{
		if (count_champions(champions) < 4)
		{
			if (!(add_champions(argv, stock, champions)))
				return (0);
		}
		else
			return (error_msg(ERR_CHAMPS_NB, 0, NULL));
	}
	return (1);
}

int		main(int argc, char **argv)
{
	int			i;
	t_corewar	stock;
	t_champion	*champions;

	i = 1;
	champions = NULL;
	if (argc < 2)
		return (error_msg(ERR_VM_USAGE, 1, NULL));
	ft_bzero(&stock, sizeof(t_corewar));
	while (argv[i])
	{
		if (!parse_args(argv[i], &stock, &champions))
			return (vm_free(&champions));
		if (!check_champion_size(argv[i], &champions))
			return (vm_free(&champions));
		i++;
	}
	if (!(find_nb_player(&stock, &champions)))
		return (vm_free(&champions));
	introduce_champs(&champions);
	vm_free(&champions);
	return (0);
}
