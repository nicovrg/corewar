/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 00:07:02 by nicolasv          #+#    #+#             */
/*   Updated: 2020/02/10 04:53:04 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

#include <unistd.h>
# include "op.h"

# define ERR_CHAMPS_NB "Too many champions"
# define ERR_FILE_HEADER "Header of the file is invalid"
# define ERR_MALLOC "malloc error"
# define ERR_OPEN_FILE "file doesn't exist"
# define ERR_VM_NB_PLAYERS "Corewar takes a number between 1 and 4 after flag -n"
# define ERR_VM_NUMBERS "Corewar takes a number in argument after flags -dump and -n"
# define ERR_VM_USAGE "Usage:  ./corewar [-dump nbr_cycles] [[-n number] champion1.cor]"
# define ERR_VM_NB_PLAYERS_EXCEED "-n number exceed the total number of champions"

# define HEADER_SIZE 2192
# define INSTRUCTION_SECTION_START 2192
# define BYTE_AFTER_PADDING 136
# define MAGIC_NUMBER_PT_1 0
# define MAGIC_NUMBER_PT_2 4294967274
# define MAGIC_NUMBER_PT_3 4294967171
# define MAGIC_NUMBER_PT_4 4294967283

typedef enum		e_header
{
	PARSING_MAGIC_NB,
	PARSING_NAME,
	PARSING_INSTRUCTION_SIZE,
	PARSING_COMMENT,
	PARSING_PADDING,
	ERROR,

}					t_header;

typedef struct		s_champion
{
	unsigned long		size;
	int					player;
	char				*name;
	char				*comment;
	char				*instructions;
	struct s_champion	*next;
}					t_champion;

typedef struct			s_corewar
{
	int					first_player;
	int					second_player;
	int					third_player;
	int					fourth_player;
	int					n_option;
	int					dump_option;
	long				dump_cycles;
	int					nb_player;
	struct	s_champion	*champs;
}						t_corewar;


// process_parse_arguments.c
int						process_parse_arguments(t_corewar *stock, t_champion **champions, char **argv);

int						add_champions(char *argv, t_corewar *stock, t_champion **champions);
int						add_nb_player(t_corewar *stock, t_champion **champions, t_champion **tmp);
t_champion				*champions_list(t_champion **champions);
int						check_champion_size(char *argv, t_champion **champions);
int						check_flags(char *argv, t_corewar *stock);
int						check_if_number(char *argv);
int						check_instructions_size(char *line, t_header *state,
						int *i, t_champion **tmp);
int						check_player_or_cycles(char *argv, t_corewar *stock);
int						count_champions(t_champion **champions);
int						find_nb_player(t_corewar *stock, t_champion **champions);
int						header_check(t_corewar *stock, char *line, t_champion **champions);
int						introduce_champs(t_champion **champions);
int						vm_free(t_champion **champions);
int						vm_usage(int i);

// error.c
int						error_header(int *fd);
void					*error_msg_null(char *error_msg, t_header *state);
int						error_msg(char *error_msg, int i, t_header *state);
int						vm_error_champion(char *champion, int var, int size);

// helper_lib.c
char					*ft_strndup(const char *s1, ssize_t len);
char					*ft_strjoinf(char *s1, char *s2, size_t rm);
char					*ft_itoa_base(int n, int base);
int						ft_atoi_base(const char *str, int base);

#endif
