/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudding <sbudding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 13:15:58 by sbudding          #+#    #+#             */
/*   Updated: 2020/12/10 10:49:55 by sbudding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int				ft_file_was_read(char **line, char **save)
{
	int			ind;
	char		*tmp;

	if (*save && (ind = ft_strchr_ind(*save, '\n')) > -1)
	{
		(*save)[ind] = '\0';
		if ((!(*line = ft_strdup(*save))) ||
		(!(tmp = ft_strdup(*save + ind + 1))))
			return (-1);
		free(*save);
		*save = tmp;
		return (1);
	}
	else if (*save)
	{
		*line = *save;
		*save = 0;
		return (0);
	}
	*line = ft_strdup("");
	return (0);
}

int				ft_get_next_line(int fd, char **line, char *buff)
{
	static char	*save[256];
	int			count;
	int			ind;
	char		*tmp;

	while ((count = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[count] = '\0';
		if (!(save[fd] = ft_strjoin_gnl(save[fd], buff)))
			return (-1);
		if ((ind = ft_strchr_ind(save[fd], '\n')) > -1)
		{
			(save[fd])[ind] = '\0';
			if ((!(*line = ft_strdup(save[fd]))) ||
			(!(tmp = ft_strdup(save[fd] + ind + 1))))
				return (-1);
			free(save[fd]);
			save[fd] = tmp;
			free(buff);
			return (1);
		}
	}
	free(buff);
	return (ft_file_was_read(line, &save[fd]));
}

int				get_next_line(int fd, char **line)
{
	char		*buff;

	if ((fd < 0) || (line == NULL) || (BUFFER_SIZE < 1))
		return (-1);
	if (!(buff = (char *)malloc((BUFFER_SIZE + 1) * (sizeof(char)))))
		return (-1);
	if (read(fd, buff, 0) == -1)
	{
		free(buff);
		return (-1);
	}
	return (ft_get_next_line(fd, line, buff));
}
