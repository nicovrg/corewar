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

typedef struct	s_champion
{
	int		size;
	int		player;
	char	*champion;
}				t_champion;

/* vm_main.c */
int				parse_args(char *argv, t_champion **champs);

/* vm_error.c */
int				vm_usage(int i);
int				vm_error_champion(char *champion);

/* vm_checks.c */
int				check_nb_player(char *argv);
int				check_flags(char *argv);

/* vm_add_champions.c */
int				add_champions(char *champion);

#endif
