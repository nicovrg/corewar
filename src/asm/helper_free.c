/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 05:36:34 by nicolasv          #+#    #+#             */
/*   Updated: 2020/03/03 22:53:49 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "tokens.h"
#include "libft.h"
#include "ft_printf.h"	

int		free_data(t_data **data)
{
	ft_strdel(&(*data)->name);
	ft_strdel(&(*data)->comment);
	ft_strdel(&(*data)->file_name);
	free((*data));
	return (1);
}

void	free_token(t_token *token)
{
	int	type;

	type = token->type;
	if (!(type == TOKEN_TYPE_SEPARATOR))
		g_token_free_values_func_array[type](token);
	ft_memdel((void*)&token->values);
	ft_memdel((void*)&token);
}

int		free_token_list(t_token *token)
{
	t_token *current_token_address;

	while (token)
	{
		current_token_address = (token);
		(token) = (token)->next;
		if (current_token_address != NULL)
			free_token(current_token_address);
	}
	return (1);
}

int		free_code_line(t_code_line **code_line)
{
	t_code_line *current_code_line_address;

	while (*code_line)
	{
		current_code_line_address = (*code_line);
		(*code_line) = (*code_line)->next;
		free_token_list(current_code_line_address->token);
		ft_strdel(&current_code_line_address->line);
		ft_memdel((void*)&current_code_line_address->tokens);
		ft_memdel((void*)&current_code_line_address);
	}
	free(*code_line);
	return (1);
}

int		free_all(t_data **data, t_code_line **code_line)
{
	if (code_line)
		free_code_line(code_line);
	if (data)
		free_data(data);
	return (1);
}
