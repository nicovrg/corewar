/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_add_champions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 03:04:45 by nivergne          #+#    #+#             */
/*   Updated: 2020/02/10 02:59:41 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include "libft.h"
#include "ft_printf.h"

/*
** ==================== add_champions ====================
** open the champion file and read it then call function that check if header
** is valid and last check and stock instructions of the champion
*/

int				add_champions(char *argv, t_corewar *stock,
t_champion **champions)
{
	int			fd;
	char		line[HEADER_SIZE + CHAMP_MAX_SIZE];

	fd = 0;
	if (argv && (fd = open(argv, O_RDONLY)) == -1)
		return (error_msg(ERR_OPEN_FILE, 0, NULL));
	int t = CHAMP_MAX_SIZE;
	if ((t = read(fd, &line, (HEADER_SIZE + CHAMP_MAX_SIZE))) > 0)
	{
		if (!(header_check(stock, line, champions)))
			return (error_header(&fd));
	}
	else
	{
		close(fd);
		return (error_msg(ERR_FILE_HEADER, 0, NULL));
	}
	close(fd);
	stock->n_option = 0;
	stock->nb_player = 0;
	return (1);
}
