/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 15:32:40 by qgirard           #+#    #+#             */
/*   Updated: 2019/11/07 12:25:31 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "libft.h"

int		parse_args(char *argv, t_champion **champs)
{
	if (argv && (!ft_strchr(argv, '.')
	|| (ft_strcmp(ft_strchr(argv, '.'), ".cor") && (argv[0] != '-'
	&& !ft_isdigit(argv[0])))))
		return (vm_error_champion(argv));
	else if (argv[0] == '-')
		check_flags(argv);
	else if (ft_isdigit(argv[0]))
		check_nb_player(argv);
	else
		add_champions(argv);
	return (1);
}

int		main(int argc, char **argv)
{
	int			i;
	t_champion	*champs;

	i = 1;
	champs = NULL;
	if (argc < 2)
		return (vm_usage(1));
	while (argv[i])
	{
		if (!parse_args(argv[i], &champs))
			return (1);	
		i++;
	}
	return (0);
}