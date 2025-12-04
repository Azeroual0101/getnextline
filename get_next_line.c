/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdazero <abdazero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 21:50:29 by abdazero          #+#    #+#             */
/*   Updated: 2025/12/04 22:06:26 by abdazero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*init_stash(char *stash, char **buffer)
{
	*buffer = malloc((size_t)BUFFER_SIZE + 1);
	if (!*buffer)
		return (free(stash), NULL);
	if (!stash)
	{
		stash = ft_gnl_strdup("");
		if (!stash)
			return (free(*buffer), NULL);
	}
	return (stash);
}

static char	*read_into_stash(int fd, char *stash)
{
	ssize_t	bytes_read;
	char	*buffer;
	char	*tmp;

	stash = init_stash(stash, &buffer);
	if (!stash)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0 && ft_gnl_strchr(stash, '\n') == NULL)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (free(buffer), free(stash), NULL);
		buffer[bytes_read] = '\0';
		tmp = stash;
		stash = ft_gnl_strjoin(tmp, buffer);
		if (!stash)
			return (free(buffer), NULL);
	}
	free(buffer);
	if (stash[0] == '\0')
		return (free(stash), NULL);
	return (stash);
}

static char	*extract_line(char *stash)
{
	size_t	i;
	char	*line;

	i = 0;
	if (!stash || ft_gnl_strlen(stash) == 0)
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	line = ft_gnl_substr(stash, 0, i);
	if (!line)
		return (NULL);
	return (line);
}

static char	*update_stash(char *stash)
{
	size_t	i;
	char	*new_stash;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	if (stash[i] == '\0')
	{
		free(stash);
		return (NULL);
	}
	new_stash = ft_gnl_strdup(stash + i);
	free(stash);
	return (new_stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	stash = read_into_stash(fd, stash);
	if (!stash)
		return (NULL);
	line = extract_line(stash);
	stash = update_stash(stash);
	return (line);
}
