/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_check_instructions_size.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 15:17:51 by qgirard           #+#    #+#             */
/*   Updated: 2020/02/11 01:20:26 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include "libft.h"

/*
** ==================== reverse_bits ====================
** reverse bits, 0 become 1 and 1 become 0
*/

static int		reverse_bits(int *i, char **tmp)
{
	*i = 0;
	while (*tmp && (*tmp)[*i])
	{
		if ((*tmp)[*i] == '0')
			(*tmp)[*i] = '1';
		else
			(*tmp)[*i] = '0';
		*i = *i + 1;
	}
	return (1);
}

/*
** ==================== two_complement ====================
** this function make the two's complement of kobe
*/

static int		two_complement(int kobe)
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
	reverse_bits(&i, &tmp);
	kobe = ft_atoi_base(tmp, 2) + 1;
	ft_strdel(&tmp);
	return (kobe);
}

/*
** ==================== increment_values ====================
** increment values of function check_instructions_size
*/

static int		increment_values(int *kobe, int *byte)
{
	*kobe = *kobe - 1;
	*byte = *byte + 1;
	return (1);
}

/*
** ==================== init_values ====================
** init values of function check_instructions_size
*/

static int		init_values(int *index, int *i, char *line, char **buff)
{
	(*index) = *i;
	*buff = NULL;
	while (!line[(*index)] && (*index) - *i < 4)
		(*index)++;
	*i = *i + 3;
	if (*i >= (*index) && line[(*index)])
		if (!(*buff = ft_strsub(line, (*index), *i - (*index) + 1)))
			return (0);
	return (1);
}

/*
** ==================== instruction size ====================
** faire la gestion d'erreur si size > max_champ_size
*/

int				check_instructions_size(char *line, t_header_state *state,
int *i, t_champion **tmp)
{
	int		kobe;
	int		byte;
	int		index;
	char	*buff;

	byte = 0;
	if ((!init_values(&index, i, line, &buff) || *state == HEADER_ERROR))
		return (error_msg(ERR_MALLOC, 0, state));
	if (buff)
	{
		kobe = ft_strlen(buff) - 1;
		while (kobe >= 0)
		{
			if ((int)buff[kobe] < 0)
				(*tmp)->size = (*tmp)->size + ft_power(256, byte)
				* (unsigned int)two_complement(-(buff[kobe]));
			else
				(*tmp)->size = (*tmp)->size + ft_power(256, byte)
				* (unsigned int)buff[kobe];
			increment_values(&kobe, &byte);
		}
	}
	ft_strdel(&buff);
	*state = HEADER_PARSING_COMMENT;
	return (1);
}
