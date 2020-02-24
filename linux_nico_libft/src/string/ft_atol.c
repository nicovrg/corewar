/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasv <nicolasv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 02:28:01 by nicolasv          #+#    #+#             */
/*   Updated: 2019/09/21 02:28:10 by nicolasv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static long	realatol(const char *str, long i, long j, long k)
{
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\r' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == ' ')
		i++;
	if ((str[i] == '-') && (str[i + 1] >= 48 && str[i + 1] <= 57))
	{
		j = -1;
		i++;
	}
	if ((str[i] == '+') && (str[i + 1] >= 48 && str[i + 1] <= 57))
		i++;
	while (str[i] >= 48 && str[i] <= 57)
	{
		if (k > 2147483647 && j == 1)
			return (2147483649);
		if (k > 2147483648 && j == -1)
			return (2147483649);
		k = k * 10 + str[i] - '0';
		i++;
	}
	return (k * j);
}

long		ft_atol(const char *str)
{
	long i;
	long k;
	long j;

	i = 0;
	k = 0;
	j = 1;
	return (realatol(str, i, j, k));
}
