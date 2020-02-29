/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_parameters.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takoumys <takoumys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 18:21:24 by amamy             #+#    #+#             */
/*   Updated: 2020/02/29 13:57:12 by takoumys         ###   ########.fr       */
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
			param->error = MEMORY_ALLOCATION_ERROR,
			(*state) = ERROR_PARSE_TOKEN;
			return (NULL);
		}
		registr->reg_nb = ft_atoi(&codeline->line[param->position + 1]);
		if (registr->reg_nb < 1 || registr->reg_nb > 16)
		{
			ft_printf("%s\n", "inv reg");
			param->error = INVALID_REGISTER;
		}
		codeline->instruction_size = codeline->instruction_size + 1;
		ft_printf("register %d\n", registr->reg_nb);
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
		return (param);
	}
	return (NULL);
	(void)data;
}

t_token	*parse_token_direct(t_data *data, t_code_line *codeline, t_token *param, int *state)
{
	t_indirect *direct;
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
		return (param);
	}
	(void)data;
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

	ft_printf("%s\n", "parse_token_label_call");
	ft_printf("token_type : |%d|\n", param->type);
	if (param->type == TOKEN_TYPE_LABEL_CALL)
	{
		label_call = param->values->label_call;
		if (check_label_call_type(param, LABEL_CALL_TYPE_INDIRECT))
			label_call->lexeme = ft_strndup(&param->code_line->line[param->position + 1], param->length - 1);
		else
			label_call->lexeme = ft_strndup(&param->code_line->line[param->position + 2], param->length - 2);
		ft_printf("label_call->lexeme : |%s|\n", label_call->lexeme);
		if ( data->op_tab[codeline->op_code].direct_size)
			codeline->instruction_size = codeline->instruction_size + 2;
		else
			codeline->instruction_size = codeline->instruction_size + 4;
		set_label_call_target(data, param);
		return (param);
	}
	(void)data;
	return (NULL);
	(void)codeline;
	(void)param;
	(void)state;
	(void)data;
	return (NULL);
}

t_token	*(*g_parse_parameters_func_array[PARSE_TOKEN_STATES_NUMBER])(t_data *,t_code_line *, t_token *, int *) = {
	[PARSE_TOKEN_REGISTER] = parse_token_register,
	[PARSE_TOKEN_INDIRECT] = parse_token_indirect,
	[PARSE_TOKEN_DIRECT] = parse_token_direct,
	[PARSE_TOKEN_LABEL_CALL] = parse_token_label_call,
};
