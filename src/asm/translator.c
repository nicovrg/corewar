/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translator.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 18:27:42 by takoumys          #+#    #+#             */
/*   Updated: 2020/02/25 19:54:13 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"
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

int			translator(t_data **data, t_code_line **code_line)
{
	int	fd;
	if ((fd = create_output_file(*data)) == -1)
		return (0);
	write_header(*data, fd);
	write_instruction_section(*data, *code_line, fd);
	return (1);
}