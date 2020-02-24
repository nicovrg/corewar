/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 15:02:00 by nivergne          #+#    #+#             */
/*   Updated: 2018/11/07 19:27:31 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char *cpy;

	cpy = NULL;
	cpy = (char *)malloc(ft_strlen(s1) + 1);
	if (cpy != NULL)
		ft_strcpy(cpy, s1);
	return (cpy);
}

/*
** DESCRIPTION
** The strdup() function allocates sufficient memory,
** for a copy of the string s1, does the copy, and returns a pointer to it.
**
** The pointer may subsequently be used as,
** an argument to the function free(3).
**
** If insufficient memory is available,
** NULL is returned and errno is set to ENOMEM.
**
** The strndup() function copies at most n characters,
** from the string s1 always NUL terminating the copied string.
*/
