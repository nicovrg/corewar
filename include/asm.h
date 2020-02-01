/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 01:21:58 by nivergne          #+#    #+#             */
/*   Updated: 2020/02/01 04:40:30 by nivergne         ###   ########.fr       */
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

# define LEX_STATES_NB	9

typedef	 struct			s_data
{
	int					errors; // is a flag in case there is a lexical or syntaxic error, might be other ways.
	int					name_line;
	int					index_line;
	int					comment_line;
	char				*name;
	char				*comment;
}						t_data;

typedef struct			s_token
{
	int					type;	//type of token (enum token refered)
	int					position; // token's position in the code line
	struct u_type		*values; // pointe rtoward the match structure
	struct s_token		*next; // pointing the next token
	struct s_code_line	*parent; // pointing to the line it is contained by
}						t_token;

typedef struct			s_code_line
{
	int					nb_line;
	int					nb_token;
	char				*line;
	struct s_token		*token; // we  now point to the first element of a list of tokens
	struct s_code_line	*next; // point to the next code line
}						t_code_line;

enum					token
{
	separator,
	label,
	instruction,
	direct,
	registr,
	indirect,
	label_call,
	unknown,
};

/* asm_main.c */

/* asm_lexer.c */
// static int				is_empty(char *str);
// static t_code_line		**new_lexer_node(t_code_line **lex);
int						lexer(int fd, t_data **data, t_code_line **code_line);

/* asm_tokeniser.c */
int						tokenizer(t_code_line **c_line, char *line);
int						token_machine_gun(t_token **token, char *line);
void					stuff_token_guns();

/* asm_tokeniser_states-functions.c */
int						is_separator(t_token **token, char *src);
int						is_label(t_token **token, char *src);
int						is_instructions(t_token **token, char *src);
int						is_direct(t_token **token, char *src);
int						is_registr(t_token **token, char *src);
int						is_indirect(t_token **token, char *src);
int						is_label_call(t_token **token, char *src);
int						is_unknown(t_token **token, char *src);

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
