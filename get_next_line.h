/* ************************************************************************** */
/* */
/* :::      ::::::::   */
/* get_next_line.h                                    :+:      :+:    :+:   */
/* +:+ +:+         +:+     */
/* By: gemini <gemini@student.42.fr>              +#+  +:+       +#+        */
/* +#+#+#+#+#+   +#+           */
/* Created: 2024/07/15 10:00:00 by gemini            #+#    #+#             */
/* Updated: 2024/07/15 10:00:00 by gemini           ###   ########.fr       */
/* */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

// Standard library includes for file operations and memory allocation.
# include <unistd.h>
# include <stdlib.h>

// Define the BUFFER_SIZE for reading from the file descriptor.
// This value can be changed to optimize performance.
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

// Function prototypes for get_next_line and its helper functions.
// Note that the 'static' keyword has been removed from the helper
// functions to allow them to be used in a separate file.
char	*get_next_line(int fd);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *s1, char const *s2);
size_t	ft_strlen(const char *s);
char	*extract_line(char *stash);
char	*clean_stash(char *stash);

#endif