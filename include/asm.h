/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takoumys <takoumys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 01:21:58 by nivergne          #+#    #+#             */
/*   Updated: 2020/02/29 23:23:03 by takoumys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include <stdlib.h>
# include <string.h>
# include "op.h"

# define ERR_MAIN_NB_PARAMETERS "error in main - asm takes only one file as parameter"
# define ERR_MAIN_FILE_TYPE "error in main - not a valid file, the file should be a .s"
# define ERR_MAIN_OPEN_FILE "error in main - file doesn't exist"

# define ERR_LEXER_NODE_CREATE "error in lexer - could not create new node"

# define TO_PROCESS 100

typedef enum			e_token_errors
{
	NO_ERROR,
	UNKNOWN_TOKEN,
	MEMORY_ALLOCATION_ERROR,
	INVALID_REGISTER,
	BAD_PARAMETER,
	NOT_ARGUMENT_TYPE,
	UNDECLARED_LABEL_CALL,
	TOKEN_ERRORS_NUMBER,
}						t_token_errors;

typedef enum			e_line_errors
{
	NO_LINE_ERROR,
	LINE_ERROR_LEXICAL,
	LINE_ERROR_SYNTAX,
	LINE_ERROR_BOTH,
}						t_line_errors;

typedef enum			e_parse_token_args
{
	PARSE_TOKEN_REGISTER,
	PARSE_TOKEN_INDIRECT,
	PARSE_TOKEN_DIRECT,
	PARSE_TOKEN_LABEL_CALL,
	ERROR_PARSE_TOKEN,
	PARSE_TOKEN_STATES_NUMBER,
	
}						t_parse_token__args;

typedef enum			e_token_type
{
	TOKEN_TYPE_UNDEFINED,		// 0
	TOKEN_TYPE_SEPARATOR,		// 1
	TOKEN_TYPE_LABEL,			// 2
	TOKEN_TYPE_INSTRUCTION,		// 3
	TOKEN_TYPE_DIRECT,			// 4
	TOKEN_TYPE_REGISTER,		// 5
	TOKEN_TYPE_INDIRECT,		// 6
	TOKEN_TYPE_LABEL_CALL,		// 7
	TOKEN_TYPE_UNKNOWN,			// 8
	LABEL_CALL_TYPE_DIRECT,		// 9
	LABEL_CALL_TYPE_INDIRECT,	// 10
	NB_TOKEN_TYPE,				// 11
}						t_token_type;

typedef	 struct			s_data
{
	int					errors;
	int					name_line;
	int					index_line;
	int					comment_line;
	char				*name;
	char				*comment;
	t_op				*op_tab;
	struct s_label		*label_list;
	struct s_label		*label_calls;
}						t_data;

typedef struct			s_token
{
	int					type;
	int					length;
	int					error;
	int					position;
	int					token_nb;
	int					mem_address;
	struct s_code_line	*code_line; 
	union u_type		*values;
	struct s_token		*next;  
}						t_token;

typedef struct			s_code_line
{
	char			*label;
	int					errors;
	int					op_code;
	int					nb_line;
	int					nb_token;
	int					mem_address;
	int					instruction_size;
	char				*line;
	struct s_token		*token; 
	struct s_token		**tokens; 
	struct s_code_line	*next; 
}						t_code_line;

/* main.c */

/* lexer.c */
int						lexer(int fd, t_data **data, t_code_line **code_line);

/* parser.c */
int						parser(t_data **data, t_code_line **code_line);
int						parse_label_declarations(t_data *data, t_code_line *code_line);

t_token					*(*g_parse_parameters_func_array[PARSE_TOKEN_STATES_NUMBER])(t_data *, t_code_line *, t_token *, int *);
/* is_label_declaration.c */
int						is_label_declaration(t_code_line *code_line);

/* is_valid_instruction.c */
int						is_valid_instruction(t_data *data, t_code_line *code_line, int current_byte);
/* parse_instruction.c */
int						parse_instruction(t_data *data, t_code_line *code_line, int inst_position, int current_byte[1]);

/* label_functions.c*/
int						is_only_label(t_code_line *code_line);
int						is_valid_label(t_code_line *code_line);
void					labels_calls_computing(t_data *data, t_code_line *code_line);
int						check_label_call_type(t_token *label_call, int is_this_type);

/* get_tokens_from_current_line.c */
int						get_tokens_from_current_line(t_code_line **c_line, char *line);

/* determine_token_type_and_length.c */
void					determine_token_type_and_length(t_token *token);
int						(*g_token_type_determination_func_array[NB_TOKEN_TYPE])(t_token *);

/* determine_token_type_one.c */
int						is_label_char(char c);
int						is_label(t_token *token);
int						is_direct(t_token *token);
int						is_indirect(t_token *token);
int						is_register(t_token *token);
/* determine_token_type_two.c */
int						is_instructions(t_token *token);
int						is_separator(t_token *token);
int						is_unknown(t_token *token);

/* determine_token_type_three.c */
// int						is_direct_label_call(t_token *token);
// int						is_indirect_label_call(t_token *token);
int						is_label_call(t_token *token);

/* error_mode */
void					error_mode(t_code_line **c_line);

/* helper_error.c */
int						error_msg(char *error_msg, int i);
int						asm_usage(int i);
int						error_while_gnl(char **line, char *error_msg);
int						error_syntax_token(t_token *token, int	error_syntax_token, int error_code);

/* helper_debug.c */
int						print_data(t_data **data);
int						print_code_lines(t_data **data, t_code_line **lexer);
int						print_tokens(t_code_line **lexer);
int						print_token(int length, char *str);
void					print_labels(t_data *data);

/* get_header_info_one.c */
int						is_whitespace(char c);
int						is_dirty(char *str);
int						get_string_child(t_data **data, char *str, int mode, int i);
int						get_string(t_data **data, char *str, int mode);

/* get_header_info_two.c */
int						get_name(int i, char *line, t_data **data);
int						get_comment(int i, char *line, t_data **data);
int						little_parsing(char *line, t_data **data);
int						header(int fd, t_data **data);

/* helper_lib.c */
int						is_comma(char c);
int						is_comment_char(char c);
int						is_number(char *num);
int						is_whitespace(char c);
void					ft_putstrn(char const *s, int size);	
char					*ft_strndup(const char *s1, ssize_t len);
int						is_str_whitespace_or_comment(char *str);

/* helper_free.c */
int						free_data(t_data **data);
int						free_code_line(t_code_line **t_code_line);
void					free_token(t_token *token);
int						free_token_list(t_token **token);
int						free_all(t_data **data, t_code_line **code_line);

/* helper_free_token_values.c */
void 		(*g_token_free_values_func_array[NB_TOKEN_TYPE])(t_token *);

#endif
