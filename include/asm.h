/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasv <nicolasv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 01:21:58 by nivergne          #+#    #+#             */
/*   Updated: 2020/01/25 01:34:48 by nicolasv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# define ERR_MAIN_NB_PARAMETERS "error in main - asm takes only one file as parameter"
# define ERR_MAIN_FILE_TYPE "error in main - not a valid file, the file should be a .s"
# define ERR_MAIN_OPEN_FILE "error in main - file doesn't exist"

# define ERR_LEXER_NODE_CREATE "error in lexer - could not create new node"

# define COMMENT_CHAR '#'

typedef	 struct			s_data
{
	char				*name;
	char				*comment;
	int					index_line;
	int					name_line;
	int					comment_line;
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

int						error_msg(char *error_msg, int i);
int						vm_usage(int i);

#endif
