/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 17:10:09 by nivergne          #+#    #+#             */
/*   Updated: 2019/09/19 04:04:06 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <limits.h>


static int	get_return(char **line)
{
	if ((**line))
		return (1);
	else
	{
		ft_strdel(line);
		return (0);
	}
}

int			get_next_line(const int fd, char **line)
{
	static char	fdstock[FOPEN_MAX][BUFF_SIZE + 1];
	char		*tmp;
	int			ret;

	tmp = fdstock[fd];
	if (!line || fd < 0 || BUFF_SIZE < 1 || read(fd, NULL, 0) < 0)
		return (-1);
	if (!((*line) = ft_strnew(0)))
		return (-1);
	while (1)
	{
		if (ft_strchr(tmp, '\n'))
		{
			(*line) = ft_strnjoinf((*line), tmp, 1,
				(ft_strchr(tmp, '\n') - tmp));
			ft_strncpy(tmp, &tmp[ft_strchr(tmp, '\n') - tmp + 1],
				BUFF_SIZE - (ft_strchr(tmp, '\n') - tmp));
			return (1);
		}
		(*line) = ft_strnjoinf((*line), tmp, 1, BUFF_SIZE);
		ret = read(fd, fdstock[fd], BUFF_SIZE);
		tmp[ret] = '\0';
		if (ret == 0)
			return (get_return(line) == 1 ? 1 : 0);
	}
}

/*
** ================ OLD VERSION ============================
**
** static int	find_newline(char *store)
** {
** 	int	i;
**
** 	i = 0;
** 	while (store[i] && store[i] != '\n')
** 		i++;
** 	if (store[i] == '\n')
** 		return (i);
** 	else
** 		return (-1);
** }
**
** static char	*join_free(char *store, char buff[BUFF_SIZE])
** {
** 	int		i;
** 	int		j;
** 	char	*join;
**
** 	i = 0;
** 	j = 0;
** 	if (store)
** 		i = ft_strlen(store);
** 	if (buff)
** 		j = ft_strlen(buff);
** 	if (!(join = (char *)malloc(sizeof(char) * (i + j + 1))))
** 		return (NULL);
** 	ft_memcpy(join, store, i);
** 	ft_memcpy(join + i, buff, j);
** 	join[i + j] = '\0';
** 	free(store);
** 	return (join);
** }
**
** static int	assign_line(char **store, char buff[BUFF_SIZE], char **line)
** {
** 	int		index;
** 	char	*tmp;
**
** 	*store = join_free(*store, buff);
** 	index = find_newline(*store);
** 	if (index != -1)
** 	{
** 		tmp = *store;
** 		*line = ft_strsub(*store, 0, index);
** 		tmp = ft_strdup(*store + index + 1);
** 		ft_strdel(store);
** 		*store = tmp;
** 		return (1);
** 	}
** 	return (0);
** }
**
** int			get_next_line(const int fd, char **line)
** {
** 	int				ret;
** 	int				ret_2;
** 	char			buff[BUFF_SIZE];
** 	static char		*store[10000];
**
** 	if (!line || BUFF_SIZE <= 0 || (ret = read(fd, buff, 0)) < 0)
** 		return (-1);
** 	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
** 	{
** 		buff[ret] = 0;
** 		ret_2 = assign_line(&store[fd], buff, line);
** 		ft_bzero((void *)buff, BUFF_SIZE);
** 		if (ret_2 == 1)
** 			return (1);
** 	}
** 	ft_bzero((void *)buff, BUFF_SIZE);
** 	if (assign_line(&store[fd], buff, line) == 1)
** 		return (1);
** 	else if (ft_strlen(store[fd]) > 0)
** 	{
** 		*line = ft_strdup(store[fd]);
** 		ft_strdel(&store[fd]);
** 		return (1);
** 	}
** 	return (0);
** }
*/
