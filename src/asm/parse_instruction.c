/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_instruction.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 13:18:15 by amamy             #+#    #+#             */
/*   Updated: 2020/02/28 15:18:56 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"
#include "tokens.h"
#include "ft_printf.h"

static void update_instruction_size_and_address(t_data *data, t_code_line *code_line, int current_byte[1])
{
	if (data->op_tab[code_line->op_code].encoding_byte)
		code_line->instruction_size = (code_line->instruction_size + 2);
	else
		code_line->instruction_size++;
	code_line->mem_address = current_byte[0];
}
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

int	parse_instruction(t_data *data, t_code_line *code_line, int inst_position, int current_byte[1])
{
	t_instruction	*inst;
	t_token 		*inst_token;
	int				current_param;
	int				token_parse_state;

	inst = NULL;
	current_param = 0;
	token_parse_state = PARSE_TOKEN_REGISTER;
	inst_token = code_line->tokens[inst_position];
	update_instruction_size_and_address(data, code_line, current_byte);
	if (!(allocation_instruction(code_line, &inst, &inst_token)))
		return (0);
	while (current_param < data->op_tab[code_line->op_code].param_nb)
	{
		ft_printf("inst param number : %d\n", data->op_tab[code_line->op_code].param_nb);
		while (inst_token->values->instruction->args[current_param] == NULL\
		&& token_parse_state != ERROR_PARSE_TOKEN)
		{
			ft_printf("curent paramrererg : %d\n", current_param);
			ft_printf("current_line : |%s|\n", code_line->line);
			ft_printf("token position : %d\n", code_line->tokens[inst_position + 1 + current_param]->position);
			ft_printf(" current_statte : %d\n", token_parse_state);
			ft_printf("test : %p\n", inst_token->values->instruction->args[current_param]);
			ft_printf("2:\n");
			// inst_token->values->instruction->args[current_param] = g_parse_parameters_func_array[token_parse_state](0,0,0);
			inst_token->values->instruction->args[current_param] = g_parse_parameters_func_array[token_parse_state](code_line, code_line->tokens[inst_position + 1 + current_param], &token_parse_state);
			token_parse_state++;
			ft_printf("3:\n");
		}
		current_param++;
	}
	return (1);	
}