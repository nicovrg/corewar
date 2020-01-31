/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 01:21:58 by nivergne          #+#    #+#             */
/*   Updated: 2020/01/30 23:51:55 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include <stdlib.h>
# include <string.h>
// # include <unistd.h>
// # include "libft.h"



typedef union					u_token
{
	enum token					type;
	struct s_label				*label;
	struct s_instruction		*instruction;
	struct s_registr			*registr;
	struct s_direct				*direct;
	struct s_indirect			*indirect;
	struct s_label_call			*label_call;
	struct s_unknown			*unknown;
}								t_token;

typedef struct			s_label
{
	char				*lexeme;
	int					position;
	struct s_lexer		*target;
	struct s_lexer		*parent; // unsure
}						t_label;	

typedef struct			s_instruction
{
	char				*lexeme;
	int					position;
	enum token			type;
	union u_token			*arg1;
	union u_token			*arg2;
	union u_token			*arg3;
	struct s_lexer		*parent; // unsure
}						t_instruction;

typedef struct			s_registr
{
	int					reg_nb;
	int					position;
	struct s_lexer		*parent; // unsure
}						t_registr;

typedef struct			s_direct
{
	int					value;
	int					position;
	struct s_lexer		*parent; // unsure
}						t_direct;

typedef struct			s_indirect
{
	int					value;
	int					position;
	struct s_lexer		*parent; // unsure
}						t_indirect;

typedef struct			s_label_call
{
	char				*lexeme;
	int					value;
	int					position;
	struct s_lexer		*parent; // unsure
}						t_label_call;


typedef struct			s_separator
{
	char				*lexeme;
	int					position;
	struct s_lexer		*parent; // unsure
}						t_separator;

typedef struct			s_unknown
{
	char				*lexeme;
	int					position;
	struct s_lexer		*target;
	struct s_lexer		*parent; // unsure
}						t_unknown;

#endif
