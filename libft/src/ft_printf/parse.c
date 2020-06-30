/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquivogn <jquivogn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 19:01:31 by nivergne          #+#    #+#             */
/*   Updated: 2019/02/11 14:46:10 by jquivogn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		check_flag(char c, t_info *o)
{
	if (c == '0')
		o->zero = 1;
	else if (c == '+')
		o->plus = 1;
	else if (c == '-')
		o->minus = 1;
	else if (c == ' ')
		o->space = 1;
	else if (c == '#')
		o->hashtag = 1;
	if (c == ' ' || c == '-' || c == '+' || c == '#' || c == '0')
		return (1);
	return (0);
}

int		check_width(char c, t_info *o)
{
	if (c >= '0' && c <= '9')
	{
		if (o->width == -1)
			o->width = c - '0';
		else
			o->width = o->width * 10 + c - '0';
		return (1);
	}
	return (0);
}

int		check_accuracy_one(char c, t_info *o)
{
	if (c == '.')
	{
		o->accuracy = 0;
		return (1);
	}
	return (0);
}

int		check_accuracy_two(char c, t_info *o)
{
	if (c >= '0' && c <= '9')
	{
		o->accuracy = o->accuracy * 10 + c - '0';
		return (1);
	}
	return (0);
}

int		check_conversion(char c, t_info *o)
{
	int		i;
	char	*str;

	i = 0;
	str = "cspdiouxXbf%aCSPDIOU";
	while (str[i])
	{
		if (c == str[i])
		{
			i > 12 ? o->type = 4 : 0;
			o->conversion = i;
			return (1);
		}
		i++;
	}
	return (0);
}
