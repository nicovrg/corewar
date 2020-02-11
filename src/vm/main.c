/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 15:32:40 by qgirard           #+#    #+#             */
/*   Updated: 2020/02/10 23:50:56 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include "libft.h"

int		main(int argc, char **argv)
{
	t_corewar	arena;
	t_champion	*champions;

	champions = NULL;
	if (argc < 2)
		return (error_msg(ERR_VM_USAGE, 1, NULL));
	ft_bzero(&arena, sizeof(t_corewar));
	if (!process_parse_arguments(&arena, &champions, argv))
		return (0);
	introduce_champs(&champions);
	vm_free(&champions);
	return (0);
}
