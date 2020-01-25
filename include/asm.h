/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 01:21:58 by nivergne          #+#    #+#             */
/*   Updated: 2020/01/25 22:48:11 by nivergne         ###   ########.fr       */
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

# define COMMENT_CHAR '#'

typedef	 struct			s_data
{
	int					name_line;
	int					comment_line;
	char				*name;
	char				*comment;
	int					index_line;
}						t_data;

typedef struct			s_token
{
	int					value;
	char				*lexme;
	struct s_token		*next;
}						t_token;

typedef struct			s_lexer
{
	int					nb_line;
	char				*line;
	char				*label;
	struct s_token		*token;
	struct s_lexer		*next;
}						t_lexer;


/* asm_main.c */

/* asm_lexer.c */
int						new_lexer_node(t_lexer **lex, int nb_line);
int						lexer(int fd, t_lexer **lex);

/* asm_token.c */
int						new_token_node(t_token **token);
int						create_tokens(char *line, t_token **token);

/* asm_error.c */
int						error_msg(char *error_msg, int i);
int						asm_usage(int i);
int						print_data(t_data **data);

/* asm_header_one.c */
int						is_comment(char c);
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
char					*ft_strndup(const char *s1, ssize_t len);

/* asm_splitter.c */



#endif
