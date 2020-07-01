/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_instruction_section.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 15:55:58 by amamy             #+#    #+#             */
/*   Updated: 2020/07/01 15:05:15 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "tokens.h"
#include "libft.h"
#include "ft_printf.h"


static void	write_direct(t_data *data, t_token *token, int fd)
{
	if (token->type != TOKEN_TYPE_DIRECT)	
		return ;
	// ft_printf("%s\n", "write_direct");
	// ft_printf("token mem %d\n", token->mem_address);
	if (data->op_tab[token->code_line->op_code].direct_size) // segfault here because token not allocated cause parser not coded
		write_big_endian(fd, token->values->direct->value, 2);
	else
		write_big_endian(fd, token->values->direct->value, 4);
}

static void	write_indirect(t_data *data, t_token *token, int fd)
{
	if (token->type != TOKEN_TYPE_INDIRECT)	
		return ;
	// ft_printf("%s\n", "write_INdirect");
	write_big_endian(fd, token->values->indirect->value, 2);
	(void)data;
}

static void	write_register(t_data *data, t_token *token, int fd)
{
	if (token->type != TOKEN_TYPE_REGISTER)	
		return ;
	// ft_printf("%s\n", "write_register");
	write(fd, &token->values->registr->reg_nb, 1);
	(void)data;
}

static void	write_encoding_byte(t_data *data, t_token *token, int fd)
{
	int	i;
	int	byte;
	char	binary[1];

	i = 0;
	byte = 6;
	binary[0] = 0;
	if (token->type != TOKEN_TYPE_INSTRUCTION || !data->op_tab[token->values->instruction->type].encoding_byte)	
		return ;
	else
	{
		while (i < 3 && token->values->instruction->args[i])
		{
			if (token->values->instruction->args[i]->type == TOKEN_TYPE_DIRECT)
				binary[0] = binary[0] + (char)((DIR_CODE << byte));
			else if (token->values->instruction->args[i]->type == TOKEN_TYPE_INDIRECT)
				binary[0] = binary[0] + (char)((IND_CODE << byte));
			else if (token->values->instruction->args[i]->type == TOKEN_TYPE_REGISTER)
				binary[0] = binary[0] + (char)((REG_CODE << byte));
			i++;
			byte = byte - 2;
		}
	}
	write(fd, binary, 1);
}

static void	write_opcode(t_data *data, t_token *token, int fd)
{
	char binary[1];
	int	op_code;

	if (token->type != TOKEN_TYPE_INSTRUCTION)	
		return ;
	op_code = (token->values->instruction->type );
	binary[0] = (char)op_code;
	write(fd, binary, 1);
	(void)data;
}

void (*g_instruction_translation_func_array[TRANSLATE_STATES_NUMBER])(t_data *, t_token *, int) = {
	[TRANSLATE_OPCODE] = write_opcode,
	[TRANSLATE_ENCODING_BYTE] = write_encoding_byte,
	[TRANSLATE_DIRECT] = write_direct,
	[TRANSLATE_INDIRECT] = write_indirect,
	[TRANSLATE_REGISTER] = write_register,
};

static t_token	*skip_label_declaration(t_token *token)
{
	if (token->type == TOKEN_TYPE_LABEL)
		return (token->next);
	else
		return (token);
}

void		write_instruction(t_data *data, t_code_line *code_line, int fd)
{
	int		current_state;
	t_token	*current_token;

	current_state = TRANSLATE_OPCODE;
	// ft_printf("token : %d\n", code_line->token->type);
	current_token = skip_label_declaration(code_line->token);
	// ft_printf("token apres : %d\n", code_line->token->type);
	while (current_token)
	{
		
		while (current_state <= TRANSLATE_REGISTER)
		{
			g_instruction_translation_func_array[current_state](data, current_token, fd);
			current_state++;
		}
		current_state = TRANSLATE_OPCODE;
		current_token = current_token->next;
	}
}