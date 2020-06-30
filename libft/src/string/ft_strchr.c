/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 16:00:12 by nivergne          #+#    #+#             */
/*   Updated: 2018/11/13 12:44:42 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t		i;
	char		chr;
	char		*s_cpy;

	i = 0;
	chr = (char)c;
	s_cpy = (char *)s;
	while (s[i])
	{
		if (s[i] == chr)
			return (s_cpy + i);
		i++;
	}
	if (s[i] == '\0' && chr == '\0')
		return (s_cpy + i);
	else
		return (NULL);
}

/*
** DESCRIPTION
** The strchr() function locates the first occurrence of c (converted to a char)
** in the string pointed to by s.  The terminating null character
** is considered to be part of the string;
** therefore if c is `\0', the functions locate the terminating `\0'.
** The strrchr() function is identical to strchr(),
** except it locates the last occurrence of c.
**
** RETURN VALUES
** The functions strchr() and strrchr() return a pointer to
** the located character, or NULL if the char does not appear in the string.
*/
