/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_mode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takoumys <takoumys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 02:29:58 by amamy             #+#    #+#             */
/*   Updated: 2020/03/01 01:57:53 by takoumys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"
#include "ft_printf.h"

static void	free_error_table(char *error_table[TOKEN_ERRORS_NUMBER])
{
	int	i;

	i = 0;
	while (i < TOKEN_ERRORS_NUMBER)
	{
		ft_memdel((void*)&error_table[i]);
		i++;
	}
}

// static void		read_notes()

/*
** ==================== read_errors_in_line ====================
** Go though tokens one by one and displays matching text for error.
*/

static void		read_errors_in_line(t_token *token, char **error_table)
{
	while (token)
	{
		if (token->error)
		{
			ft_printf("\t- %s : |", error_table[token->error]);
			ft_putstrn(&token->code_line->line[token->position], token->length);
			ft_printf("|\n");
		}
		token = token->next;
	}
}

/*
** ==================== loading_error_table ====================
** Loads an array of known errors that are needed to display
** good information on errors.
*/

static void		loading_error_table(char **error_table)
{
	error_table[NO_ERROR] = NULL;
	error_table[UNKNOWN_TOKEN] = ft_strdup("Unknow token");
	error_table[MEMORY_ALLOCATION_ERROR] = ft_strdup("Could not allocate memory");
	error_table[BAD_OP_CODE] = ft_strdup("Unrecognized instruction");
	error_table[INVALID_REGISTER] = ft_strdup("Invalid register number, only exist r1 to r16");
	error_table[WRONG_ARGUMENT_TYPE] = ft_strdup("This instruction does not take this type of parameter");
	error_table[NOT_ARGUMENT_TYPE] = ft_strdup("This is not a valid argument for any instruction");
	error_table[MISSING_SEPARATOR] = ft_strdup("Parameter given to instruction must be separated with a coma ','.");
	error_table[MISS_PLACED_SEPARATOR] = ft_strdup("Coma ',' are only used to separate instruction arguments");
	error_table[UNDECLARED_LABEL_CALL] = ft_strdup("Use of undeclared label");
}

/*
** ==================== error_mode ====================
** Receives the first node of t_code_line list (aka first
** line of code). Reads lines one by one. If the line contains
** errors, displays it and go to next line.
*/

void			error_mode(t_code_line **c_line)
{
	t_code_line	*tmp;
	char		*error_table[TOKEN_ERRORS_NUMBER];

	tmp = (*c_line);
	loading_error_table(error_table);
	ft_printf("%s\n", "=============== ERROR(S) FOUND(S) ===============");
	while (tmp)
	{
		if (tmp->errors)
		{
			ft_printf("\n%s\n", "=========");
			ft_printf("line %d : ", tmp->nb_line);
			ft_printf("|%s|\n\n", tmp->line);
			ft_printf("line error : %d\n", tmp->errors);
			if (tmp->errors == LINE_ERROR_LEXICAL)
				ft_printf("Lexical error(s) :\n");
			else if (tmp->errors == LINE_ERROR_SYNTAX)
				ft_printf("Syntax error(s) :\n");
			else //if (tmp->errors >= LINE_ERROR_BOTH)
				ft_printf("Lexical and Syntax errors :\n");
			read_errors_in_line(tmp->token, error_table);
		}
		tmp = tmp->next;
	}
	free_error_table(error_table);
	ft_printf("\n%s\n", "============ END OF ERROR DISPLAY ============\n");
}
