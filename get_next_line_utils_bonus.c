/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbauer <mbauer@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 13:51:48 by mbauer            #+#    #+#             */
/*   Updated: 2025/08/11 14:43:21 by mbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

// Helper function to find the length of a string.
size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

// Helper function to find the first occurrence of a character.
char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}

// Helper function to join two strings into a new one,
// freeing the first string (s1).
// len1 = ;
// len2 = ft_strlen(s2);
// size_t	len1;
// size_t	len2;
char	*ft_strjoin(char *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	str = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!str)
		return (free(s1), NULL);
	i = -1;
	while (++i < ft_strlen(s1))
		str[i] = s1[i];
	j = -1;
	while (++j < ft_strlen(s2))
		str[i + j] = s2[j];
	str[i + j] = '\0';
	return (free(s1), str);
}

// Helper function to extract a single line from a larger string.
char	*ft_get_line(char *line)
{
	char	*tmp;
	size_t	i;
	size_t	j;

	if (!line || !*line)
		return (NULL);
	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i] == '\n')
		i++;
	tmp = (char *)malloc((i + 1) * sizeof(char));
	if (!tmp)
		return (NULL);
	j = 0;
	while (j < i)
	{
		tmp[j] = line[j];
		j++;
	}
	tmp[j] = '\0';
	return (tmp);
}

// Helper function to clean the buffer by shifting the remaining content.
// This is a non-malloc approach to prevent leaks.
int	ft_clean_buff(char *buffer)
{
	size_t	i;
	char	*start;

	start = ft_strchr(buffer, '\n');
	if (!start)
	{
		buffer[0] = '\0';
		return (0);
	}
	start++;
	i = 0;
	while (start[i])
	{
		buffer[i] = start[i];
		i++;
	}
	buffer[i] = '\0';
	return (1);
}
