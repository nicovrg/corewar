/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 00:07:02 by nicolasv          #+#    #+#             */
/*   Updated: 2020/01/21 01:24:46 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# define ERR_NB_PARAMETERS "asm takes only one file as parameter"
# define ERR_FILE_TYPE "not a valid file, the file should be a .s"
# define ERR_OPEN_FILE "file doesn't exist"

/* vm_main.c */

int				error_msg(char *error_msg, int i);
int				vm_usage(int i);

typedef struct	s_champion
{
	int		size;
	int		player;
	char	*champion;
}				t_champion;

#endif
