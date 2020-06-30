/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquivogn <jquivogn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 23:27:03 by nivergne          #+#    #+#             */
/*   Updated: 2019/02/11 17:58:30 by jquivogn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_addchar(va_list ap, t_info *o)
{
	int	cast_ap;

	if (o->type == 2 || o->conversion == 12)
	{
		ft_addwchar(ap, o);
		return ;
	}
	cast_ap = va_arg(ap, int);
	if (cast_ap < 32 && cast_ap >= 0)
	{
		char_null(cast_ap, o);
	}
	else
	{
		if (o->minus == 1)
			append_to_buff(' ' + cast_ap - 32, 0, o);
		addwidth_char(o->width, o);
		if (o->minus == 0)
			append_to_buff(' ' + cast_ap - 32, 0, o);
	}
}

void			ft_addwchar(va_list ap, t_info *o)
{
	wchar_t	cast_ap;

	cast_ap = va_arg(ap, wchar_t);
	if (o->minus == 1)
		ft_putwchar(cast_ap, o);
	addwidth_wchar(cast_ap, o->width, o);
	if (o->minus == 0)
		ft_putwchar(cast_ap, o);
}

void			ft_putwchar(wchar_t c, t_info *o)
{
	if (c <= 0x7F)
		append_to_buff(c, 0, o);
	else if (c <= 0x7FF)
	{
		append_to_buff((c >> 6) | 0xC0, 0, o);
		append_to_buff((c & 0x3F) | 0x80, 0, o);
	}
	else if (c <= 0xFFFF)
	{
		append_to_buff((c >> 12) | 0xE0, 0, o);
		append_to_buff(((c >> 6) & 0x3F) | 0x80, 0, o);
		append_to_buff((c & 0x3F) | 0x80, 0, o);
	}
	else if (c <= 0x10FFFF)
	{
		append_to_buff((c >> 18) | 0xF0, 0, o);
		append_to_buff(((c >> 12) & 0x3F) | 0x80, 0, o);
		append_to_buff(((c >> 6) & 0x3F) | 0x80, 0, o);
		append_to_buff((c & 0x3F) | 0x80, 0, o);
	}
}

void			addwidth_wchar(wchar_t c, int nb, t_info *o)
{
	if (c <= 0x7F)
		nb--;
	else if (c <= 0x7FF)
		nb -= 2;
	else if (c <= 0xFFFF)
		nb -= 3;
	else if (c <= 0x10FFFF)
		nb -= 4;
	while (nb > 0)
	{
		append_to_buff(o->zero && !o->minus && o->accuracy < 0
		? '0' : ' ', 0, o);
		nb--;
	}
}

void			ft_color(va_list ap, t_info *options)
{
	const char	*str = va_arg(ap, char *);

	while (*str)
	{
		append_to_buff(*str, 0, options);
		str++;
		options->ret--;
	}
}
