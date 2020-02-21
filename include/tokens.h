/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 01:21:58 by nivergne          #+#    #+#             */
/*   Updated: 2020/02/21 09:26:58 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENS_H
# define TOKENS_H

typedef union				u_type
{
	struct s_label			*label;
	struct s_instruction	*instruction;
	struct s_registr		*registr;
	struct s_direct			*direct;
	struct s_indirect		*indirect;
	struct s_label_call		*label_call;
	struct s_unknown		*unknown;
}							t_type;

typedef struct				s_label
{
	char					*lexeme;
	struct s_code_line		*target;
	struct s_label			*next;
}							t_label;

typedef struct				s_instruction
{
	int						type;
	char					*lexeme;
	union token				*arg1;
	union token				*arg2;
	union token				*arg3;
}							t_instruction;

typedef struct				s_registr
{
	int						reg_nb;
}							t_registr;

typedef struct				s_direct
{
	int						value;
}							t_direct;

typedef struct				s_indirect
{
	int						value;
}							t_indirect;

typedef struct				s_label_call
{
	int						type;
	char					*lexeme;
	struct s_code_line		*target;
	struct s_label_call		*next;
	struct s_token			*token;
}							t_label_call;

typedef struct				s_unknown
{
	char					*lexeme;
}							t_unknown;

#endif
