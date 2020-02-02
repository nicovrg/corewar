/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 01:21:58 by nivergne          #+#    #+#             */
/*   Updated: 2020/02/02 06:26:14 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include <stdlib.h>
# include <string.h>
// # include <unistd.h>
// # include "libft.h"

# define ERR_MAIN_NB_PARAMETERS "error in main - asm takes only one file as parameter"
# define ERR_MAIN_FILE_TYPE "error in main - not a valid file, the file should be a .s"
# define ERR_MAIN_OPEN_FILE "error in main - file doesn't exist"

# define ERR_LEXER_NODE_CREATE "error in lexer - could not create new node"

typedef enum			e_token_type
{
	TOKEN_TYPE_UNDEFINED,
	TOKEN_TYPE_SEPARATOR,
	TOKEN_TYPE_LABEL,
	TOKEN_TYPE_INSTRUCTION,
	TOKEN_TYPE_DIRECT,
	TOKEN_TYPE_REGISTR, //TODO: typo
	TOKEN_TYPE_INDIRECT,
	TOKEN_TYPE_LABEL_CALL,
	TOKEN_TYPE_UNKNOWN,
	NB_TOKEN_TYPE,
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
	int					position;
	int					length;
	struct s_token		*next; 
	struct s_code_line	*code_line; 
	struct u_type		*values;
}						t_token;

typedef struct			s_code_line
{
	int					nb_line;
	int					nb_token;
	char				*line;
	struct s_token		*token; 
	struct s_code_line	*next; 
}						t_code_line;


/* asm_main.c */

/* asm_lexer.c */
int						lexer(int fd, t_data **data, t_code_line **code_line);

/* asm_tokeniser.c */
int						tokenizer(t_code_line **c_line, char *line);
void					determine_token_type_and_length(t_token *token);

/* asm_tokeniser_states-functions.c */
int						is_separator(t_token *token);
int						is_label(t_token *token);
int						is_instructions(t_token *token);
int						is_direct(t_token *token);
int						is_registr(t_token *token);
int						is_indirect(t_token *token);
int						is_label_call(t_token *token);
int						is_unknown(t_token *token);

/* asm_error.c */
int						error_msg(char *error_msg, int i);
int						asm_usage(int i);
int						error_while_gnl(char **line, char *error_msg);

/* asm_debug.c */
int						print_data(t_data **data);
int						print_code_line(t_data **data, t_code_line **lexer);
int						print_token(t_code_line **lexer);

/* asm_header_one.c */
int						is_whitespace(char c);
int						is_dirty(char *str);
int						get_string_child(t_data **data, char *str, int mode, int i);
int						get_string(t_data **data, char *str, int mode);

/* asm_header_two.c */
int						get_name(int i, char *line, t_data **data);
int						get_comment(int i, char *line, t_data **data);
int						little_parsing(char *line, t_data **data);
int						header(int fd, t_data **data);

/* asm_lib.c */
int						is_comma(char c);
int						is_comment(char c);
int						is_whitespace(char c);
char					*ft_strndup(const char *s1, ssize_t len);

/* asm_splitter.c */
// static int				count_tokens(char *line);
// static int				allocate_token(t_code_line **tmp_lex, char *line);


#endif
