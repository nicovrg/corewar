/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_i.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquivogn <jquivogn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 03:18:33 by nivergne          #+#    #+#             */
/*   Updated: 2019/02/11 17:58:15 by jquivogn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_nbr(va_list ap, t_info *o)
{
	long long		cast_ap;
	__intmax_t		tmp;

	cast_ap = (o->type == 0 ? va_arg(ap, int) : 0);
	cast_ap = (o->type == 1 ? (short)va_arg(ap, int) : cast_ap);
	cast_ap = (o->type == 3 ? (signed char)va_arg(ap, int) : cast_ap);
	cast_ap = (o->type == 2 ? va_arg(ap, long) : cast_ap);
	cast_ap = (o->type == 4 ? va_arg(ap, long long) : cast_ap);
	if (cast_ap == 0 && o->accuracy == 0)
	{
		width_for_null(o);
		return ;
	}
	tmp = cast_ap;
	if (cast_ap < 0)
	{
		if (tmp == LONG_MIN)
		{
			cast_ap = -922337203685477580;
			o->llmin = 1;
		}
		cast_ap *= -1;
		o->neg = 1;
	}
	ft_addnbr(cast_ap, o);
}

void	ft_nbrsign(t_info *o)
{
	if (!o->minus)
	{
		o->plus && !o->neg ? append_to_buff('+', 0, o) : 0;
		o->space && !o->plus && !o->neg ?
			append_to_buff(' ', 0, o) : 0;
		o->neg ? append_to_buff('-', 0, o) : 0;
	}
}

void	ft_addnbr(long long cast_ap, t_info *o)
{
	int		size;

	size = width_size_diou(o, cast_ap, 10);
	o->plus && o->minus && !o->neg ?
		append_to_buff('+', 0, o) : 0;
	!o->plus && o->minus && !o->neg && o->space ?
		append_to_buff(' ', 0, o) : 0;
	o->neg && o->minus ? append_to_buff('-', 0, o) : 0;
	o->accuracy > 0 && o->minus ? ft_accuracy(o) : 0;
	o->minus == 1 ? ft_addnbr_core(cast_ap, o) : 0;
	o->minus == 1 && o->llmin == 1 ? ft_addnbr_core(8, o) : 0;
	if (o->zero && o->accuracy == -1)
		ft_nbrsign(o);
	if (o->width >= 0 && size > 0)
		while (size-- > 0)
			append_to_buff(o->zero && !o->minus &&
				o->accuracy < 0 ? '0' : ' ', 0, o);
	if (!(o->zero && o->accuracy == -1))
		ft_nbrsign(o);
	o->accuracy > 0 && !o->minus ? ft_accuracy(o) : 0;
	o->minus == 0 ? ft_addnbr_core(cast_ap, o) : 0;
	o->minus == 0 && o->llmin == 1 ? ft_addnbr_core(8, o) : 0;
}

void	ft_addnbr_core(long long nb, t_info *o)
{
	if (nb < 0)
	{
		append_to_buff('-', 0, o);
		nb = -nb;
	}
	if (nb >= 10)
	{
		ft_addnbr_core(nb / 10, o);
		append_to_buff(nb % 10 + '0', 0, o);
	}
	else
		append_to_buff(nb % 10 + '0', 0, o);
}
