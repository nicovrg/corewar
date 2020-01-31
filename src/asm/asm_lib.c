/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_lib.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 03:50:53 by nicolasv          #+#    #+#             */
/*   Updated: 2020/01/31 18:12:57 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "asm.h"
#include "libft.h"

char	*ft_strndup(const char *s1, ssize_t len)
{
	ssize_t	counter;
	char	*sdest;

	counter = 0;
	if (!(sdest = (char *)ft_memalloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (s1[counter] != '\0' && counter < len)
	{
		sdest[counter] = s1[counter];
		counter++;
	}
	sdest[counter] = '\0';
	return (sdest);
}

int ft_isnumber(char *num)
{
	int	i;

	i = 0;
	while (ft_isdigit(num[i]))
		i++;
	if (num[i])
		return (0);
	else
		return (1);

}

int		ft_lowercase(int c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	return (0);
}

/*
** ==================== is_whitespace ====================
** say if the char is a whitespace character
** whitespaces char are in ascii decimal (9, 10, 11, 12, 13 and 32)
*/

int		is_whitespace(char c)
{
	if ((c >= 9 && c <= 13) || c == ' ')
		return (1);
	return (0);
}

/*
** ==================== is_comment ====================
** This function check if the character passed in argument is a #.
** If yes, return an false, else return true
*/


//SHould be renamed "is_separator_char"
int		is_comment(char c)
{
	if (c == '#')
		return (1);
	return (0);
}

/*
** ==================== is_comma ====================
** This function check if the character passed in argument is a ,.
** If yes, return an false, else return true
*/

int		is_comma(char c)
{
	if (c == ',')
		return (1);
	return (0);
}