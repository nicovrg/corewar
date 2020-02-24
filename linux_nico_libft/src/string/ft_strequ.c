/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 17:14:26 by nivergne          #+#    #+#             */
/*   Updated: 2018/11/13 14:36:10 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	size_t		i;

	if (s1 != NULL && s2 != NULL)
	{
		i = 0;
		while (s1[i] && s2[i] && s1[i] == s2[i])
			i++;
		if (s1[i] == '\0' && s2[i] == '\0')
			return (1);
		return (0);
	}
	return (0);
}

/*
** DESCRIPTION
** Strequ() lexicographically compare the null-terminated strings s1 and s2.
** If s1 == s2 return 1, else return 0.
*/
