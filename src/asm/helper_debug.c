/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_debug.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takoumys <takoumys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 15:32:54 by qgirard           #+#    #+#             */
/*   Updated: 2020/02/26 23:18:30 by takoumys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"
#include "tokens.h"
#include "ft_printf.h"
#include <stdio.h>

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

int		print_code_lines(t_data **data, t_code_line **code_line)
{
	int				i;
	t_code_line		*current_code_line;

	i = 1;
	current_code_line = (*code_line);
	if (!code_line || !(*code_line))
		return (error_msg("code_line is not initialized", 0));
	print_data(data);
	ft_printf("\x1b[1m\x1b[32m/ ======================== START CODE LINE LIST ======================== \\\x1b[0m\n");
	ft_putendl("\n\n");
	while (current_code_line)
	{
		ft_printf("\t\x1b[1m\x1b[36m/ ===================== START CODE LINE NODE %d ===================== \\\x1b[0m\n", i);
		ft_putendl("");
		ft_printf("\t\tline number =\t\t\t\t|%d|\n", current_code_line->nb_line);
		ft_printf("\t\ttoken in line number =\t\t\t|%d|\n", current_code_line->nb_token);
		ft_printf("\t\tline string =\t\t\t\t|\x1b[32m%s\x1b[0m|\n", current_code_line->line);
		ft_putendl("");
		ft_printf("\t\t\x1b[1m\x1b[34m/ ===================== START TOKEN TABLE (%d) ===================== \\\x1b[0m\n\n", i);
		print_tokens(&current_code_line);
		ft_printf("\t\t\x1b[1m\x1b[34m\\ ======================== END TOKEN TABLE ======================== /\t\t\x1b[0m\n\n");
		ft_printf("\t\taddress to current node =\t\t|%p|\n", current_code_line);
		ft_printf("\t\taddress to following node =\t\t|%p|\n", current_code_line->next);
		ft_putendl("");
		ft_printf("\t\x1b[1m\x1b[36m\\ ======================= END CODE LINE  NODE ======================= /\x1b[0m\n\n");
		current_code_line = current_code_line->next;
		i++;
	}
	ft_putendl("");
	ft_printf("\x1b[1m\x1b[32m\\ ======================== ENDCODE LINE LIST ======================== /\t\t\x1b[0m\n");
	return (1);
}

int		print_token(int length, char *str)
{
	int i;

	i = 0;
	while (str[i] && i < length)
	{
		ft_putchar(str[i]);
		i++;
	}
	return (1);
}

int		print_tokens(t_code_line **current_code_line)
{
	int			i;
	t_token		*current_token;
	
	i = 0;
	if (!current_code_line || !(*current_code_line) || !(*current_code_line)->token)
		return (error_msg("code_line is not initialized", 0));
	current_token = (*current_code_line)->token;
	while (current_token)
	{
		ft_printf("token number %d\n", i);
		ft_printf("\t\t\ttoken =\t\t\t\t\t|");
		print_token(current_token->length, current_token->code_line->line + current_token->position);
		ft_printf("|\n");
		ft_printf("\t\t\tToken number :\t\t\t|%d|\n", current_token->token_nb);
		ft_printf("\t\t\ttype =\t\t\t\t\t|%d|\n", current_token->type);
		ft_printf("\t\t\tposition =\t\t\t\t|%d|\n", current_token->position);
		ft_printf("\t\t\tlength =\t\t\t\t|%d|\n", current_token->length);
		ft_printf("\t\t\tcode_line parent node address =\t\t|%p|\n", current_token->code_line);
		ft_printf("\t\t\tunion structure address =\t\t|%p|\n", current_token->values);
		ft_printf("\t\t\tnext token address =\t\t\t|%p|\n", current_token->next);
		ft_printf("\n");
		current_token = current_token->next;
		i++;
	}
	return (1);
}

void	print_labels(t_data *data)
{
	int		i;
	t_label	*current_label;

	i = 0;
	current_label = data->label_list;
	while (current_label)
	{
		ft_printf("==== Label n : %d ====\n", i);
		ft_printf("Lexeme -> |%s|\n", current_label->lexeme);
		current_label = current_label->next;
		i++;
	}
}