/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_tokeniser_states-function_one.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 05:57:28 by amamy             #+#    #+#             */
/*   Updated: 2020/02/01 00:53:20 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"
#include "ft_printf.h"

int						is_label(t_token **token, char *src)
{
	(void)src;
	(void)token;
	ft_printf("%s\n", "label couille");
	return (0);
}

int						is_instructions(t_token **token, char *src)
{
	(void)src;
	(void)token;
	ft_printf("%s\n", "instructions");
	return (0);
}

int						is_direct(t_token **token, char *src)
{
	(void)src;
	(void)token;
	ft_printf("%s\n", "direct");
	return (0);
}

int						is_registr(t_token **token, char *src)
{
	(void)src;
	(void)token;
	ft_printf("%s\n", "register");
	return (0);
}

int						is_indirect(t_token **token, char *src)
{
	(void)src;
	(void)token;
	ft_printf("%s\n", "indirect");
	return (0);
}
