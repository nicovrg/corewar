/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_lib.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasv <nicolasv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 03:50:53 by nicolasv          #+#    #+#             */
/*   Updated: 2020/01/27 01:46:06 by nicolasv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "asm.h"
#include "libft.h"

char	*ft_strndup(const char *s1, ssize_t len)
{
	ssize_t	counter;
	char	*sdest;

	counter = 0;
	if (!(sdest = (char *)ft_memalloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (s1[counter] != '\0' && counter < len)
	{
		sdest[counter] = s1[counter];
		counter++;
	}
	sdest[counter] = '\0';
	return (sdest);
}

int ft_isnumber(char *num)
{
	int	i;

	i = 0;
	while (ft_isdigit(num[i]))
		i++;
	if (num[i])
		return (0);
	else
		return (1);

}

int		ft_lowercase(int c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	return (0);
}

int		is_whitespace(char c)
{
	if ((c >= 9 && c <= 13) || c == ' ')
		return (1);
	return (0);
}
