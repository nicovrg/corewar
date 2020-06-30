/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_f.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 21:19:05 by nivergne          #+#    #+#             */
/*   Updated: 2019/02/11 18:21:11 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_calc_mantis(t_info *o, long double *cast_ap, long long *tmp)
{
	while (o->accuracy > 0 && *cast_ap)
	{
		if (*tmp > 2147483647)
		{
			ft_addnbr_core(*tmp, o);
			*cast_ap -= *tmp;
			*tmp = 0;
			continue ;
		}
		*cast_ap *= 10;
		if ((int)*cast_ap == 0)
		{
			while ((int)*cast_ap == 0 && o->accuracy-- > 0)
			{
				append_to_buff('0', 0, o);
				*cast_ap *= 10;
			}
		}
		else
		{
			*tmp = *tmp * 10 + ((long long)*cast_ap % 10);
			o->accuracy--;
		}
	}
}

void		ft_mantis(t_info *o, long double cast_ap, int flag,
			unsigned long long left)
{
	long long	tmp;

	if (o->fnull == 1 && o->accuracy == 0)
		flag = 1;
	tmp = 0;
	ft_calc_mantis(o, &cast_ap, &tmp);
	while (o->accuracy-- > 1 && (o->fnull == 1 || !cast_ap))
		append_to_buff('0', 0, o);
	cast_ap *= 10;
	left = 0;
	left += ((int)cast_ap % 10);
	if (left >= 5)
		tmp = tmp % 2 == 0 ? tmp : tmp + 1;
	if (!flag)
		ft_addnbr_core(tmp, o);
}

void		ft_addfloat(va_list ap, t_info *o)
{
	unsigned long long	left;
	long double			cast_ap;
	int					flag;
	int					size;

	flag = 0;
	cast_ap = o->type != 4 ? (double)va_arg(ap, double) : 0;
	cast_ap = o->type == 4 ? (long double)va_arg(ap, long double) : cast_ap;
	left = (unsigned long long)(cast_ap < 0 ? -cast_ap : cast_ap);
	cast_ap <= 0 && left == 0 ? o->neg = 1 : 0;
	cast_ap < 0 ? o->neg = 1 : 0;
	cast_ap < 0 ? cast_ap *= -1 : 0;
	size = width_size_float(o, left);
	cast_ap = cast_ap - left;
	o->fnull = left == 0 ? 1 : 0;
	if (o->accuracy == 0 && left != 0)
	{
		flag = cast_ap * 10;
		if (flag >= 5)
			left = (left % 2 == 0) ? left : left + 1;
		flag = 1;
	}
	o->llmin = flag;
	ft_merge_float(o, left, cast_ap, size);
}

void		ft_merge_float(t_info *o, unsigned long long left,
			long double cast_ap, int size)
{
	int	flag;

	flag = o->llmin;
	if (o->minus)
		ft_put_float(o, left, cast_ap, flag);
	if (!o->minus && o->zero)
		ft_padding(o);
	if (o->width >= 0 && size > 0)
		while (size-- > 0)
			append_to_buff(o->zero && !o->minus
			? '0' : ' ', 0, o);
	if (!o->minus && !(o->zero))
		ft_padding(o);
	if (!o->minus)
		ft_put_float(o, left, cast_ap, flag);
}

int			width_size_float(t_info *o, unsigned long long cast_ap)
{
	int	width;
	int	size_nb;

	size_nb = cast_ap == 0 ? 1 : 0;
	width = o->width;
	o->accuracy = o->accuracy == -1 ? 6 : o->accuracy;
	o->neg == 1 ? size_nb++ : 0;
	size_nb += 1 + o->accuracy;
	while (cast_ap > 0)
	{
		cast_ap /= 10;
		size_nb++;
	}
	width = width - (o->accuracy > size_nb ? o->accuracy : size_nb)
		- (o->plus && !o->neg ? 1 : 0) - (o->neg ? 1 : 0)
		- (o->space == 1 && !o->plus && !o->neg ? 1 : 0);
	return (width);
}
