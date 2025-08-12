/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbauer <mbauer@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 13:36:01 by mbauer            #+#    #+#             */
/*   Updated: 2025/08/11 18:11:19 by mbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_read(char *nineway, int fd, char *buffer)
{
	char		*tmp_line;
	ssize_t		bytes_read;

	while (!ft_strchr(nineway, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(nineway);
			buffer[0] = '\0';
			return (NULL);
		}
		if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		tmp_line = ft_strjoin(nineway, buffer);
		if (!tmp_line)
			return (NULL);
		nineway = tmp_line;
	}
	return (nineway);
}

// The main get_next_line function refactored to use a one-dimensional
// static buffer. This version is simpler and more memory-efficient but
// can only handle one file descriptor at a time.
char	*get_next_line(int fd)
{
	static char	buffer[1024][BUFFER_SIZE + 1];
	char		*nineway;
	char		*res;
	char		*buff;

	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	buff = buffer[fd];
	nineway = NULL;
	nineway = ft_strjoin(NULL, buff);
	if (!nineway)
		return (NULL);
	nineway = ft_read(nineway, fd, buff);
	if (!nineway)
		return (buff[0] = '\0', NULL);
	res = ft_get_line(nineway);
	if (!res)
		return (buff[0] = '\0', free(nineway), NULL);
	if (res[0] == '\0')
		return (buff[0] = '\0', free(res), free(nineway), NULL);
	ft_clean_buff(buff);
	return (free(nineway), res);
}
