/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_parameters.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 18:21:24 by amamy             #+#    #+#             */
/*   Updated: 2020/02/28 15:23:17 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"
#include "tokens.h"
#include "ft_printf.h"

t_token	*parse_token_register(t_code_line *codeline, t_token *param, int *state)
{
	t_registr *registr;
	
	ft_putendl("===== ICI ICI ICI ===");
	if ((*param)->type == TOKEN_TYPE_REGISTER)
	{
		if (!(registr = ft_memalloc(sizeof(t_registr))))
		{
			(state) = ERROR_PARSE_TOKEN;
			return (NULL);
		}
		if (!((*param)->values = ft_memalloc(sizeof(t_type))))
		{
			(state) = ERROR_PARSE_TOKEN;
			return (NULL);
		}
		registr->reg_nb = ft_atoi(&codeline->line[param->position + 1]);
		ft_printf(" this is the register nb : %d\n", registr->reg_nb);
		return (param);
	}
	return (NULL);
}

t_token	*parse_token_indirect(t_code_line *codeline, t_token *param, int *state)
{
	ft_printf("%s\n", "parse_token_indirect");
	return (param);
}

t_token	*parse_token_direct(t_code_line *codeline, t_token *param, int *state)
{
	ft_printf("%s\n", "parse_token_direct");
	return (param);
}

t_token	*parse_token_label_call(t_code_line *codeline, t_token *param, int *state)
{
	ft_printf("%s\n", "parse_token_label_call");
	return (param);
}

// t_token	*(*g_parse_parameters_func_array[PARSE_TOKEN_STATES_NUMBER])(t_code_line *, t_token *, int *) = {
// 	[PARSE_TOKEN_REGISTER] = parse_token_register,
// 	[PARSE_TOKEN_INDIRECT] = parse_token_indirect,
// 	[PARSE_TOKEN_DIRECT] = parse_token_direct,
// 	[PARSE_TOKEN_LABEL_CALL] = parse_token_label_call,
// };
