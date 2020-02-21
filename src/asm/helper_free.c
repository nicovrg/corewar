/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 05:36:34 by nicolasv          #+#    #+#             */
/*   Updated: 2020/02/21 06:30:17 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"

int		free_data(t_data **data)
{
	ft_strdel(&(*data)->name);
	ft_strdel(&(*data)->comment);
	free((*data));
	return (1);
}

void	free_token(t_token *token)
{
	// ft_memdel((void*)&token->values);
	ft_memdel((void*)&token->values);
	ft_memdel((void*)&token);
}

int		free_token_list(t_token **token)
{
	t_token *current_token_address;

	while (*token)
	{
		current_token_address = (*token);
		(*token) = (*token)->next;
		free(current_token_address);
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
		ft_strdel(&current_code_line_address->line);
		free_token_list(&current_code_line_address->token);
		ft_memdel((void*)&current_code_line_address->tokens);
		free(current_code_line_address);
	}
	free(*code_line);
	return (1);
}

int		free_all(t_data **data, t_code_line **code_line)
{
	if (data)
		free_data(data);
	if (code_line)
		free_code_line(code_line);
	return (1);
}
