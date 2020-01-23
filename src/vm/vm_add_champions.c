/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_add_champions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 03:04:45 by nivergne          #+#    #+#             */
/*   Updated: 2020/01/23 06:25:57 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include "libft.h"

int		error_header(int *fd)
{
	close(*fd);
	return (0);
}

int		add_champions(char *argv, t_corewar *stock, t_champion __unused **champions)
{
	int			fd;
	char		line[HEADER_SIZE];
	// char		line;

	fd = 0;
	if (argv && (fd = open(argv, O_RDONLY)) == -1)
		return (error_msg(ERR_OPEN_FILE, 0));
	// while (read(fd, &line, 1) > 0)
	if (read(fd, &line, HEADER_SIZE) > 0)
	{
		// if (line > 127)
		// 	printf("%3d ", line);
		// else
		// 	printf("%3d ", line);
		if (!(header_check(line, champions)))
			return (error_header(&fd));
	}
	else
	{
		close(fd);
		return (error_msg(ERR_FILE_HEADER, 0)); 
	}
	close(fd);
	stock->n_option = 0;
	stock->nb_player = 0;
	return (1);
}
