/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_instruction.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takoumys <takoumys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 17:22:45 by amamy             #+#    #+#             */
/*   Updated: 2020/02/28 23:28:09 by takoumys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"
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

static int	is_param_type_accepted(t_data *data, t_token *param, int param_nb)
{
	int	param_allowed;

	param_allowed = (ft_itoa(data->op_tab[param->code_line->op_code].param_types)[param_nb] - '0');
	if (param->type == TOKEN_TYPE_REGISTER)
	{
		if (param_allowed != 1 && param_allowed != 3 && param_allowed != 5 && param_allowed != 7)
			return (0);
	}
	else if (param->type == TOKEN_TYPE_INDIRECT || param->type == LABEL_CALL_TYPE_INDIRECT)
	{
		if (param_allowed != 2 && param_allowed != 3 && param_allowed != 6 && param_allowed != 7)
			return (0);
	}
	else if (param->type == TOKEN_TYPE_DIRECT || param->type == LABEL_CALL_TYPE_DIRECT)
	{
		if (param_allowed < 4)
			return (0);
	}
	 if (param->type != TOKEN_TYPE_REGISTER && param->type != TOKEN_TYPE_INDIRECT && param->type != LABEL_CALL_TYPE_INDIRECT \
	&& param->type != TOKEN_TYPE_DIRECT && param->type != LABEL_CALL_TYPE_DIRECT)
	{
		ft_printf("lexeme : |%s|\n", &param->code_line->line[param->position]);
		ft_printf("type : %d\n", param->type);
		param->error = NOT_ARGUMENT_TYPE;
		return (0);
	}
	return (1);
}

/*
** ==================== is_valid_instruction ====================
** Save the op code of the instruction in the code_line and check
** taht we have an op code and that the params sent to it are
** compatible with this instruction.
*/

int	is_valid_instruction(t_data *data, t_code_line *line, int inst_position)
{
	int	i;
	int	valid_parms;
	int	inst_index;

	i = 0;
	valid_parms = 0;
	inst_index = inst_position;
	if (line->tokens[inst_index]->type !=  TOKEN_TYPE_INSTRUCTION)
		return (-1);
	i = 1;
	line->op_code = get_op_code(data, line->tokens[inst_index]);
	while (valid_parms < data->op_tab[line->op_code].param_nb)	
	{
		if (!is_param_type_accepted(data, line->tokens[inst_index + i], valid_parms))
			return (error_syntax_token(line->tokens[inst_index + i], BAD_PARAMETER, 0));
		valid_parms++;
		if (valid_parms < data->op_tab[line->op_code].param_nb \
		&& (!is_separator(line->tokens[inst_index + i + 1])))
			return (0);
		i = i + 2;
	}
	return (1);	
}