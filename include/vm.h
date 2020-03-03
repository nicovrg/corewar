/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 00:07:02 by nicolasv          #+#    #+#             */
/*   Updated: 2020/02/11 01:27:46 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

#include <unistd.h>

# define ERR_CHAMPS_NB "Too many champions"
# define ERR_FILE_HEADER "Header of the file is invalid"
# define ERR_MALLOC "malloc error"
# define ERR_OPEN_FILE "file doesn't exist"
# define ERR_VM_NB_PLAYERS "Corewar takes a number between 1 and 4 after flag -n"
# define ERR_VM_NUMBERS "Corewar takes a number in argument after flags -dump and -n"
# define ERR_VM_USAGE "Usage:  ./corewar [-dump nbr_cycles] [[-n number] champion1.cor]"
# define ERR_VM_NB_PLAYERS_EXCEED "-n number exceed the total number of champions"

# define HEADER_SIZE 2192
# define HEADER_SIZE 2192
# define INSTRUCTION_SECTION_START 2192
# define BYTE_AFTER_PADDING 136
# define MAGIC_NUMBER_PT_1 0
# define MAGIC_NUMBER_PT_2 4294967274
# define MAGIC_NUMBER_PT_3 4294967171
# define MAGIC_NUMBER_PT_4 4294967283


typedef enum		e_instructions_list 
{
	INST_ERROR,
	INST_LIVE,
	INST_LD,
	INST_ST,
	INST_ADD,
	INST_SUB,
	INST_AND,
	INST_OR,
	INST_XOR,
	INST_ZJMP,
	INST_LDI,
	INST_STI,
	INST_FORK,
	INST_LLD,
	INST_LLDI,
	INST_LFORK,
	INST_AFF,
	INST_NB,
}					t_instructions_list;

typedef enum		e_instructions_states 
{
	INST_STATE_ERROR,
	INST_STATE_PARSING_OPCODE,
	INST_STATE_LOADING_OPCODE,
	INST_STATE_PARSING_ENCODED_BYTE,
	INST_STATE_MATCHING_ENCODED_BYTE,
	INST_STATE_CHECKING_PARAMETERS,
	INST_STATE_EXECUTING_INSTRCUTION,
	INST_STATE_FINISHED,
	INST_STATE_NUMBER,
}					t_instrcutions_states;

typedef enum		e_header_states
{
	HEADER_ERROR,
	HEADER_PARSING_MAGIC_NB,
	HEADER_PARSING_NAME,
	HEADER_PARSING_INSTRUCTION_SIZE,
	HEADER_PARSING_COMMENT,
	HEADER_PARSING_PADDING,

}					t_header_state;

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

typedef struct			s_instruction
{
	int					opcode;
	char				parameters[3];
	char				*encoded_byte;
	char				p1;
	char				p2;
	char				p3;
}						t_instruction;

// process_parse_arguments.c
int						process_parse_arguments(t_corewar *arena, t_champion **champions, char **argv);

int						add_champions(char *argv, t_corewar *arena, t_champion **champions);
int						add_nb_player(t_corewar *arena, t_champion **champions, t_champion **tmp);
t_champion				*champions_list(t_champion **champions);
int						check_champion_size(char *argv, t_champion **champions);
int						check_flags(char *argv, t_corewar *arena);
int						check_if_number(char *argv);
int						check_instructions_size(char *line, t_header_state *state, int *i, t_champion **tmp);
int						check_player_or_cycles(char *argv, t_corewar *arena);
int						count_champions(t_champion **champions);
int						find_nb_player(t_corewar *arena, t_champion **champions);
int						header_check(t_corewar *arena, char *line, t_champion **champions);
int						introduce_champs(t_champion **champions);
int						vm_free(t_champion **champions);
int						vm_usage(int i);

// Parse_instructions_functions
int						inst_state_error(t_instruction **instruction);
int						inst_state_parsing_opcode(t_instruction **instruction);
int						inst_state_loading_opcode(t_instruction **instruction);
int						inst_state_parsing_encoded_byte(t_instruction **instruction);
int						inst_state_matching_encoded_byte(t_instruction **instruction);
int						inst_state_checking_parameters(t_instruction **instruction);
int						inst_state_executing_instrcution(t_instruction **instruction);
int						inst_state_finished(t_instruction **instruction);

// Instructions : 
int						inst_error(t_instruction **instruction, t_corewar *arena);
int						inst_live(t_instruction **instruction, t_corewar *arena);
int						inst_ld(t_instruction **instruction, t_corewar *arena);
int						inst_st(t_instruction **instruction, t_corewar *arena);
int						inst_add(t_instruction **instruction, t_corewar *arena);
int						inst_sub(t_instruction **instruction, t_corewar *arena);
int						inst_and(t_instruction **instruction, t_corewar *arena);
int						inst_or(t_instruction **instruction, t_corewar *arena);
int						inst_xor(t_instruction **instruction, t_corewar *arena);
int						inst_zjmp(t_instruction **instruction, t_corewar *arena);
int						inst_ldi(t_instruction **instruction, t_corewar *arena);
int						inst_sti(t_instruction **instruction, t_corewar *arena);
int						inst_fork(t_instruction **instruction, t_corewar *arena);
int						inst_lld(t_instruction **instruction, t_corewar *arena);
int						inst_lldi(t_instruction **instruction, t_corewar *arena);
int						inst_lfork(t_instruction **instruction, t_corewar *arena);
int						inst_aff(t_instruction **instruction, t_corewar *arena);

// error.c
int						error_header(int *fd);
void					*error_msg_null(char *error_msg, t_header_state *state);
int						error_msg(char *error_msg, int i, t_header_state *state);
int						vm_error_champion(char *champion, int var, int size);
int						inst_error(t_instruction **instruction, t_corewar *arena);

// helper_lib.c
char					*ft_strndup(const char *s1, ssize_t len);
char					*ft_strjoinf(char *s1, char *s2, size_t rm);
char					*ft_itoa_base(int n, int base);
int						ft_atoi_base(const char *str, int base);

#endif
