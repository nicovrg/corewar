/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_header_info_two.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 23:44:32 by amamy             #+#    #+#             */
/*   Updated: 2020/02/08 20:30:14 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include "asm.h"
#include "libft.h"
#include "ft_printf.h"

/*
** ==================== is_dirty ====================
** This function check if the string passed in argument contain other things
** than whitespaces or comments. If yes, return an false, else return true
*/

int		is_dirty(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		while (str[i] && is_whitespace(str[i]))
			i++;
		if (str[i] == '#' || !str[i])
			return (0);
		else
			return (1);
		i++;
	}
	return (0);
}

/*
** ==================== get_string_child ====================
** This function look for the second quote of the string.
** If there is a second quote, check if there is trash
** after (something that is not a comment) and return an error if so.
** If there is no trash, then copy the string in the data structure
*/

int		get_string_child(t_data **data, char *str, int mode, int i)
{
	int j;

	j = 0;
	while (str[i + j] && str[i + j] != '\"')
		j++;
	if (!str[i + j] || is_dirty(&str[i + j + 1]))
		return (0);
	else
	{
		if (mode == 1)
			(*data)->name = ft_strndup(&str[i], j);
		else if (mode == 2)
			(*data)->comment = ft_strndup(&str[i], j);
		return (1);
	}
}

/*
** ==================== get_string ====================
** This function copy a string. It first skip all the whitespaces
** Then check if there is a quote. If no, return an error, if yes
** call the core function to strndup the string
*/

int		get_string(t_data **data, char *str, int mode)
{
	int i;

	i = 0;
	while (str[i])
	{
		while (str[i] && is_whitespace(str[i]))
			i++;
		if (str[i] && str[i++] == '\"')
			return (get_string_child(data, str, mode, i));
		else
			return (0);
		i++;
	}
	return (0);
}
