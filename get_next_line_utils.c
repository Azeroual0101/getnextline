/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdazero <abdazero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 21:50:25 by abdazero          #+#    #+#             */
/*   Updated: 2025/11/29 21:53:41 by abdazero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_gnl_strlen(const char *str)
{
	size_t	length;

	if (!str)
		return (0);
	length = 0;
	while (str[length])
		length++;
	return (length);
}

char	*ft_gnl_strchr(const char *str, int c)
{
	unsigned char	target;

	if (!str)
		return (NULL);
	target = (unsigned char)c;
	while (*str)
	{
		if (*str == target)
			return ((char *)str);
		str++;
	}
	if (*str == target)
		return ((char *)str);
	return (NULL);
}

char	*ft_gnl_strjoin(char *first, char *second)
{
	char	*buffer;
	int		index_a;
	int		index_b;

	if (!first || !second)
		return (NULL);
	buffer = malloc((ft_gnl_strlen(first) + ft_gnl_strlen(second) + 1));
	if (!buffer)
		return (NULL);
	index_a = 0;
	index_b = 0;
	while (first[index_a])
		buffer[index_b++] = first[index_a++];
	index_a = 0;
	while (second[index_a])
		buffer[index_b++] = second[index_a++];
	buffer[index_b] = '\0';
	free(first);
	return (buffer);
}

char	*ft_gnl_strdup(const char *source)
{
	char	*copy;
	int		idx;

	idx = 0;
	if (!source)
		return (NULL);
	copy = (char *)malloc ((ft_gnl_strlen(source) + 1) * sizeof(char));
	if (!copy)
		return (NULL);
	while (source[idx])
	{
		copy[idx] = source[idx];
		idx++;
	}
	copy[idx] = '\0';
	return (copy);
}

char	*ft_gnl_substr(const char *str, unsigned int start, size_t length)
{
	char		*slice;
	size_t		pos;
	size_t		remain_len;

	if (!str)
		return (NULL);
	if (start >= ft_gnl_strlen(str))
		return (ft_gnl_strdup(""));
	remain_len = ft_gnl_strlen(str + start);
	if (remain_len < length)
		slice = malloc(sizeof(char) * (remain_len + 1));
	else
		slice = malloc(sizeof(char) * (length + 1));
	if (!slice)
		return (NULL);
	pos = 0;
	while (pos < length && str[start + pos])
	{
		slice[pos] = str[start + pos];
		pos++;
	}
	slice[pos] = '\0';
	return (slice);
}
