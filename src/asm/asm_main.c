/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 14:21:47 by qgirard           #+#    #+#             */
/*   Updated: 2020/01/21 01:27:27 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"

/*
** ==================== Oooookina kisu ====================
** yo j'ai check vite fait sur le makefile à la maison, pas réussi à me concentrer dessus à l'école
** (la faute à timothée, guillaume, kevin, allan, maxime, steven)
** ça me pète trop les couilles c'est la même structure de dossier que lemin
** c'est quasi le même Makefile donc ça doit être un truc débile qu'on verra pas ...
** en attendant tu peux toujours compiler à l'ancienne depuis le dossier src/asm
** gcc src/asm/main.c src/asm/error.c -Iinclude -I libft/include -L libft/ -lft -o yipikai
*/

int		main(int argc, char **argv)
{
	int		fd;

	if (argc != 2)
		return (error_msg(ERR_NB_PARAMETERS, 1));
	else
	{
		if (argv[1] && ft_strchr(argv[1], '.')
		&& ft_strcmp(ft_strchr(argv[1], '.'), ".s"))
			return (error_msg(ERR_FILE_TYPE, 1));
		else if (argv[1] && (fd = open(argv[1], O_RDONLY)) == -1)
			return (error_msg(ERR_OPEN_FILE, 1));
	}
	return (0);
}