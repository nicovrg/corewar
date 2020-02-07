/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_lib.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 03:50:53 by nicolasv          #+#    #+#             */
/*   Updated: 2020/02/06 23:15:55 by amamy            ###   ########.fr       */
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

/*
** ==================== count_tokens ====================
** This function count the number of token in one line
** If there are multiples commas following each others, return an error
*/

// static int			count_tokens(char *line)
// {
// 	int i;
// 	int j;
// 	int ret;

// 	i = 0;
// 	ret = 0;
// 	if (ft_strnstr(line, ",,", ft_strlen(line)))
// 		return (error_msg("invalid line, multiples commas in a row", -1));
// 	while (line[i])
// 	{
// 		j = 0;
// 		while (line[i] && is_whitespace(line[i]))
// 			i++;
// 		while (line[i + j] && (!is_whitespace(line[i + j]) && !is_comma(line[i + j])))
// 		{
// 			if (is_comment_char(line[i + j]))
// 				return (ret);
// 			j++;
// 		}
// 		(line[i + j - 1] > 0 && is_comma(line[i + j - 1])) ? (j++) : (0);
// 		(line[i + j - 1] > 0 && is_comma(line[i + j - 1])) ? (ret++) : (0);
// 		(j == 0) ? (i++) : (i = i + j);
// 		ret++;
// 	}
// 	return (ret);
// }

