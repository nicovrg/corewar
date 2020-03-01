/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_instruction.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takoumys <takoumys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 13:18:15 by amamy             #+#    #+#             */
/*   Updated: 2020/03/01 14:58:59 by takoumys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"
#include "tokens.h"
#include "ft_printf.h"

static int	allocation_instruction(t_code_line *code_line, t_instruction **inst, t_token **inst_token)
{
	if (!((*inst) = ft_memalloc(sizeof(t_instruction))))
		return (-1);
	if (!((*inst_token)->values = ft_memalloc(sizeof(t_type))))
		return (-1);
	(*inst_token)->values->instruction = (*inst);
	if (!((*inst_token)->values->instruction->lexeme = ft_strndup(&code_line->line[(*inst_token)->position], (*inst_token)->length)))
		return (-1);
	(*inst_token)->values->instruction->type = code_line->op_code;
	return (1);
}

static int	is_param_parsed_or_error(t_token *token, int current_param)
{
	if (token->error)
	{
		if (token->error == MEMORY_ALLOCATION_ERROR)
			exit (0); // NEED TO FREE ALL HERE
		token->code_line->errors = LINE_ERROR_SYNTAX;
		return (1);
	}
	if (token->values->instruction->args[current_param] == NULL)
		return (0);
	return (1);	
}

int	parse_instruction(t_data *data, t_code_line *code_line, int inst_position)
{
	t_instruction	*inst;
	t_token 		*inst_token;
	int				current_param;
	int				token_parse_state;

	inst = NULL;
	current_param = 0;
	inst_token = code_line->tokens[inst_position];
	if (!(allocation_instruction(code_line, &inst, &inst_token)))
		return (error_code_line(code_line, MEMORY_ALLOCATION_ERROR, 0));
	while (current_param < data->op_tab[code_line->op_code].param_nb)
	{
		token_parse_state = PARSE_TOKEN_REGISTER;
		while (!is_param_parsed_or_error(inst_token, current_param) && token_parse_state < PARSE_TOKEN_STATES_NUMBER - 1)
		{
			inst_token->values->instruction->args[current_param] = g_parse_parameters_func_array[token_parse_state](data, code_line, code_line->tokens[inst_position + (1 + current_param * 2)], &token_parse_state);
			token_parse_state++;
		}
		current_param++;
	}
	return (1);	
}
