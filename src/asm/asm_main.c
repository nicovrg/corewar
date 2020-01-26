/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 14:21:47 by qgirard           #+#    #+#             */
/*   Updated: 2020/01/26 03:55:50 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"

int	parser(void) {return (0);};
int	translator(void) {return (0);}



/*
** ==================== main ====================
** check args number
** check file name format
** open champ .s file
** call lexer
** call parser
** call translater
*/

int		main(int argc, char **argv)
{
	int		fd;
	t_lexer	*lex;
	t_data	*data;

	fd = 0;
	lex = NULL;
	data = NULL;
	if (argc != 2)
		return (error_msg(ERR_MAIN_NB_PARAMETERS, 1));
	if (argv[1] && ft_strchr(argv[1], '.') && ft_strcmp(ft_strchr(argv[1], '.'), ".s"))
		return (error_msg(ERR_MAIN_FILE_TYPE, 1));
	else if (argv[1] && (fd = open(argv[1], O_RDONLY)) == -1)
		return (error_msg(ERR_MAIN_OPEN_FILE, 1));
	if (!header(fd, &data))
		return (error_msg("err", 1)); //free		
	print_data(&data);
	if (!lexer(fd, &data, &lex))
		return (error_msg("err", 1)); //free
	print_lexer(&lex);
	if (!parser())
		return (error_msg("err", 1)); //free
	if (!translator())
		return (error_msg("err", 1)); //free
	return (0);
}