/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   label_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 23:58:28 by amamy             #+#    #+#             */
/*   Updated: 2020/02/26 19:42:41 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"
#include "tokens.h"
#include "ft_printf.h"

int		is_label_only(t_code_line *code_line)
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

static char	*get_label_text(t_code_line *code_line)
{
	char *label;

	if (!(label = ft_strndup(&code_line->line[code_line->token->position], code_line->token->length - 1)))
		return (NULL);
	return (label);
}

static int	create_and_add_label(t_data *data, t_code_line *code_line, char *label)
{
	t_label *new_label;
	t_label *current_label;


	if (!(new_label = ft_memalloc(sizeof(t_label))))
		return (-1);
	new_label->lexeme = label;
	new_label->target = fetch_label_target(code_line);
	if (!data->label_list)
		data->label_list = new_label;
	else
	{
		current_label = data->label_list;
		while (current_label)
			current_label = current_label->next

	}
	

}

static int	is_valid_label(t_data *data, t_code_line *code_line)
{
	t_label *labels;
	t_token *token;
	char	*label_text;

	token = code_line->token;
	if (!(label_text = get_label_text(code_line)))
		return (-1);
	if (token->type == TOKEN_TYPE_LABEL)
	{
		labels = data->label_list;
		while (labels)
		{
			if (!ft_strcmp(labels->lexeme, label_text))
				return(-1);
			labels = labels->next;
		}
	}
	return 0;	
}


int		parse_labels_declaration(t_data *data, t_code_line *code_line)
{
	t_code_line	*current_line;

	current_line = code_line;
	while (current_line)
	{
		if (is_label_only(current_line))
		{
			
			if (!(create_and_add_label(data, code_line)))
				return (-1);
		}
		current_line = current_line->next;
	}
	
	(void)data;
	(void)code_line;
	return (1);
}

void	labels_calls_computing(t_data *data, t_code_line *code_line)
{
	(void)data;
	(void)code_line;
}