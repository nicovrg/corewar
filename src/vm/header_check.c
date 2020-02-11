/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 03:15:38 by qgirard           #+#    #+#             */
/*   Updated: 2020/02/10 23:50:55 by amamy            ###   ########.fr       */
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
** check and arena the comment of the champion
*/

static int			check_comments(char *line, t_header *state, int *i,
t_champion **tmp)
{
	int			index;

	*i = *i + 1;
	index = *i;
	if (state[0] == HEADER_ERROR)
		return (0);
	while (line[index])
		index++;
	if (!((*tmp)->comment = ft_strsub(line, *i, index - *i)))
		return (error_msg(ERR_MALLOC, 0, state));
	*state = HEADER_PARSING_PADDING;
	*i = index;
	if (!check_paddings(line, i, HEADER_SIZE))
		return (error_msg(ERR_FILE_HEADER, 0, state));
	return (1);
}

/*
** ==================== check_name ====================
** check and arena the name of the champion
*/

static t_champion	*check_name(char *line, t_header *state, int *i,
t_champion **champions)
{
	int			index;
	t_champion	*tmp;

	index = *i;
	if (state[0] == HEADER_ERROR)
		return (0);
	if (!(tmp = champions_list(champions)))
		error_msg_null(ERR_MALLOC, state);
	while (line[index])
		index++;
	if (!(tmp->name = ft_strsub(line, *i, index - *i)))
		error_msg_null(ERR_MALLOC, state);
	*state = HEADER_PARSING_INSTRUCTION_SIZE;
	*i = index;
	if (!check_paddings(line, i, BYTE_AFTER_PADDING))
		error_msg_null(ERR_MALLOC, state);
	return (tmp);
}

/*
** ==================== magic_number ====================
** check the magic number of the champion file if this one is incorrect
** return an error
*/

static int			magic_number(char *line, t_header *state, int *i)
{
	if (state[0] == HEADER_ERROR)
		return (0);
	if ((unsigned int)line[*i] == MAGIC_NUMBER_PT_1
	&& (unsigned int)line[*i + 1] == MAGIC_NUMBER_PT_2
	&& (unsigned int)line[*i + 2] == MAGIC_NUMBER_PT_3
	&& (unsigned int)line[*i + 3] == MAGIC_NUMBER_PT_4)
	{
		*i = *i + 4;
		*state = HEADER_PARSING_NAME;
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

int					header_check(t_corewar *arena, char *line,
t_champion **champions)
{
	int			i;
	t_champion	*tmp;
	t_header	state;

	i = 0;
	state = HEADER_PARSING_MAGIC_NB;
	while (i < HEADER_SIZE)
	{
		if (state == HEADER_PARSING_MAGIC_NB && state != HEADER_ERROR)
			magic_number(line, &state, &i);
		if (state == HEADER_PARSING_NAME && state != HEADER_ERROR)
			tmp = check_name(line, &state, &i, champions);
		if (state == HEADER_PARSING_INSTRUCTION_SIZE && state != HEADER_ERROR)
			check_instructions_size(line, &state, &i, &tmp);
		if (state == HEADER_PARSING_COMMENT && state != HEADER_ERROR)
			check_comments(line, &state, &i, &tmp);
		if (state == HEADER_ERROR)
			return (error_msg(ERR_FILE_HEADER, 0, NULL));
		i++;
	}
	if (arena->nb_player)
		add_nb_player(arena, champions, &tmp);
	if (!(tmp->instructions = ft_strndup(&line[INSTRUCTION_SECTION_START], CHAMP_MAX_SIZE)))
		return (0);
	return (1);
}
