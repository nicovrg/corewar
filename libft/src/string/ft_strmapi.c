/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 22:52:42 by nivergne          #+#    #+#             */
/*   Updated: 2018/11/13 15:20:02 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	size_t			s_len;
	char			*new;

	if (s != NULL && f != NULL)
	{
		i = 0;
		new = NULL;
		s_len = ft_strlen(s);
		if (!(new = (char *)malloc(sizeof(char) * s_len + 1)))
			return (NULL);
		while (i < s_len)
		{
			new[i] = f(i, s[i]);
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
** precising the index, creating a new "fresh" string.
*/
