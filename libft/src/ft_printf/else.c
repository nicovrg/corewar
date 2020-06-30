/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   else.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquivogn <jquivogn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 22:16:08 by nivergne          #+#    #+#             */
/*   Updated: 2019/02/09 03:59:00 by jquivogn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		t_info_init(t_info *o, int i)
{
	o->zero = 0;
	o->plus = 0;
	o->minus = 0;
	o->space = 0;
	o->hashtag = 0;
	o->percent = 0;
	o->neg = 0;
	o->width = -1;
	o->accuracy = -1;
	o->type = 0;
	o->conversion = -1;
	o->llmin = 0;
	if (i == 0)
	{
		o->ret = 0;
		o->index = 0;
		ft_bzero(&o->buff, BUFF_SIZE);
	}
	return (0);
}

int		check_type(char c, t_info *o)
{
	if (c == 'h')
	{
		if (o->type == 1)
			o->type = 3;
		else
			o->type = 1;
		return (1);
	}
	else if (c == 'l')
	{
		if (o->type == 2)
			o->type = 4;
		else
			o->type = 2;
		return (1);
	}
	else if (c == 'j' || c == 'z' || c == 'L')
	{
		o->type = 4;
		return (1);
	}
	else if (c == 'q')
		return (1);
	return (0);
}

int		ft_accuracy(t_info *o)
{
	int accu;

	accu = o->accuracy;
	while (accu-- > 0)
		append_to_buff('0', 0, o);
	return (0);
}
