/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   label_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takoumys <takoumys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 23:58:28 by amamy             #+#    #+#             */
/*   Updated: 2020/02/26 23:28:32 by takoumys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"
#include "tokens.h"
#include "ft_printf.h"

static t_code_line	*fetch_label_target(t_code_line *code_line)
{
	t_code_line *tmp;

	tmp = code_line;
	if (is_only_label(code_line))
	{
		if (code_line->next->nb_token > 1)
			return (code_line->next);
		while (is_only_label(tmp))
			tmp = tmp->next;
		return (tmp);
	}
	else
		return (code_line);
}

static int	create_and_add_label(t_data *data, t_code_line *code_line, char *label)
{
	t_label *new_label;
	t_label *current_label;


	if (!(new_label = ft_memalloc(sizeof(t_label))))
		return (-1);
	if (!(code_line->token->values = ft_memalloc(sizeof(t_type))))
		return (-1);
	new_label->lexeme = label;
	new_label->target = fetch_label_target(code_line);
	code_line->token->values ->label = new_label;
	if (!data->label_list)
	{
		ft_printf("FIRST label: |%s| \n", label);
		data->label_list = new_label;
	}
	else
	{
		current_label = data->label_list;
		while (current_label->next)
			current_label = current_label->next;
		current_label->next = new_label;
		ft_printf("adding new label : |%s|\n", label);
	}
	return (1);
}

static int	check_redefinition(t_label *label_list, char *label)
{
	while (label_list)
	{

		if (!ft_strcmp(label_list->lexeme, label))
			return(0);
		label_list = label_list->next;
	}
	return (1);
}

static char	*get_label_text(t_code_line *code_line)
{
	char *label;

	if (!(label = ft_strndup(&code_line->line[code_line->token->position], code_line->token->length - 1)))
		return (NULL);
	return (label);
}

int		is_only_label(t_code_line *code_line)
{
	// ft_printf("code_line->nb_token : %d\n", code_line->nb_token);
	if (code_line->token->type == TOKEN_TYPE_LABEL \
	&& code_line->nb_token == 1)
	{
		// ft_printf("%s\n", "is_ONLY_label");
		return (1);
	}
	return (0);
}
int		is_label_declaration(t_code_line *code_line)
{
	// ft_printf("code_line->nb_token : %d\n", code_line->nb_token);
	if (code_line->token->type == TOKEN_TYPE_LABEL)
	{
		// ft_printf("%s\n", "is_label");
		return (1);
	}
	return (0);
}

int		parse_labels_declaration(t_data *data, t_code_line *code_line)
{
	char		*label_text;
	t_code_line	*current_line;

	current_line = code_line;
	while (current_line)
	{
		if (is_label_declaration(current_line))
		{
			if (!(label_text = get_label_text(current_line)))
				return (-1);
			if (!check_redefinition(data->label_list, label_text))
			{
				ft_printf("REDEFINITION : |%s|\n", label_text);
				return (0);
			}
			if (!(create_and_add_label(data, code_line, label_text)))
				return (-1);
		}
		current_line = current_line->next;
	}
	print_labels(data);
	return (1);
}

void	labels_calls_computing(t_data *data, t_code_line *code_line)
{
	(void)data;
	(void)code_line;
}
