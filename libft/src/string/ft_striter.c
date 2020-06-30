/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 15:54:14 by nivergne          #+#    #+#             */
/*   Updated: 2018/11/13 14:39:15 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striter(char *s, void (*f)(char *))
{
	size_t		i;

	i = 0;
	if (s != NULL && f != NULL)
	{
		while (s[i])
		{
			f(&s[i]);
			i++;
		}
	}
}

/*
** DESCRIPTION
** Strcmp() lexicographically compare the null-terminated strings s1 and s2.
**
** RETURN VALUES
** Strcmp() return an the difference between s1 and s2.
** The comparison is done using unsigned characters,
** so that `\200' is greater than `\0'.
*/
