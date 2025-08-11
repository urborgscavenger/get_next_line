/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbauer <mbauer@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 13:51:38 by mbauer            #+#    #+#             */
/*   Updated: 2025/08/11 14:18:22 by mbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

// Standard library includes for file operations and memory allocation.
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h> // Include for open() function in the tester.

// Define the BUFFER_SIZE for reading from the file descriptor.
// This value can be changed to optimize performance.
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

// Function prototypes for get_next_line and its helper functions.
char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *s1, const char *s2);
char	*ft_get_line(char *line);
int		ft_clean_buff(char *buffer);

#endif
