/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquivogn <jquivogn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 23:32:12 by nivergne          #+#    #+#             */
/*   Updated: 2019/02/08 19:20:49 by jquivogn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_bit_to_buff(char cast_ap, t_info *o)
{
	int i;

	i = 256;
	while (i >>= 1)
		append_to_buff((cast_ap & i) ? '1' : '0', 0, o);
}

void	ft_addbin(va_list ap, t_info *o)
{
	char	cast_ap;
	int		size;

	cast_ap = (signed char)va_arg(ap, int);
	size = width_bin(o);
	if (o->minus)
	{
		o->space ? append_to_buff(' ', 0, o) : 0;
		o->accuracy > 0 ? ft_accuracy(o) : 0;
		ft_put_bit_to_buff(cast_ap, o);
	}
	if (o->width >= 0 && size > 0)
		while (size--)
			append_to_buff(o->zero && !o->minus
			&& o->accuracy < 0 ? '0' : ' ', 0, o);
	if (!o->minus)
	{
		o->space ? append_to_buff(' ', 0, o) : 0;
		o->accuracy > 0 ? ft_accuracy(o) : 0;
		ft_put_bit_to_buff(cast_ap, o);
	}
}
