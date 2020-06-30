/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_o.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 23:33:38 by nivergne          #+#    #+#             */
/*   Updated: 2019/02/20 18:31:56 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_oct(va_list ap, t_info *o)
{
	unsigned long long	cast;

	if (o->type == 0)
		o->type = 2;
	cast = (o->type == 0 ? (unsigned int)va_arg(ap, unsigned int) : 0);
	cast = (o->type == 3 ? (unsigned char)va_arg(ap, unsigned int) : cast);
	cast = (o->type == 1 ? (unsigned short)va_arg(ap, unsigned int) : cast);
	cast = (o->type == 2 ? va_arg(ap, unsigned long) : cast);
	cast = (o->type == 4 ? va_arg(ap, unsigned long long) : cast);
	if (itooct(cast) == 0)
		oct_for_null(o);
	else
		ft_addoct(cast, o);
}

void	ft_addoct(unsigned long long cast_ap, t_info *o)
{
	int size;

	size = width_size_o(o, cast_ap);
	o->accuracy > 0 && o->minus ? ft_accuracy(o) : 0;
	o->minus == 1 && o->hashtag == 1 ? append_to_buff('0', 0, o) : 0;
	o->minus == 1 ? ft_adduns_core(cast_ap, o, 8) : 0;
	if (o->width >= 0 && size > 0)
		while (size-- > 0)
			append_to_buff(o->zero && !o->minus
			&& o->accuracy < 0 ? '0' : ' ', 0, o);
	o->accuracy > 0 && !o->minus ? ft_accuracy(o) : 0;
	o->minus == 0 && o->hashtag == 1 ? append_to_buff('0', 0, o) : 0;
	o->minus == 0 ? ft_adduns_core(cast_ap, o, 8) : 0;
}

void	oct_for_null(t_info *o)
{
	o->accuracy > 0 && o->minus ? ft_accuracy(o) : 0;
	o->accuracy <= 0 && o->minus == 1 && o->hashtag == 1
	? ft_addnbr_core(0, o) : 0;
	o->minus && o->accuracy < 0 && !o->hashtag ? ft_addnbr_core(0, o) : 0;
	if (o->accuracy > 1)
		o->width = o->width - (o->accuracy >= 1 + o->hashtag
		? o->accuracy : 1 + o->hashtag);
	else if (o->accuracy == 1)
		o->width = o->width - (o->accuracy >= 1
		? o->accuracy : 1);
	else if ((o->accuracy < 0 && !o->hashtag) || (o->hashtag == 1))
		o->width--;
	while (o->width-- > 0)
		append_to_buff(o->zero && !o->minus
		&& o->accuracy < 0 ? '0' : ' ', 0, o);
	o->accuracy > 0 && !o->minus ? ft_accuracy(o) : 0;
	o->accuracy <= 0 && o->minus == 0 && o->hashtag == 1
	? ft_addnbr_core(0, o) : 0;
	!o->minus && o->accuracy < 0 && !o->hashtag ? ft_addnbr_core(0, o) : 0;
}
