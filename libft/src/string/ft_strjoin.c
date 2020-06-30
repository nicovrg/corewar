/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 19:02:33 by nivergne          #+#    #+#             */
/*   Updated: 2018/11/13 15:01:15 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*join;

	if (s1 != NULL && s2 != NULL)
	{
		i = 0;
		j = 0;
		if (!(join = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
			return (NULL);
		while (s1[i])
		{
			join[i] = s1[i];
			i++;
		}
		while (s2[j])
		{
			join[i + j] = s2[j];
			j++;
		}
		join[i + j] = '\0';
		return (join);
	}
	return (NULL);
}

/*
** DESCRIPTION
** Strjoin is a concatenation function, using a malloc unlike strcat.
*/
