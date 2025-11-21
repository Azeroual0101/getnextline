/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdazero <abdazero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 15:47:24 by abdazero          #+#    #+#             */
/*   Updated: 2025/11/21 16:08:10 by abdazero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_gnl_strchr(const char *s, int c)
{
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	if (c == '\0')
		return ((char *)(s + i));
	return (NULL);
}

static char	*ft_read_chunk(int fd, char *stash)
{
	char	*buffer;
	ssize_t	bytes_read;
	char	*tmp;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read <= 0)
	{
		free(buffer);
		return (stash);
	}
	buffer[bytes_read] = '\0';
	tmp = ft_gnl_strjoin(stash, buffer);
	free(stash);
	free(buffer);
	return (tmp);
}

static char	*ft_read_fd(int fd, char *stash)
{
	ssize_t	bytes_read;

	bytes_read = 1;
	while (!ft_gnl_strchr(stash, '\n') && bytes_read > 0)
	{
		stash = ft_read_chunk(fd, stash);
		if (!stash)
			return (NULL);
		if (!ft_gnl_strchr(stash, '\n'))
			bytes_read = 1;
		else
			bytes_read = 0;
	}
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = ft_read_fd(fd, stash);
	if (!stash)
		return (NULL);
	line = ft_extract_line(stash);
	stash = ft_extract_remainder(stash);
	return (line);
}
