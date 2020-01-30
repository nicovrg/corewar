/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_debug.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 15:32:54 by qgirard           #+#    #+#             */
/*   Updated: 2020/01/30 23:59:01 by amamy            ###   ########.fr       */
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

int		print_lexer(t_data **data, t_lexer **lexer)
{
	int			i;
	t_lexer		*tmp_lexer;

	i = 1;
	tmp_lexer = (*lexer);
	if (!lexer || !(*lexer))
		return (error_msg("lexer is not initialized", 0));
	print_data(data);
	ft_printf("\x1b[1m\x1b[32m/ ======================== START LEXER LIST ======================== \\\x1b[0m\n");
	ft_putendl("\n\n");
	while (tmp_lexer)
	{
		ft_printf("\t\x1b[1m\x1b[36m/ ======================= START LEXER NODE %d ======================= \\\x1b[0m\n", i);
		ft_putendl("");
		ft_printf("\t\tline number =\t\t\t\t%d\n", tmp_lexer->nb_line);
		ft_printf("\t\tline string =\t\t\t\t|\x1b[32m%s\x1b[0m|\n", tmp_lexer->line);
		ft_printf("\t\tline label =\t\t\t\t|%s|\n", tmp_lexer->label);
		ft_putendl("");
		ft_printf("\t\t\x1b[1m\x1b[34m/ ======================= START TOKEN TABLE (%d) ======================= \\\x1b[0m\n", i);
		ft_printf("\t\t\ttoken number =\t\t%d\n", (*lexer)->nb_token);
		print_token(lexer);
		ft_printf("\t\t\x1b[1m\x1b[34m\\ ======================== END TOKEN TABLE ======================== /\t\t\x1b[0m\n\n");
		ft_printf("\t\taddress to current node =\t\t|%p|\n", tmp_lexer);
		ft_printf("\t\taddress to following node =\t\t|%p|\n", tmp_lexer->next);
		ft_putendl("");
		ft_printf("\t\x1b[1m\x1b[36m\\ ======================= END LEXER NODE ======================= /\x1b[0m\n");
		tmp_lexer = tmp_lexer->next;
		i++;
	}
	ft_putendl("");
	ft_printf("\x1b[1m\x1b[32m\\ ======================== END LEXER LIST ======================== /\t\t\x1b[0m\n");
	return (1);
}

int		print_token(t_lexer **lexer)
{
	int i;
	
	i = 0;
	if (!lexer || !(*lexer) || !(*lexer)->token)
		return (error_msg("lexer is not initialized", 0));
	while (i < (*lexer)->nb_token)
	{
		// ligne com parce aue ça use une var qu'on utilise plus
		//  ft_printf("\t\t\tlexeme =\t\t\t|%s|\n", (*lexer)->token[i]->lexeme);
		i++;
	}
	return (1);
}
