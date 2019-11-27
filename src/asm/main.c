/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasv <nicolasv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 14:21:47 by qgirard           #+#    #+#             */
/*   Updated: 2019/11/27 03:26:27 by nicolasv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "asm.h"

int		main(int argc, char **argv)
{
	int		fd;

	if (argc != 2)
		return (error_msg(ERR_NB_PARAMETERS, 1));
	else
	{
		if (argv[1] && ft_strchr(argv[1], '.')
		&& ft_strcmp(ft_strchr(argv[1], '.'), ".s"))
			return (error_msg(ERR_FILE_TYPE, 1));
		else if (argv[1] && (fd = open(argv[1], O_RDONLY)) == -1)
			return (error_msg(ERR_OPEN_FILE, 1));
	}
	return (0);
}