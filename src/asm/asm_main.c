/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 14:21:47 by qgirard           #+#    #+#             */
/*   Updated: 2020/01/23 01:09:41 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"

int	parser(void) {return (0);};
int	translator(void) {return (0);}

int	new_lexer_node(t_lexer **lex)
{
	t_lexer		*new;
	t_lexer		*tmp_lex;

	tmp_lex = (*lex);
	while (tmp_lex && tmp_lex->next)
		tmp_lex = tmp_lex->next;
	if (!(new = (t_lexer *)ft_memalloc(sizeof(t_lexer))))
		return (0);
	new->nb_line = 0;
	new->line = NULL;
	new->label = NULL;
	new->token = NULL;
	new->next = NULL;
	if (*lex)
		tmp_lex->next = new;
	else
		(*lex) = new;
	return (1);
}

int	lexer(t_lexer *lex) 
{
	while (get_one_line(&))
	{
		if (!new_lexer_node(&lex))
			return (error_msg(ERR_LEXER_NODE_CREATE, 0));
	}
	return (1);
}

int		main(int argc, char **argv)
{
	int		fd;
	t_lexer	*lex;

	lex = NULL;
	if (argc != 2)
		return (error_msg(ERR_MAIN_NB_PARAMETERS, 1));
	else
	{
		if (argv[1] && ft_strchr(argv[1], '.') && ft_strcmp(ft_strchr(argv[1], '.'), ".s"))
			return (error_msg(ERR_MAIN_FILE_TYPE, 1));
		else if (argv[1] && (fd = open(argv[1], O_RDONLY)) == -1)
			return (error_msg(ERR_MAIN_OPEN_FILE, 1));
		ft_putstr("coucou\n");
		if (!lexer(&lex))
			return 0;
		if (!parser())
			return 0;
		if (!translator())
			return 0;
	}
	return (0);
}