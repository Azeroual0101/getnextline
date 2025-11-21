/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdazero <abdazero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 15:47:28 by abdazero          #+#    #+#             */
/*   Updated: 2025/11/21 16:07:49 by abdazero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_gnl_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_gnl_strjoin(char *s1, char *s2)
{
	size_t	len1;
	size_t	len2;
	char	*result;
	size_t	i;
	size_t	j;

	len1 = ft_gnl_strlen(s1);
	len2 = ft_gnl_strlen(s2);
	result = malloc(len1 + len2 + 1);
	if (!result)
		return (NULL);
	i = 0;
	j = 0;
	while (s1 && s1[i])
	{
		result[i] = s1[i];
		i++;
	}
	while (s2 && s2[j])
	{
		result[i + j] = s2[j];
		j++;
	}
	result[i + j] = '\0';
	return (result);
}

char	*ft_extract_line(char *stash)
{
	int		i;
	char	*line;

	if (!stash || !*stash)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	line = malloc(i + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
	{
		line[i++] = '\n';
	}
	line[i] = '\0';
	return (line);
}

static int	ft_after_newline(char *stash)
{
	int	i;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	return (i);
}

char	*ft_extract_remainder(char *stash)
{
	int		i;
	int		j;
	char	*rem;

	if (!stash)
		return (NULL);
	i = ft_after_newline(stash);
	if (!stash[i - 1])
	{
		free(stash);
		return (NULL);
	}
	rem = malloc(ft_gnl_strlen(stash) - i + 1);
	if (!rem)
	{
		free(stash);
		return (NULL);
	}
	j = 0;
	while (stash[i])
		rem[j++] = stash[i++];
	rem[j] = '\0';
	free(stash);
	return (rem);
}
