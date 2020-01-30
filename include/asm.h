/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasv <nicolasv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 01:21:58 by nivergne          #+#    #+#             */
/*   Updated: 2020/01/30 03:52:35 by nicolasv         ###   ########.fr       */
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
	int					errors;
	int					name_line;
	int					index_line;
	int					comment_line;
	char				*name;
	char				*comment;
}						t_data;

typedef struct			s_token
{
	int					value;
	char				*lexeme;
	struct s_lexer		*parent; // unsure
}						t_token;

typedef struct			s_lexer
{
	int					nb_line;
	int					token_nb;
	char				*line;
	char				*label; //  token * ?
	struct s_token		**token;
	struct s_lexer		*next;
}						t_lexer;

enum					token
{
	label,
	instruction,
	direct,
	registr,
	indirect,
	label_call,
	separator,
	unknown,
	eol
};

/* asm_main.c */

/* asm_lexer.c */
// static int				is_empty(char *str);
// static t_lexer			**new_lexer_node(t_lexer **lex);
int						lexer(int fd, t_data **data, t_lexer **lex);

/* asm_tokeniser.c */
int						new_token_node(t_token **token);
int						tokenizer(t_lexer *lex, t_data *data);

/* asm_tokeniser_states-functions.c */
int						is_label(t_lexer*lex, t_data *data, int current_token);
int						is_instructions(t_lexer *lex, t_data *data, int current_token);
int						is_direct(t_lexer *lex, t_data *data, int current_token);
int						is_registr(t_lexer *lex, t_data *data, int current_token);
int						is_indirect(t_lexer *lex, t_data *data, int current_token);
int						is_label_call(t_lexer *lex, t_data *data, int current_token);
int						is_separator(t_lexer *lex, t_data *data, int current_token);
int						is_unknown(t_lexer *lex, t_data *data, int current_token);

/* asm_error.c */
int						error_msg(char *error_msg, int i);
int						asm_usage(int i);
int						error_while_gnl(char **line, char *error_msg);

/* asm_debug.c */
int						print_data(t_data **data);
int						print_lexer(t_data **data, t_lexer **lexer);
int						print_token(t_lexer **lexer);

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
// static int				allocate_token(t_lexer **tmp_lex, char *line);
int						splitter(t_lexer **tmp_lex, char *line);


#endif
