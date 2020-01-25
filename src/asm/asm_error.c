/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasv <nicolasv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 15:32:54 by qgirard           #+#    #+#             */
/*   Updated: 2020/01/25 04:15:16 by nicolasv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"
#include "ft_printf.h"

int		error_msg(char *error_msg, int error_code)
{
	ft_putendl(error_msg);
	return (error_code);
}

int		asm_usage(int i)
{
	ft_putendl("Usage:  RTFS (READ THE FUCKING SUBJECT)");
	return (i);
}

int		print_data(t_data **data)
{
	if (!data || !(*data))
		return(error_msg("data is not initialized", 0));
	ft_printf(" / ============ START DATA STRUCTURE ============ \\\n");
	ft_printf("\t.name =\t\t|%s|\n", (*data)->name);
	ft_printf("\t.comment =\t\t|%s|\n", (*data)->comment);
	ft_printf("\tindex_line =\t\t|%d|\n", (*data)->index_line);
	ft_printf("\tindex_name =\t\t|%d|\n", (*data)->name_line);
	ft_printf("\tindex_comment =\t\t|%d|\n", (*data)->comment_line);
	ft_printf(" \\ ============ END DATA STRUCTURE ============ /\t\t\n");
	return (1);
}

// int		print_token(t_token **token)
// {

// }

// int		print_lexer(t_lexer **lexer)
// {
	
// }