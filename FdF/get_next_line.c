/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivasche <mivasche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 13:57:05 by mivasche          #+#    #+#             */
/*   Updated: 2019/03/28 16:59:09 by mivasche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

int			retu_num_end(char *tmp)
{
	int			ind;

	ind = 0;
	while (tmp[ind] != '\n' && tmp[ind])
		ind++;
	if (tmp[ind] == '\n')
		return (ind);
	return (0);
}

static int	ft_check_end(char **tmp, char **line)
{
	char		*save_tmp;
	int			cmp;

	save_tmp = *tmp;
	cmp = retu_num_end(save_tmp);
	if (cmp > 0)
	{
		*line = ft_strnew(cmp);
		ft_strncpy(*line, save_tmp, cmp);
		*tmp = ft_strsub(save_tmp, cmp + 1, ft_strlen(save_tmp) - (cmp + 1));
		free(save_tmp);
		return (1);
	}
	return (0);
}

static int	ft_cpy_buff(char **tmp, int byte, char *buff, char **line)
{
	char		*save_tmp;

	buff[byte] = '\0';
	if (*tmp == NULL)
		*tmp = ft_strdup(buff);
	else
	{
		save_tmp = *tmp;
		*tmp = ft_strjoin(save_tmp, buff);
		free(save_tmp);
	}
	if (ft_check_end(tmp, line))
	{
		free(buff);
		return (1);
	}
	return (0);
}

int			get_next_line(const int fd, char **line)
{
	char		*buff;
	static char	*tmp[MAX_FD_NUM];
	size_t		byte;

	buff = NULL;
	if (BUFF_SIZE < 1 || fd > MAX_FD_NUM || read(fd, buff, 0) == -1 || fd < 0
		|| !line)
		return (-1);
	if (tmp[fd] != NULL)
		if (ft_check_end(&tmp[fd], line))
			return (1);
	buff = ft_strnew(BUFF_SIZE + 1);
	while ((byte = read(fd, buff, BUFF_SIZE)))
		if (ft_cpy_buff(&tmp[fd], byte, buff, line))
			return (1);
	if (tmp[fd] == NULL || *tmp[fd] == '\0')
	{
		free(buff);
		return (0);
	}
	*line = ft_strdup(tmp[fd]);
	free(buff);
	ft_strdel(&tmp[fd]);
	return (1);
}
