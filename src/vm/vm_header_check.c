/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_header_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 03:15:38 by qgirard           #+#    #+#             */
/*   Updated: 2020/01/28 18:40:07 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include "op.h"
#include "libft.h"
#include "ft_printf.h"

static int			check_paddings(char *line, int *i, int size)
{
	while (*i < size)
	{
		if ((int)(line[*i]) != 0)
			return (0);
		*i = *i + 1;
	}
	return (1);
}

/*
** ==================== check_comments ====================
** check and stock the comment of the champion
*/

static int			check_comments(char *line, enum header *state, int *i,
t_champion **tmp)
{
	int			index;

	*i = *i + 1;
	index = *i;
	while (line[index])
		index++;
	if (!((*tmp)->comment = ft_strsub(line, *i, index - *i)))
		return (error_msg(ERR_MALLOC, 0));
	*state = padding;
	*i = index;
	if (!check_paddings(line, i, HEADER_SIZE))
		return (error_msg(ERR_FILE_HEADER, 0));
	return (1);
}

/*
** ==================== check_name ====================
** check and stock the name of the champion
*/

static t_champion	*check_name(char *line, enum header *state, int *i,
t_champion **champions)
{
	int			index;
	t_champion	*tmp;

	index = *i;
	if (!(tmp = champions_list(champions)))
	{
		error_msg(ERR_MALLOC, 0);
		return (NULL);
	}
	while (line[index])
		index++;
	if (!(tmp->name = ft_strsub(line, *i, index - *i)))
	{
		error_msg(ERR_MALLOC, 0);
		return (NULL);
	}
	*state = instructions_size;
	*i = index;
	if (!check_paddings(line, i, BYTE_AFTER_PADDING))
	{
		error_msg(ERR_FILE_HEADER, 0);
		return (NULL);
	}
	return (tmp);
}

/*
** ==================== magic_number ====================
** check the magic number of the champion file if this one is incorrect
** return an error
*/

static int			magic_number(char *line, enum header *state, int *i)
{
	if ((unsigned int)line[*i] == MAGIC_NUMBER_PT_1
	&& (unsigned int)line[*i + 1] == MAGIC_NUMBER_PT_2
	&& (unsigned int)line[*i + 2] == MAGIC_NUMBER_PT_3
	&& (unsigned int)line[*i + 3] == MAGIC_NUMBER_PT_4)
	{
		*i = *i + 4;
		*state = name;
	}
	else
		return (0);
	return (1);
}

/*
** ==================== header_check ====================
** check the state that inform us in which part of the header we are
** and then display to specified checking functions
*/

int					header_check(t_corewar *stock, char *line,
t_champion **champions)
{
	int			i;
	t_champion	*tmp;
	enum header	state;

	i = 0;
	state = magic_nb;
	while (i < HEADER_SIZE)
	{
		if (state == magic_nb)
			if (!(magic_number(line, &state, &i)))
				return (error_msg(ERR_FILE_HEADER, 0));
		if (state == name)
			if (!(tmp = check_name(line, &state, &i, champions)))
				return (0);
		if (state == instructions_size)
			if (!(check_instructions_size(line, &state, &i, &tmp)))
				return (0);
		if (state == comment)
			if (!(check_comments(line, &state, &i, &tmp)))
				return (0);
		i++;
	}
	if (stock->nb_player)
		add_nb_player(stock, champions, &tmp);
	return (1);
}
