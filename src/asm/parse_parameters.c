/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_parameters.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 18:21:24 by amamy             #+#    #+#             */
/*   Updated: 2020/03/01 18:51:44 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "asm.h"
#include "tokens.h"
#include "ft_printf.h"

t_token	*parse_token_register(t_data *data, t_code_line *codeline, t_token *param, int *state)
{
	t_registr *registr;
	
	if (param->type == TOKEN_TYPE_REGISTER)
	{
		if (!(registr = ft_memalloc(sizeof(t_registr)))\
		|| !(param->values = ft_memalloc(sizeof(t_type*))))
		{
			(*state) = ERROR_PARSE_TOKEN;
			return (NULL);
		}
		registr->reg_nb = ft_atoi(&codeline->line[param->position + 1]);
		if (registr->reg_nb < 1 || registr->reg_nb > 16)
			error_syntax_token(param, INVALID_REGISTER, 0);
		codeline->instruction_size = codeline->instruction_size + 1;
			param->values->registr = registr;
		return (param);
	}
	return (NULL);
	(void)data;
}

t_token	*parse_token_indirect(t_data *data, t_code_line *codeline, t_token *param, int *state)
{
	t_indirect *indirect;
	if (param->type == TOKEN_TYPE_INDIRECT)
	{
		if (!(indirect = ft_memalloc(sizeof(t_indirect)))\
		|| !(param->values = ft_memalloc(sizeof(t_type*))))
		{
			param->error = MEMORY_ALLOCATION_ERROR,
			(*state) = ERROR_PARSE_TOKEN;
			return (NULL);
		}
		indirect->value = ft_atoi(&codeline->line[param->position]);
		codeline->instruction_size = codeline->instruction_size + 2;
			param->values->indirect = indirect;
		return (param);
	}
	return (NULL);
	(void)data;
}

t_token	*parse_token_direct(t_data *data, t_code_line *codeline, t_token *param, int *state)
{
	t_direct *direct;
	if (param->type == TOKEN_TYPE_DIRECT)
	{
		if (!(direct = ft_memalloc(sizeof(t_direct)))\
		|| !(param->values = ft_memalloc(sizeof(t_type*))))
		{
			param->error = MEMORY_ALLOCATION_ERROR,
			(*state) = ERROR_PARSE_TOKEN;
			return (NULL);
		}
		direct->value = ft_atoi(&codeline->line[param->position + 1]);
		if ( data->op_tab[codeline->op_code].direct_size)
			codeline->instruction_size = codeline->instruction_size + 2;
		else
			codeline->instruction_size = codeline->instruction_size + 4;
		param->values->direct = direct;
		return (param);
	}
	return (NULL);
}

static void	set_label_call_target(t_data *data, t_token *label_call)
{
	t_label *declarations;

	declarations = data->label_list;
	while (declarations)
	{
		if (!ft_strcmp(declarations->lexeme, label_call->values->label_call->lexeme))
		{
			label_call->values->label_call->target = declarations->target;
			label_call->values->label_call->value = declarations->target->mem_address;
		}
		declarations = declarations->next;
	}
	if (!label_call->values->label_call->target)
		label_call->error = UNDECLARED_LABEL_CALL;
	
}

t_token	*parse_token_label_call(t_data *data, t_code_line *codeline, t_token *param, int *state)
{
	t_label_call *label_call;

	if (param->type == TOKEN_TYPE_LABEL_CALL)
	{
		label_call = param->values->label_call;
		if (check_label_call_type(param, LABEL_CALL_TYPE_INDIRECT))
			label_call->lexeme = ft_strndup(&param->code_line->line[param->position + 1], param->length - 1);
		else
			label_call->lexeme = ft_strndup(&param->code_line->line[param->position + 2], param->length - 2);
		if ( data->op_tab[codeline->op_code].direct_size)
			codeline->instruction_size = codeline->instruction_size + 2;
		else
			codeline->instruction_size = codeline->instruction_size + 4;
		set_label_call_target(data, param);
		return (param);
	}
	return (NULL);
	(void)state;
}

t_token	*(*g_parse_parameters_func_array[PARSE_TOKEN_STATES_NUMBER])(t_data *,t_code_line *, t_token *, int *) = {
	[PARSE_TOKEN_REGISTER] = parse_token_register,
	[PARSE_TOKEN_INDIRECT] = parse_token_indirect,
	[PARSE_TOKEN_DIRECT] = parse_token_direct,
	[PARSE_TOKEN_LABEL_CALL] = parse_token_label_call,
};
