/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_instruction_validity.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takoumys <takoumys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 17:22:45 by amamy             #+#    #+#             */
/*   Updated: 2020/03/01 02:04:31 by takoumys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"
#include "tokens.h"
#include "ft_printf.h"


static int	get_op_code(t_data *data, t_token *op)
{
	int	i;
	char	*line;

	i = 1;
	line = op->code_line->line;
	while (ft_strncmp(data->op_tab[i].name , &line[op->position], op->length))
		i++;
	return (i);
}

static int	check_parameter_validity(t_data *data, t_token *param, int param_nb)
{
	int	param_allowed;

	param_allowed = (ft_itoa(data->op_tab[param->code_line->op_code].param_types)[param_nb] - '0');
	if (param->type == TOKEN_TYPE_REGISTER)
	{
		if (param_allowed != 1 && param_allowed != 3 && param_allowed != 5 && param_allowed != 7)
			return (error_syntax_token(param, WRONG_ARGUMENT_TYPE, 0));
	}
	else if (param->type == TOKEN_TYPE_INDIRECT || check_label_call_type(param, LABEL_CALL_TYPE_INDIRECT))
	{
		if (param_allowed != 2 && param_allowed != 3 && param_allowed != 6 && param_allowed != 7)
			return (error_syntax_token(param, WRONG_ARGUMENT_TYPE, 0));
	}
	else if (param->type == TOKEN_TYPE_DIRECT || check_label_call_type(param, LABEL_CALL_TYPE_DIRECT))
	{
		if (param_allowed < 4)
			return (error_syntax_token(param, WRONG_ARGUMENT_TYPE, 0));
	}
	 if (param->type != TOKEN_TYPE_REGISTER && param->type != TOKEN_TYPE_INDIRECT \
	&& param->type != TOKEN_TYPE_DIRECT && param->type != TOKEN_TYPE_LABEL_CALL && param->type != TOKEN_TYPE_UNKNOWN)
	{
		ft_printf("lexeme : |%s|\n", &param->code_line->line[param->position]);
		ft_printf("type : %d\n", param->type);
		ft_printf("%s\n", "NOT_ARGUMENT_TYPE");
		return (error_syntax_token(param, NOT_ARGUMENT_TYPE, 0));
	}
	return (1);
}

/*
** ==================== check_instruction_validity ====================
** Save the op code of the instruction in the code_line and check
** taht we have an op code and that the params sent to it are
** compatible with this instruction.
*/


int	check_instruction_validity(t_data *data, t_code_line *line, int inst_position)
{
	int	i;
	int	params;
	int	inst_index;

	i = 0;
	params = 0;
	inst_index = inst_position;
	if (line->tokens[inst_index]->type !=  TOKEN_TYPE_INSTRUCTION)
		return (error_code_line(line, BAD_OP_CODE, -1));
	i = 1;
	line->op_code = get_op_code(data, line->tokens[inst_index]);
	while (params < data->op_tab[line->op_code].param_nb)	
	{
		check_parameter_validity(data, line->tokens[inst_index + i], params);
		params++;
		if (params < data->op_tab[line->op_code].param_nb \
		&& (!is_separator(line->tokens[inst_index + i + 1])))
			error_syntax_token(line->tokens[inst_index + i + 1], MISSING_SEPARATOR, 0);
		i = i + 2;
	}
	return (1);	
}

















/* int	check_instruction_validity(t_data *data, t_code_line *line, int inst_position)
// {
// 	int	i;
// 	int	valid_parms;
// 	int	inst_index;

// 	i = 0;
// 	valid_parms = 0;
// 	inst_index = inst_position;
// 	if (line->tokens[inst_index]->type !=  TOKEN_TYPE_INSTRUCTION)
// 		return (-1);
// 	i = 1;
// 	line->op_code = get_op_code(data, line->tokens[inst_index]);
// 	while (valid_parms < data->op_tab[line->op_code].param_nb)	
// 	{
// 		if (!check_parameter_validity(data, line->tokens[inst_index + i], valid_parms))
// 			return (error_syntax_token(line->tokens[inst_index + i], WRONG_ARGUMENT_TYPE, 0));
// 		valid_parms++;
// 		if (valid_parms < data->op_tab[line->op_code].param_nb \
// 		&& (!is_separator(line->tokens[inst_index + i + 1])))
// 			return (0);
// 		i = i + 2;
// 	}
// 	return (1);	
 }*/
