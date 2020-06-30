/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 14:38:27 by nivergne          #+#    #+#             */
/*   Updated: 2019/02/13 17:56:45 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_size(int n)
{
	int	size;

	size = 0;
	if (n < 0)
	{
		n = -n;
		size++;
	}
	if (n == 0)
		return (1);
	while (n)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

static char	*ft_iota_core(unsigned int nb, int sign, int size)
{
	char	*result;

	if (!(result = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	result[size] = '\0';
	size--;
	if (sign == -1)
	{
		result[0] = '-';
		sign = 1;
	}
	while (nb >= 10)
	{
		result[size] = nb % 10 + '0';
		nb = nb / 10;
		size--;
	}
	result[size] = nb % 10 + '0';
	return (result);
}

char		*ft_itoa(int n)
{
	int				sign;
	int				size;
	unsigned int	nb;

	size = get_size(n);
	if (n >= 0)
	{
		nb = (unsigned int)n;
		sign = 0;
	}
	else
	{
		nb = (unsigned int)-n;
		sign = -1;
	}
	return (ft_iota_core(nb, sign, size));
}

/*
** DESCRIPTION
** Convert an integer to a string.
*/
