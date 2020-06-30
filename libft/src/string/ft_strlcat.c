/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/02 19:18:09 by nivergne          #+#    #+#             */
/*   Updated: 2018/11/13 15:09:15 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dst_size)
{
	size_t	i;
	size_t	dst_len;
	size_t	store;

	i = 0;
	dst_len = ft_strlen(dst);
	if (dst_size + ft_strlen(src) <= ft_strlen(src) + dst_len)
		return (ft_strlen(src) + dst_size);
	store = dst_len + ft_strlen(src);
	dst_size = dst_size - dst_len - 1;
	while (src[i] != '\0' && i < dst_size)
	{
		dst[i + dst_len] = src[i];
		i++;
	}
	dst[i + dst_len] = '\0';
	return (store);
}

/*
** DESCRIPTION
** Strlcat() functions copy and concatenate strings respectively.
** Strlcat() take the full size of the buffer (not just the length),
** and guarantee to NUL-terminate the result
** (as long as there is at least one byte free in dst).
** Note that a byte for the NUL should be included in size.
** Also note that strlcat() only operate on true ``C'' strings.
** This means that for strlcpy() src must be NUL-ter-minated
** and for strlcat() both src and dst must be NUL-terminated.
** The strlcat() function appends the string src to the end of dst.
** It will append at most size - strlen(dst) - 1 bytes,
** NUL-terminating the result.
** The source and destination strings should not overlap,
** as the behavior is undefined.
*/
