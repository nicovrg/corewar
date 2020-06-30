/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 07:51:34 by nivergne          #+#    #+#             */
/*   Updated: 2019/10/09 07:52:03 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "time_exe.h"

double				cl(clock_t t)
{
	static double	last;
	double			m;

	m = ((double)(t - last)) / (CLOCKS_PER_SEC);
	last = ((double)(clock()));
	return (m);
}
