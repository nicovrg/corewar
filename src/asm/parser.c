/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 02:56:10 by amamy             #+#    #+#             */
/*   Updated: 2020/02/20 03:15:56 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"
#include "ft_printf.h"


int	is_valid_label(t_code_line *code_line)
{
	t_token *token;

	token = code_line->token;
	if (token->type == TOKEN_TYPE_LABEL)
		code_line->label = ft_strndup(&(code_line->line[token->position]), token->length - 1);
	ft_printf("laebel |%s|\n", code_line->label);
	return (1);	
}

int	parse_instruction(t_code_line *code_line,int current_token, int current_byte[1])
{
	ft_putendl("coucou");
	(void)code_line;
	(void)current_token;
	(void)current_byte;
	return (1);	
}

int	is_valid_instruction(t_code_line *code_line, int current_byte[1], int *contains_instruction)
{
	ft_putendl("coucou");
	(void)code_line;
	(void)current_byte;
	(void)contains_instruction;
	return (1);	
}

int	invalid_syntax(t_code_line *code_line, int contains_instruction)
{
	ft_putendl("coucou");
	(void)code_line;
	(void)contains_instruction;
	return (1);	
}

int	syntax_error(t_code_line *code_line, int current_byte[1], int contains_instruction)
{
	ft_putendl("coucou");
	(void)code_line;
	(void)current_byte;
	(void)contains_instruction;
	return (1);	
}

// static int	parse_line(t_code_line *code_line, int current_byte[1])
// {
// 	ft_printf("=========\nLINE : |%s|\n", code_line->line);
// 	if (code_line->token->type == TOKEN_TYPE_LABEL \
// 	|| code_line->token->type == TOKEN_TYPE_INSTRUCTION)
// 	{
// 		parse_label(code_line, current_byte);
// 		if(!is_valid_instruction(code_line, current_byte))
// 			return (0);
// 	}
// 	else
// 	{
// 		ft_printf("%s\n", "Wrong_first");
// 		code_line->errors = 1;
// 		syntax_error(code_line, current_byte);
// 		return (0);
// 	}
// 	ft_printf("=========\n\n");
// 	return (1);
// }

static int	parse_line(t_code_line *code_line, int current_byte[1])
{
	int			current_token;
	int			contains_instruction;;
	
	contains_instruction = 0;
	current_token = 0;
	ft_printf("=========\nLINE : |%s|\n", code_line->line);
	if (is_valid_label(code_line) && current_token < code_line->nb_token)
		current_token++;
	if (is_valid_instruction(code_line, current_byte, &contains_instruction))
		parse_instruction(code_line, current_token, current_byte);
	else
		invalid_syntax(code_line, contains_instruction);
		
	// while (current_token < code_line->nb_token)
	{
		// ft_printf("current_token : %d\n", current_token);
		// ft_printf(" code_line->tokens[current_token]->type : |%s|\n", code_line->tokens[current_token]->type);
		// if (code_line->tokens[current_token]->type == TOKEN_TYPE_INSTRUCTION)
		// {
		// }
		// else
		// {
		// 	ft_printf("%s\n", "Wrong_first");
		// 	code_line->errors = 1;
		// 	syntax_error(code_line, current_byte, contains_instruction);
		// 	return (0);
		// }
	}
	ft_printf("=========\n\n");
	return (1);
}


static t_code_line	*looking_for_rigth_label(t_code_line **code_line)
{
	ft_printf("%s\n", "looking_for_rigth_label");
	return (NULL);
	(void)code_line;
}

static int	is_label_only(t_code_line *code_line)
{
	ft_printf("code_line->nb_token : %d\n", code_line->nb_token);
	if (code_line->token->type == TOKEN_TYPE_LABEL \
	&& code_line->nb_token == 1)
	{
		ft_printf("%s\n", "is_label_only");
		return (1);
	}
	return (0);
}

int	parser(t_data **data, t_code_line **code_line)
{
	int			current_byte;
	t_code_line	*loaded_label;
	t_code_line	*current_line;


	current_byte = 0;
	current_line = (*code_line);
	loaded_label = NULL;
	while (current_line)
	{
		ft_putendl("coucou");
		if (is_label_only(current_line))
			loaded_label = looking_for_rigth_label(&current_line);
		else
		{
			parse_line(*code_line, &current_byte);
			if (current_line->errors)
				(*data)->errors = 1;
		}
		// if (loaded_label)
		// 	save_label();
		if (current_line)
		current_line = current_line->next;
	}
	return (1);
}