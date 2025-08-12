/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbauer <mbauer@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 13:36:01 by mbauer            #+#    #+#             */
/*   Updated: 2025/08/11 18:08:48 by mbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	static char	buffer[BUFFER_SIZE + 1];
	char		*nineway;
	char		*res;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	nineway = NULL;
	nineway = ft_strjoin(NULL, buffer);
	if (!nineway)
		return (NULL);
	nineway = ft_read(nineway, fd, buffer);
	if (!nineway)
	{
		return (buffer[0] = '\0', NULL);
	}
	res = ft_get_line(nineway);
	if (!res)
		return (buffer[0] = '\0', free(nineway), NULL);
	if (res[0] == '\0')
		return (buffer[0] = '\0', free(res), free(nineway), NULL);
	ft_clean_buff(buffer);
	return (free(nineway), res);
}
