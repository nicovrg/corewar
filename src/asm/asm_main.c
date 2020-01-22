/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 14:21:47 by qgirard           #+#    #+#             */
/*   Updated: 2020/01/22 06:28:53 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"

int	parser(void) {return (0);};
int	translator(void) {return (0);}

int	lexer(t_line *codeline) 
{
	while ()
	{
		
	}
	return (1);
}

int		main(int argc, char **argv)
{
	int		fd;
	t_line	codeline;

	if (argc != 2)
		return (error_msg(ERR_NB_PARAMETERS, 1));
	else
	{
		if (argv[1] && ft_strchr(argv[1], '.') && ft_strcmp(ft_strchr(argv[1], '.'), ".s"))
			return (error_msg(ERR_FILE_TYPE, 1));
		else if (argv[1] && (fd = open(argv[1], O_RDONLY)) == -1)
			return (error_msg(ERR_OPEN_FILE, 1));
		ft_putstr("coucou\n");
		// init
		if (!lexer(&codeline))
			return 0;
		if (!parser())
			return 0;
		if (!translator())
			return 0;
	}
	return (0);
}