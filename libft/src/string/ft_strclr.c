/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 15:40:39 by nivergne          #+#    #+#             */
/*   Updated: 2018/11/13 15:54:18 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strclr(char *s)
{
	size_t		i;
	size_t		s_len;

	if (s != NULL)
	{
		i = 0;
		s_len = ft_strlen(s);
		while (i < s_len)
		{
			s[i] = '\0';
			i++;
		}
	}
}

/*
** DESCRIPTION
** Strclr() assign 0 to every char of the string
** sent as a parameter.
*/
