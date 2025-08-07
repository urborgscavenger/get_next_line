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

// // Helper function to find the length of a string.
// static size_t	ft_strlen(const char *s)
// {
// 	size_t	i;

// 	i = 0;
// 	if (!s)
// 		return (0);
// 	while (s[i])
// 		i++;
// 	return (i);
// }

// // Helper function to find the first occurrence of a character.
// static char	*ft_strchr(const char *s, int c)
// {
// 	int	i;

// 	i = 0;
// 	if (!s)
// 		return (NULL);
// 	while (s[i])
// 	{
// 		if (s[i] == (char)c)
// 			return ((char *)&s[i]);
// 		i++;
// 	}
// 	if ((char)c == '\0')
// 		return ((char *)&s[i]);
// 	return (NULL);
// }

// // Helper function to join two strings into a new one.
// static char	*ft_strjoin(char *s1, char const *s2)
// {
// 	char	*str;
// 	size_t	len1;
// 	size_t	len2;
// 	size_t	i;
// 	size_t	j;

// 	if (!s1)
// 	{
// 		s1 = (char *)malloc(1 * sizeof(char));
// 		if (!s1)
// 			return (NULL);
// 		s1[0] = '\0';
// 	}
// 	len1 = ft_strlen(s1);
// 	len2 = ft_strlen(s2);
// 	str = (char *)malloc((len1 + len2 + 1) * sizeof(char));
// 	if (!str)
// 		return (free(s1), NULL);
// 	i = -1;
// 	while (++i < len1)
// 		str[i] = s1[i];
// 	j = -1;
// 	while (++j < len2)
// 		str[i + j] = s2[j];
// 	str[i + j] = '\0';
// 	free(s1);
// 	return (str);
// }

// // Helper function to extract the next line from the buffer.
// static char	*extract_line(char *stash)
// {
// 	char	*line;
// 	size_t	i;
// 	size_t	len;

// 	if (!stash || !*stash)
// 		return (NULL);
// 	i = 0;
// 	while (stash[i] && stash[i] != '\n')
// 		i++;
// 	if (stash[i] == '\n')
// 		len = i + 1;
// 	else
// 		len = i;
// 	line = (char *)malloc((len + 1) * sizeof(char));
// 	if (!line)
// 		return (NULL);
// 	i = -1;
// 	while (++i < len)
// 		line[i] = stash[i];
// 	line[i] = '\0';
// 	return (line);
// }

// // Helper function to clean the buffer after a line has been extracted.
// static char	*clean_stash(char *stash)
// {
// 	char	*new_stash;
// 	char	*p;
// 	size_t	len;
// 	size_t	i;

// 	p = ft_strchr(stash, '\n');
// 	if (!p)
// 		return (free(stash), NULL);
// 	p++;
// 	if (!*p)
// 		return (free(stash), NULL);
// 	len = ft_strlen(p);
// 	new_stash = (char *)malloc((len + 1) * sizeof(char));
// 	if (!new_stash)
// 		return (free(stash), NULL);
// 	i = -1;
// 	while (++i < len)
// 		new_stash[i] = p[i];
// 	new_stash[i] = '\0';
// 	free(stash);
// 	return (new_stash);
// }

// Main function to read a line from a file descriptor.
char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;
	char		buffer[BUFFER_SIZE + 1];
	ssize_t		bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	while (!ft_strchr(stash, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(stash);
			stash = NULL;
			return (NULL);
		}
		if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		stash = ft_strjoin(stash, buffer);
		if (!stash)
			return (NULL);
	}
	line = extract_line(stash);
	if (!line)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	stash = clean_stash(stash);
	return (line);
}
