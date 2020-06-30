/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_csp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquivogn <jquivogn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 22:11:13 by nivergne          #+#    #+#             */
/*   Updated: 2019/02/08 19:14:29 by jquivogn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		addwidth_char(int nb, t_info *o)
{
	while (nb > 1)
	{
		append_to_buff(o->zero && !o->minus && o->accuracy < 0
		? '0' : ' ', 0, o);
		nb--;
	}
}

void		addwidth_string(int nb, char *cast_ap, t_info *o)
{
	int	len;
	int	size;

	size = ft_strlen(cast_ap);
	if (o->accuracy > 0)
		len = nb - (size > o->accuracy ? o->accuracy : size);
	else if (o->accuracy == -1)
		len = nb - size;
	else
		len = nb;
	while (len > 0)
	{
		append_to_buff(o->zero && !o->minus && o->accuracy < 0
		? '0' : ' ', 0, o);
		len--;
	}
}

void		char_null(int cast_ap, t_info *o)
{
	if (o->minus == 0)
	{
		addwidth_char(o->width, o);
		append_to_buff(0, 1, o);
		write(1, &cast_ap, 1);
	}
	else if (o->minus == 1)
	{
		append_to_buff(0, 1, o);
		write(1, &cast_ap, 1);
		addwidth_char(o->width, o);
		append_to_buff(0, 1, o);
	}
	o->ret++;
}

char		*string_for_null(char *cast)
{
	const char	str[] = "(null)";

	cast = (char *)str;
	return (cast);
}
