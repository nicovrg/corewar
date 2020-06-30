/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquivogn <jquivogn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 16:58:54 by nivergne          #+#    #+#             */
/*   Updated: 2019/02/11 17:23:00 by jquivogn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	(*g_funptr[13])(va_list ap, t_info *o) = {
	&ft_addchar,
	&ft_addstr,
	&ft_addaddr,
	&ft_nbr,
	&ft_nbr,
	&ft_oct,
	&ft_uns,
	&ft_hex,
	&ft_hex,
	&ft_addbin,
	&ft_addfloat,
	&ft_addpercent,
	&ft_color,
};

void	addbuff(char *str, t_info *o)
{
	int		i;

	i = 0;
	if (o->conversion == 1)
		o->accuracy == -1 ? o->accuracy = ft_strlen(str) : 1;
	if (str != NULL)
	{
		while (str[i] != '\0' && (o->conversion == 1 ? i < o->accuracy : 1))
		{
			append_to_buff(str[i], 0, o);
			i++;
		}
	}
}

int		parse_str(char *str, t_info *o)
{
	int		shift;

	shift = 0;
	while (check_flag(str[shift], o) == 1)
		shift++;
	while (check_width(str[shift], o) == 1)
		shift++;
	if (check_accuracy_one(str[shift], o) == 1)
		shift++;
	while (check_accuracy_two(str[shift], o) == 1)
		shift++;
	while (check_type(str[shift], o) == 1)
		shift++;
	if (check_conversion(str[shift], o) == 1)
		shift++;
	else if (o->width > 0)
		while (o->width-- > 1)
			append_to_buff(' ', 0, o);
	return (shift);
}

int		append_to_buff(char c, int print, t_info *o)
{
	if (print == 0)
		o->buff[o->index] = c;
	else if (print == 1)
	{
		o->index = 0;
		ft_putstr(o->buff);
		ft_bzero(o->buff, BUFF_SIZE);
		return (o->ret);
	}
	o->index++;
	if (o->index == BUFF_SIZE - 1)
		append_to_buff(0, 1, o);
	return (o->ret++);
}

int		ft_printf(char *str, ...)
{
	int		i;
	va_list	arg;
	t_info	o;

	i = 0;
	if (!str)
		return (-1);
	va_start(arg, str);
	t_info_init(&o, i);
	while (str[i])
	{
		if (str[i] == '%')
		{
			t_info_init(&o, i);
			i = i + parse_str(str + i + 1, &o);
			o.conversion != -1 ? g_funptr[o.conversion % 13](arg, &o) : 0;
		}
		else
			append_to_buff(str[i], 0, &o);
		i == BUFF_SIZE - 1 ? append_to_buff(0, 1, &o) : 0;
		i++;
	}
	va_end(arg);
	return (append_to_buff(0, 1, &o));
}
