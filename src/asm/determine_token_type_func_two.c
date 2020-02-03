/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   determine_token_type_func_two.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasv <nicolasv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 05:57:28 by amamy             #+#    #+#             */
/*   Updated: 2020/02/03 03:47:12 by nicolasv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"
#include "ft_printf.h"


int						is_label(t_token *token)
{
	(void)token;
	// ft_printf("%s\n", "is_label");
	return (0);
}

int						is_instructions(t_token *token)
{
	(void)token;
	// ft_printf("%s\n", "is_instructions");
	return (0);
}

int						is_direct(t_token *token)
{
	(void)token;
	// ft_printf("%s\n", "is_direct");
	return (0);
}

int						is_registr(t_token *token) //TODO: typo
{
	(void)token;
	// ft_printf("%s\n", "is_register");
	return (0);
}

int						is_indirect(t_token *token)
{
	(void)token;
	// ft_printf("%s\n", "is_indirect");
	return (0);
}
