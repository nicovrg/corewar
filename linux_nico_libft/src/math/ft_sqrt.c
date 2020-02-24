/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 15:41:14 by nivergne          #+#    #+#             */
/*   Updated: 2019/02/13 18:01:07 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_sqrt(int nb)
{
	int i;
	int temp;

	i = 0;
	temp = 0;
	while (i < nb)
	{
		if (temp * temp == nb)
			return (temp);
		temp++;
		i++;
	}
	return (0);
}

/*
** DESCRIPTION
** Return the square root of the paraneter.
*/
