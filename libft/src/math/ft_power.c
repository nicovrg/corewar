/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 15:38:33 by nivergne          #+#    #+#             */
/*   Updated: 2019/02/13 18:00:36 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_power(int nb, int power)
{
	int i;
	int result;

	i = 0;
	result = 1;
	if (power < 0)
		return (0);
	else
		while (i < power)
		{
			result = result * nb;
			i++;
		}
	return (result);
}

/*
** DESCRIPTION
** Compute both parameter to return number^power
*/
