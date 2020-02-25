/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translator.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 18:27:42 by takoumys          #+#    #+#             */
/*   Updated: 2020/02/25 15:47:17 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"
#include "ft_printf.h"

int			translator(t_data **data, t_code_line **code_line)
{
	int	fd;
	if ((fd = create_output_file(*data)) == -1)
		return (0);
	write_header(*data, fd);
	(void)code_line;
	return (1);
}