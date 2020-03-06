/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_lib.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 22:04:12 by amamy             #+#    #+#             */
/*   Updated: 2020/03/07 00:18:37 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "vm.h"
#include "op.h"
#include "libft.h"
#include "ft_printf.h"

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

char	*ft_strjoinf(char *s1, char *s2, size_t rm)
{
	char			*new_s;
	unsigned int	i;
	unsigned int	j;
	int				tmp;

	tmp = 0;
	if ((int)rm < 0 || (int)rm > 3)
		return (NULL);
	if (!s2)
	{
		tmp = 1;
		s2 = ft_strdup("(null)");
	}
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	if ((new_s = ft_strnew(i + j)) == NULL)
		return (NULL);
	ft_strcpy(new_s, s1);
	ft_strcat(new_s, s2);
	if (rm == 1 || rm == 3)
		ft_strdel(&s1);
	if ((rm == 2 || rm == 3 || (!ft_strcmp(s2, "(null)") && tmp == 1)))
		ft_strdel(&s2);
	return (new_s);
}


// ===============THIS IS ITOA BASE SHIT ===============
static char	*ft_converter(int n, long i, long j, int base)
{
	char *str;

	if (!(str = (char *)malloc(sizeof(*str) * i + 1)))
		return (NULL);
	str[j] = '\0';
	j--;
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	if (n == 0)
		str[j] = '0';
	while (n != 0)
	{
		if (n % base < 10)
			str[j] = n % base + '0';
		else
			str[j] = n % base - 10 + 'a';
		n = n / base;
		j--;
	}
	return (str);
}

char		*ft_itoa_base(int n, int base)
{
	long	i;
	long	j;
	long	k;

	i = 0;
	k = n;
	if (n == -2147483648 && base == 10)
		return (ft_strdup("-2147483648"));
	if (n <= 0)
		i = 1;
	while (k != 0)
	{
		k = k / base;
		i++;
	}
	j = i;
	return (ft_converter(n, i, j, base));
}

int		ft_atoi_base(const char *str, int base)
{
	size_t		i;
	int			sign;
	size_t		result;

	i = 0;
	sign = 1;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * base + str[i] - '0';
		if (sign == 1 && result > __INT64_MAX__)
			return (-1);
		if (sign == -1 && result > (size_t)(__INT64_MAX__) + 1)
			return (0);
		i++;
	}
	return ((int)result * sign);
}