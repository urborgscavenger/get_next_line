/* ************************************************************************** */
/* */
/* :::      ::::::::   */
/* get_next_line.c                                    :+:      :+:    :+:   */
/* +:+ +:+         +:+     */
/* By: gemini <gemini@student.42.fr>              +#+  +:+       +#+        */
/* +#+#+#+#+#+   +#+           */
/* Created: 2024/07/15 10:00:00 by gemini            #+#    #+#             */
/* Updated: 2024/07/15 10:00:00 by gemini           ###   ########.fr       */
/* */
/* ************************************************************************** */

#include "get_next_line.h"

// The main get_next_line function refactored to use a one-dimensional
// static buffer. This version is simpler and more memory-efficient but
// can only handle one file descriptor at a time.
char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*nineway;
	char		*res;
	char		*tmp_line;
	ssize_t		bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	nineway = NULL;
	if (buffer[0])
	{
		nineway = ft_strjoin(NULL, buffer);
		if (!nineway)
			return (NULL);
	}
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
		{
			free(nineway);
			return (NULL);
		}
		nineway = tmp_line;
	}
	res = ft_get_line(nineway);
	if (!res)
	{
		free(nineway);
		buffer[0] = '\0';
		return (NULL);
	}
	if (res[0] == '\0')
	{
		free(res);
		free(nineway);
		buffer[0] = '\0';
		return (NULL);
	}
	ft_clean_buff(buffer);
	free(nineway);
	return (res);
}
