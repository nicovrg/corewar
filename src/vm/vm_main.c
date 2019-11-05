/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 15:32:40 by qgirard           #+#    #+#             */
/*   Updated: 2019/11/05 16:24:35 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "libft.h"

int		main(int argc, char **argv)
{
	int		i;

	i = 1;
	if (argc > 5)
	{
		ft_putendl("Too many champions");
	}
	else
	{
		while (argv[i])
		{
			if (argv[i] && ft_strchr(argv[i], '.')
			&& ft_strcmp(ft_strchr(argv[i], '.'), ".s"))
				return (error_msg(ERR_FILE_TYPE, 1));
		}
	}
	return (0);
}