/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 01:21:58 by nivergne          #+#    #+#             */
/*   Updated: 2020/01/23 00:14:08 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# define ERR_MAIN_NB_PARAMETERS "error in main - asm takes only one file as parameter"
# define ERR_MAIN_FILE_TYPE "error in main - not a valid file, the file should be a .s"
# define ERR_MAIN_OPEN_FILE "error in main - file doesn't exist"

# define ERR_LEXER_NODE_CREATE "error in lexer - could not create new node"

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
	struct s_line		*next;
}						t_lexer;


/* asm_main.c */


int						error_msg(char *error_msg, int i);
int						vm_usage(int i);

#endif
