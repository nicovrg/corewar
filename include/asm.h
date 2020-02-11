/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 01:21:58 by nivergne          #+#    #+#             */
/*   Updated: 2020/02/10 23:50:55 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "op.h"

# define ERR_OPEN_FILE "file doesn't exist"
# define ERR_VM_USAGE "Usage:  ./corewar [-dump nbr_cycles] [[-n number] champion1.cor]"
# define ERR_VM_NUMBERS "Corewar takes a number in argument after flags -dump and -n"
# define ERR_VM_NB_PLAYERS "Corewar takes a number between 1 and 4 after flag -n"

typedef struct		s_champion
{
	int				size;
	int				player;
	char			*champion;
}					t_champion;

typedef struct			s_corewar
{
	int					first_player;
	int					second_player;
	int					third_player;
	int					last_player;
	int					n_option;
	int					dump_option;
	long				dump_cycles;
	int					nb_player;
	struct	s_champion	*champs;
}						t_corewar;

int						add_champions(char *champion, t_corewar *arena);
int						check_flags(char *argv, t_corewar *arena);
int						check_player_or_cycles(char *argv, t_corewar *arena);
int						error_msg(char *error_msg, int i);
int						read_champions(char *argv, t_corewar *arena);
int						vm_error_champion(char *champion, int var, int size);
int						vm_usage(int i);

#endif
