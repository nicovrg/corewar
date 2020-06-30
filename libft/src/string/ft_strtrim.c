/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 19:13:18 by nivergne          #+#    #+#             */
/*   Updated: 2018/11/13 15:57:44 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	char	*result;

	if (s == NULL)
		return (NULL);
	i = 0;
	j = ft_strlen(s) - 1;
	while ((s[i]) && (s[i] == ' ' || s[i] == '\t' || s[i] == '\n'))
		i++;
	if (i == (int)ft_strlen(s))
		return (ft_strnew(1));
	while ((s[j] == ' ' || s[j] == '\t' || s[j] == '\n') && j > 0)
		j--;
	j = ft_strlen(s) - j;
	j--;
	if (!(result = ft_strnew(ft_strlen(s) - (i + j))))
		return (NULL);
	return (ft_strncpy(result, s + i, ft_strlen(s) - i - j));
}

/*
** DESCRIPTION
** strtrim removes all whitespace characters from the beginning and the end,
** of a string.
** As whitespace is counted everything for which isspace(3) returns true.
** RETURN VALUE
** strtrim returns its argument.
*/

/*
** Second attempt
** char	*ft_strtrim(char const *s)
** {
**	int		i;
**	int		j;
**	char	*result;
**
**	if (s == NULL)
**		return (NULL);
**	i = 0;
**	j = ft_strlen(s) - 1;
**	while ((s[i]) && (s[i] == ' ' || s[i] == '\t' || s[i] == '\n'))
**		i++;
**	if (i == (int)ft_strlen(s))
**		return ("");
**	while ((s[j] == ' ' || s[j] == '\t' || s[j] == '\n') && j > 0)
**		j--;
**	j = ft_strlen(s) - j;
**	j--;
**	if (!(result = ft_strnew(ft_strlen(s) - (i + j))))
**		return (NULL);
**	return (ft_strncpy(result, s + i, ft_strlen(s) - i - j));
** }
*/

/*
** Firt attempt
** char	*ft_strtrim(char const *s)
** {
** size_t		i;
** size_t		j;
** char		*s;
** char		*result;
**
** i = 0;
** j = 0;
** if (!(s = (char *)malloc(sizeof(char) * ft_strlen(s))))
**	return (NULL);
** ft_strns(s, s, ft_strlen(s));
** while ((s[i]) && (s[i] == ' ' || s[i] == '\t' || s[i] == '\n'))
** 	i++;
** if (i == ft_strlen(s))
** 	return ("");
** s = ft_strrev(s);
** while (s[j] && (s[j] == ' ' || s[j] == '\t' || s[j] == '\n'))
** 	j++;
** j = ft_strlen(s) - (i + j);
** s = ft_strrev(s);
** if (!(result = (char *)malloc(sizeof(char) * (j))))
** 	return (NULL);
** result = ft_strns(result, &s[i], j);
** result[j] = '\0';
** return (result);
** }
*/
