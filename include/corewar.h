/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 00:07:02 by nicolasv          #+#    #+#             */
/*   Updated: 2019/11/05 14:53:21 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# define ERR_NB_PARAMETERS "asm takes only one file as parameter"
# define ERR_FILE_TYPE "not a valid file, the file should be a .s"
# define ERR_OPEN_FILE "file doesn't exist"

int		error_msg(char *error_msg, int i);

#endif