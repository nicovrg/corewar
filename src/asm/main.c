/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasv <nicolasv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 14:21:47 by qgirard           #+#    #+#             */
/*   Updated: 2020/02/03 03:34:50 by nicolasv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"

int	parser(t_data **data, t_code_line **lex)
{
	(void)data;
	(void)lex;
	return (1);
}

int	error_mode(t_data **data, t_code_line **lex)
{
	(void)data;
	(void)lex;
	return (1);
}

int	translator(t_data **data, t_code_line **lex)
{
	(void)data;
	(void)lex;
	return (1);
}

static int	check_args_and_open_files(int argc, char **argv)
{
	int	fd;

	fd = 0;
	if (argc != 2)
		return (error_msg(ERR_MAIN_NB_PARAMETERS, 1));
	if (argv[1] && ft_strchr(argv[1], '.') && ft_strcmp(ft_strchr(argv[1], '.'), ".s"))
		return (error_msg(ERR_MAIN_FILE_TYPE, 1));
	else if (argv[1] && (fd = open(argv[1], O_RDONLY)) == -1)
		return (error_msg(ERR_MAIN_OPEN_FILE, 1));
	return (fd);
}

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
	int			fd;
	t_data		*data;
	t_code_line	*code_line;

	data = NULL;
	code_line = NULL;
	if (!(fd = check_args_and_open_files(argc, argv)))
		return (1);
	if (!header(fd, &data))
		return (error_msg("error in header", 1)); //free		
	if (!lexer(fd, &data, &code_line))
		return (error_msg("error in lexer", 1)); //free
	if (!parser(&data, &code_line))
		return (error_msg("error in parser", 1)); //free
	if (data->errors)
		return (error_mode(&data, &code_line));
	if (!translator(&data, &code_line))
		return (error_msg("error in translator", 1)); //free
	print_code_line(&data, &code_line);
	return (0);
}