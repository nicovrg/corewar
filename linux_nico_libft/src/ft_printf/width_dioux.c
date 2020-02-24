/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_dioux.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 22:11:15 by nivergne          #+#    #+#             */
/*   Updated: 2019/02/11 19:54:12 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			width_size_diou(t_info *o, long long cast_ap, int base)
{
	int width;
	int size_nb;

	o->fnull = o->accuracy == 0 ? 0 : 1;
	size_nb = cast_ap == 0 ? 1 : 0;
	width = o->width;
	cast_ap < 0 ? size_nb++ : 0;
	cast_ap < 0 ? cast_ap *= -1 : 0;
	while (cast_ap > 0)
	{
		cast_ap /= base;
		size_nb++;
	}
	width = width - (o->accuracy > size_nb ? o->accuracy : size_nb)
		- (o->plus && !o->neg ? 1 : 0) - (o->neg ? 1 : 0)
		- (o->space == 1 && !o->plus && !o->neg ? 1 : 0);
	if (o->accuracy != -1)
	{
		if (o->accuracy - size_nb < 0)
			o->accuracy = 0;
		else
			o->accuracy = o->accuracy - size_nb;
	}
	return (width);
}

int			width_size_x(t_info *o, char *cast_ap)
{
	int width;
	int accuracy;
	int size;

	width = o->width;
	accuracy = o->accuracy;
	size = ft_strlen(cast_ap);
	if (o->hashtag == 1)
		o->hashtag = 2;
	width = width - (accuracy > size ? accuracy : size) - o->hashtag;
	if (o->accuracy != -1)
	{
		if (o->accuracy - size < 0)
			o->accuracy = 0;
		else
		{
			o->accuracy = o->accuracy - size;
		}
	}
	return (width);
}

int			width_size_o(t_info *o, unsigned long long cast_ap)
{
	int width;
	int size_nb;
	int	hash;

	hash = o->hashtag;
	cast_ap = itooct(cast_ap);
	size_nb = cast_ap == 0 ? 1 : 0;
	width = o->width;
	while (cast_ap > 0)
	{
		cast_ap /= 10;
		size_nb++;
	}
	width -= (o->accuracy > size_nb + hash ? o->accuracy : size_nb + hash);
	if (o->accuracy != -1)
	{
		if (o->accuracy - size_nb - hash <= 0)
			o->accuracy = 0;
		else
			o->accuracy -= size_nb + hash;
	}
	return (width);
}

void		width_for_null(t_info *o)
{
	if (o->minus)
	{
		o->plus && !o->neg ? append_to_buff('+', 0, o) : 0;
		o->space && !o->plus && !o->neg
		? append_to_buff(' ', 0, o) : 0;
	}
	while (o->width-- > 0)
		append_to_buff(' ', 0, o);
	if (!o->minus)
	{
		o->plus && !o->neg ? append_to_buff('+', 0, o) : 0;
		o->space && !o->plus && !o->neg ? append_to_buff(' ', 0, o) : 0;
	}
}

int			width_bin(t_info *o)
{
	int		width;
	int		size_nb;

	size_nb = 8;
	width = o->width;
	width -= (o->accuracy > size_nb ? o->accuracy : size_nb) - o->space;
	if (o->accuracy != -1)
	{
		if (o->accuracy - size_nb < 0)
			o->accuracy = 0;
		else
		{
			o->accuracy = o->accuracy - size_nb;
		}
	}
	return (width);
}
