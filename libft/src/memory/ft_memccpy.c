/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 22:46:26 by nivergne          #+#    #+#             */
/*   Updated: 2019/02/13 17:59:18 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	i;

	i = 0;
	if (dst != NULL || src != NULL)
	{
		while (i < n)
		{
			((unsigned char *)dst)[i] = ((unsigned char*)src)[i];
			if (((unsigned char *)src)[i] == (unsigned char)c)
				return ((unsigned char *)dst + i + 1);
			i++;
		}
	}
	return (NULL);
}

/*
** DESCRIPTION
** The memccpy() function copies bytes from string src to string dst.
** If the character c (as converted to an unsigned char)
** occurs in the string src, the copy stops and a pointer to
** the byte after the copy of c in the string dst is returned.
**
** Otherwise, n bytes are copied, and a NULL pointer is returned.
** The source and destination strings should not overlap,
** as the behavior is undefined.
*/
