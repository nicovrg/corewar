/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_mode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 02:29:58 by amamy             #+#    #+#             */
/*   Updated: 2020/02/08 03:46:03 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"
#include "ft_printf.h"

static void	read_errors_in_line(t_token *token, char **error_table)
{
	while (token)
	{
		if (token->error)
		{	
			ft_printf("\t- %s : ", error_table[token->error]);
			ft_putstrn(&token->code_line->line[token->position], token->length);
			ft_printf("\n");
		}
		token = token->next;
	}
}

static void	loading_error_table(char **error_table)
{
	error_table[1] = ft_strdup("Unknow token");
}

int	error_mode(t_code_line **c_line)
{
	t_code_line	*tmp;
	char *error_table[2];

	tmp = (*c_line);
	loading_error_table(error_table);
	while (tmp)
	{
		if (tmp->errors)
		{
			ft_printf("line %d : ", tmp->nb_line);
			ft_printf("%s\n", tmp->line);
			if (tmp->errors == LINE_ERROR_LEXICAL)
				ft_printf("Lexical error(s) :\n");
			else if (tmp->errors == LINE_ERROR_SYNTAX)
				ft_printf("Syntax error(s) :\n");
			else if (tmp->errors == LINE_ERROR_BOTH)
				ft_printf("Lexical and Syntax errors :\n");
			read_errors_in_line(tmp->token, error_table);
			ft_printf("\n%s\n\n", "=========");
		}
		tmp = tmp->next;
	}
	return (1);
}