/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 00:09:20 by nivergne          #+#    #+#             */
/*   Updated: 2019/02/13 17:59:51 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*s_cpy;

	i = 0;
	s_cpy = (unsigned char *)s;
	while (i < n)
	{
		if (s_cpy[i] == (unsigned char)c)
			return (s_cpy + i);
		i++;
	}
	return (NULL);
}

/*
** DESCRIPTION
** The memchr() function locates the first occurrence of c
** (converted to an unsigned char) in string s.
**
** RETURN VALUES
** The memchr() function returns a pointer to the byte located,
** or NULL if no such byte exists within n bytes.
*/
