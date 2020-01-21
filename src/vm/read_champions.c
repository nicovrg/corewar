/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_champions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 16:19:15 by qgirard           #+#    #+#             */
/*   Updated: 2020/01/22 00:48:49 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include "libft.h"

int		read_champions(char *argv, t_corewar *stock)
{
	int			fd;
	char		*line;

	fd = 0;
	if (argv && (fd = open(argv, O_RDONLY)) == -1)
		return (error_msg(ERR_OPEN_FILE, 0));
	while (get_next_line(fd, &line) == 1)
	{
		ft_putendl(line);
		ft_strdel(&line);
	}
	close(fd);
	stock->n_option = 0;
	stock->nb_player = 0;
	return (1);
}