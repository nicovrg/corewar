/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_debug.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 15:32:54 by qgirard           #+#    #+#             */
/*   Updated: 2020/02/01 04:20:25 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"
#include "ft_printf.h"

int		print_data(t_data **data)
{
	if (!data || !(*data))
		return (error_msg("data is not initialized", 0));
	ft_printf("\x1b[1m\x1b[31m/ ======================== START DATA STRUCTURE ======================== \\\x1b[0m\n");
	ft_putendl("");
	ft_printf("\tindex_name =\t\t%d\n", (*data)->name_line);
	ft_printf("\tindex_comment =\t\t%d\n", (*data)->comment_line);
	ft_printf("\t.name =\t\t\t|%s|\n", (*data)->name);
	ft_printf("\t.comment =\t\t|%s|\n", (*data)->comment);
	ft_printf("\tindex_line =\t\t%d\n", (*data)->index_line);
	ft_putendl("");
	ft_printf("\x1b[1m\x1b[31m\\ ======================== END DATA STRUCTURE ======================== /\t\t\x1b[0m\n");
	ft_putendl("\n");
	return (1);
}

int		print_code_line(t_data **data, t_code_line **code_line)
{
	int				i;
	t_code_line		*tmp_code_line;

	i = 1;
	tmp_code_line = (*code_line);
	if (!code_line || !(*code_line))
		return (error_msg("code_line is not initialized", 0));
	print_data(data);
	ft_printf("\x1b[1m\x1b[32m/ ======================== START CODE LINE LIST ======================== \\\x1b[0m\n");
	ft_putendl("\n\n");
	while (tmp_code_line)
	{
		ft_printf("\t\x1b[1m\x1b[36m/ ===================== START CODE LINE NODE %d ===================== \\\x1b[0m\n", i);
		ft_putendl("");
		ft_printf("\t\tline number =\t\t\t\t%d\n", tmp_code_line->nb_line);
		ft_printf("\t\tline string =\t\t\t\t|\x1b[32m%s\x1b[0m|\n", tmp_code_line->line);
		ft_putendl("");
		ft_printf("\t\t\x1b[1m\x1b[34m/ ===================== START TOKEN TABLE (%d) ===================== \\\x1b[0m\n", i);
		print_token(code_line);
		ft_printf("\t\t\x1b[1m\x1b[34m\\ ======================== END TOKEN TABLE ======================== /\t\t\x1b[0m\n\n");
		ft_printf("\t\taddress to current node =\t\t|%p|\n", tmp_code_line);
		ft_printf("\t\taddress to following node =\t\t|%p|\n", tmp_code_line->next);
		ft_putendl("");
		ft_printf("\t\x1b[1m\x1b[36m\\ ======================= END CODE LINE  NODE ======================= /\x1b[0m\n\n");
		tmp_code_line = tmp_code_line->next;
		i++;
	}
	ft_putendl("");
	ft_printf("\x1b[1m\x1b[32m\\ ======================== ENDCODE LINE LIST ======================== /\t\t\x1b[0m\n");
	return (1);
}

int		print_token(t_code_line **code_line)
{
	(void)code_line;
	// int i;
	
	// i = 0;
	// if (!code_line || !(*code_line) || !(*code_line)->token)
	// 	return (error_msg("code_line is not initialized", 0));
	// while (i < (*code_line)->nb_token)
	// {
	// 	// ligne com parce aue ça use une var qu'on utilise plus
	// 	//  ft_printf("\t\t\tlexeme =\t\t\t|%s|\n", (*code_line)->token[i]->lexeme);
	// 	i++;
	// }
	return (1);
}
