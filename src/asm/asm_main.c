/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 14:21:47 by qgirard           #+#    #+#             */
/*   Updated: 2020/01/31 17:15:12 by amamy            ###   ########.fr       */
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
	t_code_line	*lex;
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
		return (error_msg("error in header", 1)); //free		
	if (!lexer(fd, &data, lex))
		return (error_msg("error in lexer", 1)); //free
	if (!parser(&data, &lex))
		return (error_msg("error in parser", 1)); //free
	if (data->errors)
		return (error_mode(&data, &lex));
	if (!translator(&data, &lex))
		return (error_msg("error in translator", 1)); //free
	// print_lexer(&data, &lex);
	return (0);
}