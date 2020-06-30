/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_per.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquivogn <jquivogn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 23:30:14 by nivergne          #+#    #+#             */
/*   Updated: 2019/02/08 18:31:45 by jquivogn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_addpercent(va_list ap, t_info *o)
{
	int		i;

	(void)ap;
	if (o->minus == 1)
		append_to_buff('%', 0, o);
	i = o->width;
	while (i-- > 1)
		append_to_buff(o->zero && !o->minus && o->accuracy < 0
		? '0' : ' ', 0, o);
	if (o->minus == 0)
		append_to_buff('%', 0, o);
}
