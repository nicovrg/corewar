/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 01:21:58 by nivergne          #+#    #+#             */
/*   Updated: 2020/01/22 06:30:44 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# define ERR_NB_PARAMETERS "asm takes only one file as parameter"
# define ERR_FILE_TYPE "not a valid file, the file should be a .s"
# define ERR_OPEN_FILE "file doesn't exist"

typedef struct			s_token
{
	int					value;
	char				*lexme;
	struct s_token		*next;
}						t_token;

typedef struct			s_line
{
	int					nb_line;
	char				*line;
	char				*label;
	struct s_token		*token;
	struct s_line		*next;
}						t_line;


/* asm_main.c */


int						error_msg(char *error_msg, int i);
int						vm_usage(int i);

#endif
