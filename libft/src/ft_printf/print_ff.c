/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_f.1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 21:19:05 by nivergne          #+#    #+#             */
/*   Updated: 2019/02/11 18:20:46 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_padding(t_info *o)
{
	o->plus && !o->neg
	? append_to_buff('+', 0, o) : 0;
	!o->plus && !o->neg && o->space
	? append_to_buff(' ', 0, o) : 0;
	o->neg ? append_to_buff('-', 0, o) : 0;
}

void		ft_put_float(t_info *o, unsigned long long left,
				long double cast_ap, int flag)
{
	if (o->minus)
		ft_padding(o);
	ft_addnbr_core(left, o);
	if (!(o->accuracy == 0 && !o->hashtag))
		append_to_buff('.', 0, o);
	ft_mantis(o, cast_ap, flag, left);
}
