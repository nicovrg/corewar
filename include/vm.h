/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 00:07:02 by nicolasv          #+#    #+#             */
/*   Updated: 2020/01/22 06:54:23 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# include "op.h"

# define ERR_FILE_HEADER "Header of the file is invalid"
# define ERR_MALLOC "malloc error"
# define ERR_OPEN_FILE "file doesn't exist"
# define ERR_VM_NB_PLAYERS "Corewar takes a number between 1 and 4 after flag -n"
# define ERR_VM_NUMBERS "Corewar takes a number in argument after flags -dump and -n"
# define ERR_VM_USAGE "Usage:  ./corewar [-dump nbr_cycles] [[-n number] champion1.cor]"

# define HEADER_SIZE 2192
# define BYTE_AFTER_PADDING 135
# define MAGIC_NUMBER_PT_1 0
# define MAGIC_NUMBER_PT_2 4294967274
# define MAGIC_NUMBER_PT_3 4294967171
# define MAGIC_NUMBER_PT_4 4294967283

enum header {magic_nb, name, padding1, instructions_size, comment, padding2};

typedef struct		s_champion
{
	unsigned int		size;
	int					player;
	char				*name;
	struct s_champion	*next;
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

int						add_champions(char *argv, t_corewar *stock, t_champion **champions);
t_champion				*champions_list(t_champion **champions);
int						check_flags(char *argv, t_corewar *stock);
int						check_player_or_cycles(char *argv, t_corewar *stock);
int						error_msg(char *error_msg, int i);
int						header_check(char *line, t_champion **champions);
int						vm_error_champion(char *champion, int var, int size);
int						vm_usage(int i);

#endif
