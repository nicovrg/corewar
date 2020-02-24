/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 15:30:12 by nivergne          #+#    #+#             */
/*   Updated: 2018/11/13 15:39:43 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		check_space(const char c, char separator)
{
	if (c == separator)
		return (1);
	return (0);
}

static int		num(const char *str, char separator)
{
	int i;
	int word_number;

	i = 0;
	word_number = 0;
	while (str[i] != '\0')
	{
		if (check_space(str[i], separator) == 1)
			i++;
		else
		{
			word_number++;
			while (check_space(str[i], separator) == 0 && str[i] != '\0')
				i++;
		}
	}
	return (word_number);
}

static int		word_size(char *str, char c)
{
	size_t		word_size;

	word_size = 0;
	while (str[word_size] && check_space(str[word_size], c) == 0)
		word_size++;
	return (word_size);
}

static char		*ft_copy(char **dst, char *src, char c)
{
	size_t		i;

	i = 0;
	while (src[i] && check_space(src[i], c) == 0)
	{
		dst[0][i] = src[i];
		i++;
	}
	dst[0][i] = '\0';
	return (*dst);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t		i;
	size_t		j;
	char		*y;
	char		**tab;

	i = 0;
	j = 0;
	y = (char *)s;
	if (s == NULL || !(tab = (char **)malloc(sizeof(char *) * (num(y, c) + 1))))
		return (NULL);
	while (s[i])
	{
		if (s[i] && check_space(s[i], c) == 0)
		{
			if (!(tab[j] = (char *)malloc(sizeof(char) * word_size(y + i, c))))
				return (NULL);
			tab[j] = ft_copy(&tab[j], &y[i], c);
			i = i + word_size(y + i, c);
			j++;
		}
		else
			i++;
	}
	tab[j] = 0;
	return (tab);
}

/*
** The strsplit() function allocate a table of "fresh" string,
** \0 terminated, resulting from the spliting
** of the string arround the separator c.
*/
