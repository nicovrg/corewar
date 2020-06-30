/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 23:27:52 by nivergne          #+#    #+#             */
/*   Updated: 2019/02/20 18:32:34 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_uns(va_list ap, t_info *o)
{
	unsigned long long	c_ap;

	c_ap = (o->type == 0 ? va_arg(ap, unsigned int) : 0);
	c_ap = (o->type == 1 ? (unsigned short)va_arg(ap, unsigned int) : c_ap);
	c_ap = (o->type == 3 ? (unsigned char)va_arg(ap, unsigned int) : c_ap);
	c_ap = (o->type == 2 ? va_arg(ap, unsigned long) : c_ap);
	c_ap = (o->type == 4 ? va_arg(ap, unsigned long long) : c_ap);
	ft_adduns(c_ap, o);
}

void	ft_adduns(long long cast_ap, t_info *o)
{
	int size;

	size = width_size_diou(o, cast_ap, 10);
	o->accuracy > 0 && o->minus ? ft_accuracy(o) : 0;
	if (o->minus == 1)
		ft_adduns_core(cast_ap, o, 10);
	if (o->width >= 0 && size > 0)
		while (size--)
			append_to_buff(o->zero && !o->minus
			&& o->accuracy < 0 ? '0' : ' ', 0, o);
	o->accuracy > 0 && !o->minus ? ft_accuracy(o) : 0;
	if (o->minus == 0)
		ft_adduns_core(cast_ap, o, 10);
}

void	ft_adduns_core(unsigned long long nb, t_info *o, int base)
{
	if (nb == 0 && o->accuracy == 0 && o->fnull == 0)
		return ;
	if (nb >= (unsigned long long)base)
	{
		ft_adduns_core(nb / base, o, base);
		append_to_buff(nb % base + '0', 0, o);
	}
	else
		append_to_buff(nb % base + '0', 0, o);
}
