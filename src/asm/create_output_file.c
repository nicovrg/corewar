/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_output_file.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 12:58:02 by amamy             #+#    #+#             */
/*   Updated: 2020/02/25 13:04:13 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"
#include "ft_printf.h"

static char	*edit_ext_to_cor(char *file_name)
{
	int		i;
	char	*cor_file;

	if (!(cor_file = ft_memalloc(sizeof(char) * (ft_strlen(file_name) + 3))))
		return (0);
	ft_strcpy(cor_file, file_name);
	i = ft_strlen(file_name) + 1;
	cor_file[i--] = 'r';
	cor_file[i--] = 'o';
	cor_file[i--] = 'c';
	ft_printf("cor_file : |%s|\n", cor_file);
	return (cor_file);
}

int			create_output_file(t_data *data)
{
	int		fd;
	char	*file_name;

	fd = 0;
	if (!(file_name = edit_ext_to_cor(data->file_name)))
		return (-1);
	if (((fd = open(file_name , O_RDWR | O_CREAT, 0644)) == -1))
		return (-1);
	ft_memdel((void*)&file_name);
	return (fd);
}