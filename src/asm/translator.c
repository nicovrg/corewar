/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translator.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 18:27:42 by takoumys          #+#    #+#             */
/*   Updated: 2020/03/03 23:02:40 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"
#include "tokens.h"
#include "ft_printf.h"

void		skip_only_labels_declaration(t_code_line **current_line)
{
	while ((*current_line) && (*current_line)->nb_token == 1)
	{
		ft_printf("%s\n", "Il est passé par ici");
		*current_line = (*current_line)->next;
	}
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

// void	dev_fill_instruction(t_code_line **code_line)
// {
// 	t_token *token = (*code_line)->tokens[0];
// 	if (!(token->values = ft_memalloc(sizeof(t_type*))))
// 		return ;
// 	if (!(token->values->instruction = ft_memalloc(sizeof(t_instruction))))
// 			return ;
// 	token->mem_address = 888;
// 	token->code_line->op_code = 8;
// 	token->values->instruction->type = 8;
// 	token->values->instruction->parameter[0] = ft_memalloc(sizeof(t_token));
// 	token->values->instruction->parameter[1] = ft_memalloc(sizeof(t_token));
// 	token->values->instruction->parameter[2] = ft_memalloc(sizeof(t_token));
// 	(*code_line)->tokens[1] = token->values->instruction->parameter[0];
// 	(*code_line)->tokens[3] = token->values->instruction->parameter[1];
// 	(*code_line)->tokens[5] = token->values->instruction->parameter[2];
// 	token->values->instruction->parameter[0]->type = TOKEN_TYPE_DIRECT;
// 	token->values->instruction->parameter[1]->type = TOKEN_TYPE_INDIRECT;
// 	token->values->instruction->parameter[2]->type = TOKEN_TYPE_REGISTER;
// 	token->values->instruction->parameter[0]->values = ft_memalloc(sizeof(t_type*));
// 	token->values->instruction->parameter[1]->values = ft_memalloc(sizeof(t_type*));
// 	token->values->instruction->parameter[2]->values = ft_memalloc(sizeof(t_type*));
	
// 	token->values->instruction->parameter[0]->values->direct = ft_memalloc(sizeof(t_direct));
// 	token->values->instruction->parameter[1]->values->indirect = ft_memalloc(sizeof(t_indirect));
// 	token->values->instruction->parameter[2]->values->registr = ft_memalloc(sizeof(t_registr));

// 	token->values->instruction->parameter[0]->values->direct->value = 4;
// 	token->values->instruction->parameter[1]->values->indirect->value = 6;
// 	token->values->instruction->parameter[2]->values->registr->reg_nb = 7;
// }

void			write_big_endian(int fd, int nb, int size)
{
	unsigned char binary[4];

	binary[0] = nb >> 24;
	binary[1] = nb >> 16;
	binary[2] = nb >> 8;
	binary[3] = nb >> 0;
	if (size == IND_SIZE)
	{
		write(fd, &binary[2], 1);
		write(fd, &binary[3], 1);
	}
	if (size == DIR_SIZE)
		write(fd, binary, size);
}

int			translator(t_data **data, t_code_line **code_line)
{
	int	fd;
	if ((fd = create_output_file(*data)) == -1)
		return (0);
	write_header(*data, fd);

	// dev_fill_instruction(code_line);

	write_instruction_section(*data, *code_line, fd);
	return (1);
}