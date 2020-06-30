/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 15:42:40 by nivergne          #+#    #+#             */
/*   Updated: 2018/11/13 11:17:54 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_find_next_prime(int nb)
{
	if (nb < 0)
		nb = 0;
	while (ft_is_prime(nb) != 1)
		nb++;
	return (nb);
}

/*
** DESCRIPTION
** Find the next prime number. If the parameter is prime, return it.
*/
