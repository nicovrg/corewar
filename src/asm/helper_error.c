/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takoumys <takoumys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 15:32:54 by qgirard           #+#    #+#             */
/*   Updated: 2020/03/01 01:54:19 by takoumys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"
#include "ft_printf.h"

static void	report_error(t_token *token)
{
	t_code_line *line;

	line = token->code_line;
		ft_printf("%s\n", "============== Laaaa");
	if (token->error && line->errors == LINE_ERROR_LEXICAL)
	{
		ft_printf("%s\n", "zzzzzzzzzzzzzzzzzzzzzLaaaa");
		line->errors = line->errors + LINE_ERROR_SYNTAX;
	}
	else if(token->error)
	{
		ft_printf("%s\n", "Liiii*******************************");
		line->errors = LINE_ERROR_SYNTAX;
	}
}

int		error_code_line(t_code_line *line, int error_syntax_token, int error_code)
{
	ft_putendl("coucou");
	line->errors = line->errors + error_syntax_token;
	return (error_code);
}

int		error_syntax_token(t_token *token, int error_syntax_token, int error_code)
{
	if (token->type == TOKEN_TYPE_SEPARATOR)
		token->error = MISS_PLACED_SEPARATOR;
	else
		token->error = error_syntax_token;
	report_error(token);
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
