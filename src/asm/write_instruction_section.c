/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_instruction_section.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takoumys <takoumys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 15:55:58 by amamy             #+#    #+#             */
/*   Updated: 2020/02/25 23:24:58 by takoumys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "tokens.h"
#include "libft.h"
#include "ft_printf.h"


static void	write_direct(t_data *data, t_token *token, int fd)
{
	ft_printf("%s\n", "write_direct");
	if (token->type != TOKEN_TYPE_DIRECT)	
		return ;
	(void)data;
	(void)token;
	(void)fd;

}

static void	write_indirect(t_data *data, t_token *token, int fd)
{
	ft_printf("%s\n", "write_INdirect");
	if (token->type != TOKEN_TYPE_INDIRECT)	
		return ;
	(void)data;
	(void)token;
	(void)fd;

}

static void	write_register(t_data *data, t_token *token, int fd)
{
	ft_printf("%s\n", "write_register");
	if (token->type != TOKEN_TYPE_REGISTER)	
		return ;
	(void)data;
	(void)token;
	(void)fd;

}

static void	write_encoding_byte(t_data *data, t_token *token, int fd)
{
	ft_printf("%s\n", "encoding_byte");
	ft_printf("type : %d\n", token->type);
	if (token->type != TOKEN_TYPE_INSTRUCTION || !data->op_tab[token->values->instruction->type].encoding_byte)	
		return ;
	else
	{
		ft_printf("%s\n", "tteubb");
	}
	
	(void)data;
	(void)token;
	(void)fd;

}

static void	write_opcode(t_data *data, t_token *token, int fd)
{
	// int	op_code;

	ft_printf("%s\n", "write_op_code");
	if (token->type != TOKEN_TYPE_INSTRUCTION)	
		return ;
	// op_code = (code_line->tokens[0]->type == TOKEN_TYPE_INSTRUCTION) ? (code_line->tokens[0]->values->instruction->type ) : (code_line->tokens[1]->values->instruction->type);
	// ft_printf("op : %d\n", op_code);
	// if (data->op_tab[op_code].encoding_byte)
		// write_encoding_byte(data, code_line, fd);
	(void)data;
	(void)token;
	(void)fd;
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
	// current_token = code_line->token;
	ft_printf("token : %d\n", code_line->token->type);
	current_token = skip_label_declaration(code_line->token);
	ft_printf("token apres : %d\n", code_line->token->type);
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