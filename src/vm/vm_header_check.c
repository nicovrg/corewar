/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_header_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 03:15:38 by qgirard           #+#    #+#             */
/*   Updated: 2020/01/24 20:50:42 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include "op.h"
#include "libft.h"
#include "ft_printf.h"

static int			reverse_bits(int kobe)
{
	int		i;
	char	*buff;
	char	*tmp;

	i = 0;
	tmp = NULL;
	if (!(buff = ft_itoa_base(kobe, 2)))
		return (0);
	while (i < (int)(8 - ft_strlen(buff)))
	{
		if (!tmp)
			tmp = ft_strdup("0");
		else
			tmp = ft_strjoinf(tmp, "0", 1);
		i++;
	}
	tmp = ft_strjoinf(tmp, buff, 3);
	i = 0;
	while (tmp && tmp[i])
	{
		if (tmp[i] == '0')
			tmp[i] = '1';
		else
			tmp[i] = '0';
		i++;
	}
	i--;
	while (i > 0)
	{
		if (tmp[i] == '0')
		{
			tmp[i] = '1';
			i = 0;
		}
		else
			tmp[i] = '0';
		i--;
	}
	kobe = ft_atoi_base(tmp, 2);
	ft_strdel(&tmp);
	return (kobe);
}

static int			check_instructions_size(char *line, enum header *state,
int *i, t_champion **tmp)
{
	int		kobe;
	int		byte;
	int		index;
	char	*buff;

	index = *i;
	buff = NULL;
	byte = 0;
	while (!line[index] && index - *i < 4)
		index++;
	*i = *i + 3;
	if (*i >= index && line[index])
		buff = ft_strsub(line, index, *i - index + 1);
	if (buff)
	{
		kobe = ft_strlen(buff) - 1;
		while (kobe >= 0)
		{
			if ((int)buff[kobe] < 0)
				(*tmp)->size = (*tmp)->size + ft_power(256, byte)
				* (unsigned int)reverse_bits(-(buff[kobe]));
			else
				(*tmp)->size = (*tmp)->size + ft_power(256, byte) * (unsigned int)buff[kobe];
			kobe--;
			byte++;
		}
	}
	ft_strdel(&buff);
	*state = comment;
	return (1);
}

static int			check_comments(char *line, enum header *state, int *i, t_champion **tmp)
{
	int			index;

	*i = *i + 1;
	index = *i;
	while (line[index])
		index++;
	if (!((*tmp)->comment = ft_strsub(line, *i, index - *i)))
		return (0);
	*state = padding;
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

int					header_check(t_corewar *stock, char *line, t_champion **champions)
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
		if (state == comment)
			if (!(check_comments(line, &state, &i, &tmp)))
				return (error_msg(ERR_MALLOC, 0));				
		i++;
	}
	add_nb_player(stock, &tmp);
	return (1);
}

/*
** ==================== instruction size ====================
** faire la gestion d'erreur si size > max_champ_size
*/