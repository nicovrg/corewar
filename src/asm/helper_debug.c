/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_debug.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 15:32:54 by qgirard           #+#    #+#             */
/*   Updated: 2020/03/06 13:17:13 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"
#include "tokens.h"
#include "ft_printf.h"
#include <stdio.h>

int		print_data(t_data **data)
{
	if (!data || !(*data))
		return (error_msg("data is not initialized", 0));
	ft_printf("\x1b[1m\x1b[31m/ ======================== START DATA STRUCTURE ======================== \\\x1b[0m\n");
	ft_putendl("");
	ft_printf("\tindex_name =\t\t%d\n", (*data)->name_line);
	ft_printf("\tindex_comment =\t\t%d\n", (*data)->comment_line);
	ft_printf("\t.name =\t\t\t|%s|\n", (*data)->name);
	ft_printf("\t.comment =\t\t|%s|\n", (*data)->comment);
	ft_printf("\tindex_line =\t\t%d\n", (*data)->index_line);
	ft_putendl("");
	ft_printf("\x1b[1m\x1b[31m\\ ======================== END DATA STRUCTURE ======================== /\t\t\x1b[0m\n");
	ft_putendl("\n");
	return (1);
}

int		print_code_lines(t_data **data, t_code_line **code_line)
{
	int				i;
	t_code_line		*current_code_line;

	i = 1;
	current_code_line = (*code_line);
	if (!code_line || !(*code_line))
		return (error_msg("code_line is not initialized", 0));
	print_data(data);
	ft_printf("\x1b[1m\x1b[32m/ ======================== START CODE LINE LIST ======================== \\\x1b[0m\n");
	ft_putendl("\n\n");
	while (current_code_line)
	{
		ft_printf("\t\x1b[1m\x1b[36m/ ===================== START CODE LINE NODE %d ===================== \\\x1b[0m\n", i);
		ft_putendl("");
		ft_printf("\t\tline number =\t\t\t\t|%d|\n", current_code_line->nb_line);
		ft_printf("\t\ttoken in line number =\t\t\t|%d|\n", current_code_line->nb_token);
		ft_printf("\t\terrors =\t\t\t\t|%d|\n", current_code_line->errors);
		ft_printf("\t\tMemory_address =\t\t\t|%d|\n", current_code_line->mem_address);
		ft_printf("\t\tSize in binary =\t\t\t|%d|\n", current_code_line->instruction_size);
		ft_printf("\t\tline string =\t\t\t\t|\x1b[32m%s\x1b[0m|\n", current_code_line->line);
		ft_putendl("");
		ft_printf("\t\t\x1b[1m\x1b[34m/ ===================== START TOKEN TABLE (%d) ===================== \\\x1b[0m\n\n", i);
		print_tokens(&current_code_line);
		ft_printf("\t\t\x1b[1m\x1b[34m\\ ======================== END TOKEN TABLE ======================== /\t\t\x1b[0m\n\n");
		ft_printf("\t\taddress to current node =\t\t|%p|\n", current_code_line);
		ft_printf("\t\taddress to following node =\t\t|%p|\n", current_code_line->next);
		ft_putendl("");
		ft_printf("\t\x1b[1m\x1b[36m\\ ======================= END CODE LINE  NODE ======================= /\x1b[0m\n\n");
		current_code_line = current_code_line->next;
		i++;
	}
	ft_putendl("");
	ft_printf("\x1b[1m\x1b[32m\\ ======================== ENDCODE LINE LIST ======================== /\t\t\x1b[0m\n");
	return (1);
}

int		print_token(int length, char *str)
{
	int i;

	i = 0;
	while (str[i] && i < length)
	{
		ft_putchar(str[i]);
		i++;
	}
	return (1);
}

static int	is_parameter(t_token *token)
{
	int	type;

	type = token->type;
	if (type == TOKEN_TYPE_REGISTER || type == TOKEN_TYPE_DIRECT \
	|| type == TOKEN_TYPE_LABEL_CALL || type == TOKEN_TYPE_INDIRECT)
		return (1);
	return (0);
}

static int	get_token_value(t_token *token)
{
	int	type;

	type = token->type;
	if (type == TOKEN_TYPE_REGISTER)
		return (token->values->registr->reg_nb);
	else if (type == TOKEN_TYPE_DIRECT)
		return (token->values->direct->value);
	else if (type == TOKEN_TYPE_INDIRECT)
		return (token->values->indirect->value);
	else if (type == TOKEN_TYPE_LABEL_CALL)
		return (token->values->label_call->value);
	return (-1);
}

static char	*get_arg_type_str(t_token *arg)
{
	int	type = arg->type;

	if (type == TOKEN_TYPE_SEPARATOR)
		return (ft_strdup("SEP"));
	if (type == TOKEN_TYPE_LABEL)
		return (ft_strdup("LABEL_DECLARATION"));
	if (type == TOKEN_TYPE_INSTRUCTION)
		return (ft_strdup("OP"));
	else if (type == TOKEN_TYPE_DIRECT)
		return (ft_strdup("DIR"));
	if (type == TOKEN_TYPE_REGISTER)
		return (ft_strdup("REG"));
	else if (type == TOKEN_TYPE_INDIRECT || (type == TOKEN_TYPE_LABEL_CALL && arg->values->label_call->type == TOKEN_TYPE_INDIRECT))
		return (ft_strdup("IND"));
	else if (type == TOKEN_TYPE_LABEL_CALL)
	{
		if (arg->values->label_call->type == LABEL_CALL_TYPE_DIRECT)
			return (ft_strdup("LABEL_CALL|->|DIR"));
		if (arg->values->label_call->type == LABEL_CALL_TYPE_INDIRECT)
			return (ft_strdup("LABEL_CALL|->|IND"));
	}
	if (type == TOKEN_TYPE_UNKNOWN)
		return (ft_strdup("UNKNOWN"));


	return (NULL);
}

int		print_tokens(t_code_line **current_code_line)
{
	int			i;
	char		*tmp;
	t_token		*current_token;
	
	i = 0;
	if (!current_code_line || !(*current_code_line) || !(*current_code_line)->token)
		return (error_msg("code_line is not initialized", 0));
	current_token = (*current_code_line)->token;
	while (current_token)
	{
		ft_printf("token number %d\n", i);
		ft_printf("\t\t\ttoken =\t\t\t\t\t|");
		print_token(current_token->length, current_token->code_line->line + current_token->position);
		ft_printf("|\n");
		ft_printf("\t\t\tToken number :\t\t\t\t|%d|\n", current_token->token_nb);
		tmp = get_arg_type_str(current_token);
		ft_printf("\t\t\ttype =\t\t\t\t\t|%s|\n", tmp);
		if (is_parameter(current_token))
			ft_printf("\t\t\tvalue =\t\t\t\t\t|%d|\n", get_token_value(current_token));
		ft_printf("\t\t\tposition =\t\t\t\t|%d|\n", current_token->position);
		ft_printf("\t\t\tlength =\t\t\t\t|%d|\n", current_token->length);
		ft_printf("\t\t\tcode_line parent node address =\t\t|%p|\n", current_token->code_line);
		ft_printf("\t\t\tunion structure address =\t\t|%p|\n", current_token->values);
		ft_printf("\t\t\tnext token address =\t\t\t|%p|\n", current_token->next);
		ft_printf("\n");
		current_token = current_token->next;
		i++;
		ft_strdel(&tmp);
	}
	return (1);
}

void	print_labels(t_data *data)
{
	int		i;
	t_label	*current_label;

	i = 0;
	current_label = data->label_list;
	ft_printf("\n======== PRINT LABEL ========\n\n");
	while (current_label)
	{
		ft_printf("==== Label n : %d ====\n", i);
		ft_printf("Lexeme -> |%s|\n", current_label->lexeme);
		ft_printf("target : L%d : |%s|\n", current_label->target->nb_line, current_label->target->line);
		current_label = current_label->next;
		i++;
	ft_printf("%s\n", "==== End ====\n");
	}
}

void	print_label_calls(t_data *data)
{
	int				i;
	t_label_call	*current_label;

	i = 0;
	current_label = data->label_calls;
	ft_printf("\n======== PRINT LABEL CALLS ========\n\n");
	while (current_label)
	{
		ft_printf("==== Label_call n : %d ====\n", i);
		ft_printf("Line : %d\n", current_label->token->code_line->nb_line);
		ft_printf("Lexeme -> |%s|\n", current_label->lexeme);
		ft_printf("value : %d\n", current_label->value);
		current_label = current_label->next;
		i++;
	ft_printf("%s\n", "==== End ====\n");
	}
}
