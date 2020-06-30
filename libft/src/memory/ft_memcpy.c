/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 19:22:42 by nivergne          #+#    #+#             */
/*   Updated: 2019/02/13 17:58:47 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dst);
}

/*
** DESCRIPTION
** Memcpy function copies n bytes from memory area src to memory area dst.
** If dst and src overlap, behavior is undefined.
** Applications in which dst and src might overlap should use memmove instead.
**
** RETURN VALUES
** The memcpy() function returns the original value of dst.
*/
