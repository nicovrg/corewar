/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translator.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takoumys <takoumys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 18:27:42 by takoumys          #+#    #+#             */
/*   Updated: 2020/02/25 23:26:15 by takoumys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"
#include "tokens.h"
#include "ft_printf.h"

void		skip_only_labels_declaration(t_code_line **current_line)
{
	while ((*current_line) && (*current_line)->nb_token == 1)
		*current_line = (*current_line)->next;
}

void		write_instruction_section(t_data *data, t_code_line *code_line, int fd)
{
	t_code_line	*current_line;

	current_line = code_line;
	while (current_line)
	{
		skip_only_labels_declaration(&current_line);
		if (current_line)
			write_instruction(data, current_line, fd);
		else
			return ;
		current_line = current_line->next;
	}
}

void	dev_fill_instruction(t_code_line **code_line)
{
	t_token *token = (*code_line)->tokens[0];
	if (!(token->values = ft_memalloc(sizeof(t_type*))))
		return ;
	if (!(token->values->instruction = ft_memalloc(sizeof(t_instruction))))
			return ;
	token->values->instruction->type = 1;
}

int			translator(t_data **data, t_code_line **code_line)
{
	int	fd;
	if ((fd = create_output_file(*data)) == -1)
		return (0);
	write_header(*data, fd);

	dev_fill_instruction(code_line);

	write_instruction_section(*data, *code_line, fd);
	return (1);
}