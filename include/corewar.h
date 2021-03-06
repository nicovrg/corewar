/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 00:07:02 by nicolasv          #+#    #+#             */
/*   Updated: 2019/11/07 12:33:30 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# define ERR_NB_PARAMETERS "asm takes only one file as parameter"
# define ERR_FILE_TYPE "not a valid file, the file should be a .s"
# define ERR_OPEN_FILE "file doesn't exist"

int				error_msg(char *error_msg, int i);
int				vm_usage(int i);

typedef struct	s_champion
{
	int		size;
	int		player;
	char	*champion;
}				t_champion;

#endif
