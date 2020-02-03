/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 15:32:54 by qgirard           #+#    #+#             */
/*   Updated: 2020/01/26 21:51:38 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"

int		error_msg(char *error_msg, int error_code)
{
	ft_putendl(error_msg);
	return (error_code);
}


int		error_while_gnl(char **line, char *error_msg)
{
	ft_putendl(error_msg);
	ft_strdel(line);
	return (0);
}

int		asm_usage(int i)
{
	ft_putendl("Usage:  RTFS (READ THE FUCKING SUBJECT)");
	return (i);
}
