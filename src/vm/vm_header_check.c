/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_header_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 03:15:38 by qgirard           #+#    #+#             */
/*   Updated: 2020/01/22 06:56:45 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include "libft.h"

static int			check_instructions_size(char *line, enum header *state, int *i,
t_champion **tmp)
{
	*state = comment;
	*i = *i + 4;
	return (1);
}

static t_champion	*check_name(char *line, enum header *state, int *i,
t_champion **champions)
{
	int			index;
	t_champion	*tmp;

	index = *i;
	if (!(tmp = champions_list(champions)))
		return (NULL);
	while (line[index])
		index++;
	if (!(tmp->name = ft_strsub(line, *i, index - *i)))
		return (NULL);
	*state = instructions_size;
	// *state = padding1;
	*i = BYTE_AFTER_PADDING;
	return (tmp);
}

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

int					header_check(char *line, t_champion **champions)
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
				return (error_msg(ERR_MALLOC, 0));
		if (state == instructions_size)
			if (!(check_instructions_size(line, &state, &i, &tmp)))
				return (0);
		i++;
	}
	return (1);
}
