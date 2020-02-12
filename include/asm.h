/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasv <nicolasv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 01:21:58 by nivergne          #+#    #+#             */
/*   Updated: 2020/02/12 20:04:36 by nicolasv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include <stdlib.h>
# include <string.h>

# define ERR_MAIN_NB_PARAMETERS "error in main - asm takes only one file as parameter"
# define ERR_MAIN_FILE_TYPE "error in main - not a valid file, the file should be a .s"
# define ERR_MAIN_OPEN_FILE "error in main - file doesn't exist"

# define ERR_LEXER_NODE_CREATE "error in lexer - could not create new node"

typedef enum			e_token_errors
{
	NO_ERROR,
	UNKNOWN_TOKEN,
}						t_token_errors;

typedef enum			e_line_errors
{
	NO_LINE_ERROR,
	LINE_ERROR_LEXICAL,
	LINE_ERROR_SYNTAX,
	LINE_ERROR_BOTH,
	
}						t_line_errors;

typedef enum			e_token_type
{
	TOKEN_TYPE_UNDEFINED,					// 0
	TOKEN_TYPE_SEPARATOR,					// 1
	TOKEN_TYPE_LABEL,						// 2
	TOKEN_TYPE_INSTRUCTION,					// 3
	TOKEN_TYPE_DIRECT,						// 4
	TOKEN_TYPE_REGISTER,					// 5
	TOKEN_TYPE_INDIRECT,					// 6
	TOKEN_TYPE_DIRECT_LABEL_CALL,			// 7
	TOKEN_TYPE_INDIRECT_LABEL_CALL,			// 8
	TOKEN_TYPE_UNKNOWN,						// 9
	NB_TOKEN_TYPE,							// 10
}						t_token_type;

typedef	 struct			s_data
{
	int					errors;
	int					name_line;
	int					index_line;
	int					comment_line;
	char				*name;
	char				*comment;
}						t_data;

typedef struct			s_token
{
	int					type;
	int					length;
	int					error;
	int					position;
	int					token_nb;
	struct s_code_line	*code_line; 
	union u_type		*values;
	struct s_token		*next; 
}						t_token;

typedef struct			s_code_line
{
	int					errors;
	int					nb_line;
	int					nb_token;
	char				*line;
	struct s_token		*token; 
	struct s_code_line	*next; 
}						t_code_line;



/* main.c */

/* lexer.c */
int						lexer(int fd, t_data **data, t_code_line **code_line);

/* error_mde */
void					error_mode(t_code_line **c_line);

/* get_tokens_from_current_line.c */
int						get_tokens_from_current_line(t_code_line **c_line, char *line);

/* determine_token_type_and_length.c */
void					determine_token_type_and_length(t_token *token);
int						(*g_token_type_determination_func_array[NB_TOKEN_TYPE])(t_token *);

/* determine_token_type_one.c */
int						is_direct(t_token *token);
int						is_indirect(t_token *token);
int						is_register(t_token *token);
/* determine_token_type_two.c */
int						is_instructions(t_token *token);
int						is_separator(t_token *token);
int						is_unknown(t_token *token);

/* determine_token_type_three.c */
int						is_label(t_token *token);
int						is_direct_label_call(t_token *token);
int						is_indirect_label_call(t_token *token);

/* helper_error.c */
int						error_msg(char *error_msg, int i);
int						asm_usage(int i);
int						error_while_gnl(char **line, char *error_msg);

/* helper_debug.c */
int						print_data(t_data **data);
int						print_code_lines(t_data **data, t_code_line **lexer);
int						print_tokens(t_code_line **lexer);
int						print_token(int length, char *str);

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

#endif
