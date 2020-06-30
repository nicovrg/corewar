/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 18:30:37 by nivergne          #+#    #+#             */
/*   Updated: 2018/11/13 15:55:51 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*h_cpy;
	char	*n_cpy;

	i = 0;
	h_cpy = (char *)haystack;
	n_cpy = (char *)needle;
	if (n_cpy[0] == '\0')
		return (h_cpy);
	while (h_cpy[i] && i + ft_strlen(n_cpy) <= len)
	{
		j = 0;
		while (h_cpy[i + j] && h_cpy[i + j] == n_cpy[j] && j < len)
		{
			if (n_cpy[j + 1] == '\0')
				return (h_cpy + i);
			j++;
		}
		i++;
	}
	return (NULL);
}

/*
** The strnstr() function locates the first occurrence of the null-terminated
** string needle in the string haystack, where not more than len characters
** are searched. Characters that appear after a `\0' character are not searched.
** Since the strnstr() function is a FreeBSD specific API,
** it should only be used when portabil-ity is not a concern.
*/
