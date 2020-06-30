/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquivogn <jquivogn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 21:51:28 by nivergne          #+#    #+#             */
/*   Updated: 2019/02/08 19:25:36 by jquivogn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_hex(va_list ap, t_info *o)
{
	char *c;

	if (o->conversion == 7)
	{
		c = (o->type == 0 ? conv(va_arg(ap, unsigned int), 16, 1) : 0);
		c = (o->type == 3 ? conv((UC)(va_arg(ap, unsigned int)), 16, 1) : c);
		c = (o->type == 1 ? conv((US)(va_arg(ap, unsigned int)), 16, 1) : c);
		c = (o->type == 2 ? conv(va_arg(ap, unsigned long), 16, 1) : c);
		c = (o->type == 4 ? conv(va_arg(ap, unsigned long long), 16, 1) : c);
		c[0] == '0' ? hex_for_null(o) : ft_addhexmin(c, o);
	}
	else if (o->conversion == 8)
	{
		c = (o->type == 0 ? conv(va_arg(ap, unsigned int), 16, 0) : 0);
		c = (o->type == 3 ? conv((UC)(va_arg(ap, unsigned int)), 16, 0) : c);
		c = (o->type == 1 ? conv((US)(va_arg(ap, unsigned int)), 16, 0) : c);
		c = (o->type == 2 ? conv(va_arg(ap, unsigned long), 16, 0) : c);
		c = (o->type == 4 ? conv(va_arg(ap, unsigned long long), 16, 0) : c);
		c[0] == '0' ? hex_for_null(o) : ft_addhexmaj(c, o);
	}
}

void	ft_addhexmin(char *cast_ap, t_info *o)
{
	int			size;

	size = width_size_x(o, cast_ap);
	o->minus == 1 && o->hashtag == 2 ? addbuff("0x", o) : 0;
	o->accuracy > 0 && o->minus ? ft_accuracy(o) : 0;
	o->minus == 1 ? addbuff(cast_ap, o) : 0;
	if (o->zero && o->accuracy == -1)
		o->minus == 0 && o->hashtag == 2 ? addbuff("0x", o) : 0;
	if (o->width >= 0 && size > 0)
		while (size--)
			append_to_buff(o->zero && !o->minus
			&& o->accuracy < 0 ? '0' : ' ', 0, o);
	if (!(o->zero && o->accuracy == -1))
		o->minus == 0 && o->hashtag == 2 ? addbuff("0x", o) : 0;
	o->accuracy > 0 && !o->minus ? ft_accuracy(o) : 0;
	o->minus == 0 ? addbuff(cast_ap, o) : 0;
	free(cast_ap);
}

void	ft_addhexmaj(char *cast_ap, t_info *o)
{
	int			size;

	size = width_size_x(o, cast_ap);
	o->minus == 1 && o->hashtag == 2 ? addbuff("0X", o) : 0;
	o->accuracy > 0 && o->minus ? ft_accuracy(o) : 0;
	o->minus == 1 ? addbuff(cast_ap, o) : 0;
	if (o->zero && o->accuracy == -1)
		o->minus == 0 && o->hashtag == 2 ? addbuff("0X", o) : 0;
	if (o->width >= 0 && size > 0)
		while (size--)
			append_to_buff(o->zero && !o->minus
			&& o->accuracy < 0 ? '0' : ' ', 0, o);
	if (!(o->zero && o->accuracy == -1))
		o->minus == 0 && o->hashtag == 2 ? addbuff("0X", o) : 0;
	o->accuracy > 0 && !o->minus ? ft_accuracy(o) : 0;
	o->minus == 0 ? addbuff(cast_ap, o) : 0;
	free(cast_ap);
}

void	hex_for_null(t_info *o)
{
	o->accuracy > 0 && o->minus ? ft_accuracy(o) : 0;
	o->minus && o->accuracy < 0 ? ft_addnbr_core(0, o) : 0;
	if (o->accuracy > 1)
		o->width = o->width - (o->accuracy >= 1
		? o->accuracy : 1);
	else if (o->accuracy == 1)
		o->width = o->width - (o->accuracy >= 1
		? o->accuracy : 1);
	else if (o->accuracy < 0)
		o->width--;
	while (o->width-- > 0)
		append_to_buff(o->zero && !o->minus
		&& o->accuracy < 0 ? '0' : ' ', 0, o);
	o->accuracy > 0 && !o->minus ? ft_accuracy(o) : 0;
	!o->minus && o->accuracy < 0 ? ft_addnbr_core(0, o) : 0;
}
