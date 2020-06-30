/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 17:07:04 by nivergne          #+#    #+#             */
/*   Updated: 2018/11/13 15:19:37 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(const char *s, char (*f)(char))
{
	size_t		i;
	size_t		s_len;
	char		*new;

	if (s != NULL && f != NULL)
	{
		i = 0;
		s_len = ft_strlen(s);
		if (!(new = (char *)malloc(sizeof(char) * s_len + 1)))
			return (NULL);
		while (i < s_len)
		{
			new[i] = (char)f(*(s + i));
			i++;
		}
		new[i] = '\0';
		return (new);
	}
	return (NULL);
}

/*
** DESCRIPTION
** Apply the f function to each character of the string,
** creating a new "fresh" string.
*/
