/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takoumys <takoumys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 15:32:54 by qgirard           #+#    #+#             */
/*   Updated: 2020/02/28 21:14:43 by takoumys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"

int		error_syntax_token(t_token *token, int	error_syntax_token, int error_code)
{
	token->error = error_syntax_token;
	return (error_code);
}

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
