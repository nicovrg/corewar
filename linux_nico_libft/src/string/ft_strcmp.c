/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 22:23:53 by nivergne          #+#    #+#             */
/*   Updated: 2019/02/13 18:01:28 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

/*
** DESCRIPTION
** Strcmp() lexicographically compare the null-terminated strings s1 and s2.
**
** RETURN VALUES
** Strcmp() return an the difference between s1 and s2.
** The comparison is done using unsigned characters,
** so that `\200' is greater than `\0'.
*/
