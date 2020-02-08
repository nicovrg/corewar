/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_lib.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 03:50:53 by nicolasv          #+#    #+#             */
/*   Updated: 2020/02/08 20:34:46 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "asm.h"
#include "libft.h"

void	ft_putstrn(char const *s, int size)
{
	if (s != NULL)
		write(1, s, size);
}

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

int		ft_lowercase(int c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	return (0);
}

/*
** ==================== is_digit ====================
** if the string is only composed by ascii digit return 1
** otherwise return 0
*/

int		is_number(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
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
** ==================== is_comment_char ====================
** This function check if the character passed in argument is a #.
** If yes, return an false, else return true
*/

int		is_comment_char(char c)
{
	if (c == '#')
		return (1);
	return (0);
}

/*
** ==================== is_str_whitespace_or_comment ====================
** This function return 1 if the string is full of whitespaces
** or if it is a comment and 0 otherwise.
*/

int			is_str_whitespace_or_comment(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '#')
			return (1);
		if (!((str[i] >= 9 && str[i] <= 13) || str[i] == ' '))
			return (0);
		i++;
	}
	return (1);
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
