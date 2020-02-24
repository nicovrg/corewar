/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translator.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takoumys <takoumys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 18:27:42 by takoumys          #+#    #+#             */
/*   Updated: 2020/02/24 22:47:55 by takoumys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"
#include "ft_printf.h"


static void	write_magic_number(int fd)
{
	int				magic_number;
	unsigned char	magic_number_binary[4];

	magic_number = COREWAR_EXEC_MAGIC;
	ft_printf("m_b %d\n", magic_number);
	magic_number_binary[0] = magic_number >> 24;
	magic_number_binary[1] = magic_number >> 16;
	magic_number_binary[2] = magic_number >> 8;
	magic_number_binary[3] = magic_number >> 0;
	write(fd, magic_number_binary, 4);
}

int	translator(t_data **data, t_code_line **code_line)
{
	int	fd;

	if ((	(fd = open("test.cor" , O_RDWR | O_CREAT, 0644)) == -1)	)
		return (0);
	write_magic_number(fd);
	(void)data;
	(void)code_line;
	return (1);
}