/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquivogn <jquivogn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 23:29:11 by nivergne          #+#    #+#             */
/*   Updated: 2019/02/11 17:43:06 by jquivogn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_addaddr(va_list ap, t_info *o)
{
	void *cast;

	cast = conv(va_arg(ap, unsigned long long), 16, 1);
	if (o->hashtag == 0)
		o->hashtag = 1;
	ft_addhexmin(cast, o);
}
