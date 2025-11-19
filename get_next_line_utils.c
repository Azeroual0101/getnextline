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

char	*ft_gnl_strchr(const char *s, int c)
{
	unsigned char	ch;

	if (!s)
		return (NULL);
	ch = (unsigned char)c;
	while (*s)
	{
		if (*s == ch)
			return ((char *)s);
		s++;
	}
	if (*s == ch)
		return ((char *)s);
	return (NULL);
}

static void	ft_gnl_concat(char *dest, const char *s1, const char *s2)
{
	size_t	i = 0;
	size_t	j = 0;

	if (s1)
	{
		while (s1[i])
		{
			dest[i] = s1[i];
			i++;
		}
	}
	if (s2)
	{
		while (s2[j])
		{
			dest[i + j] = s2[j];
			j++;
		}
	}
	dest[i + j] = '\0';
}

char	*ft_gnl_strjoin(char *s1, char *s2)
{
	size_t	len1 = ft_gnl_strlen(s1);
	size_t	len2 = ft_gnl_strlen(s2);
	char	*result;

	result = malloc(len1 + len2 + 1);
	if (!result)
		return (NULL);
	ft_gnl_concat(result, s1, s2);
	return (result);
}

char	*ft_extract_line(char *stash)
{
	int	i = 0;
	char	*line;

	if (!stash || !*stash)
		return (NULL);

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
		line[i++] = '\n';
	line[i] = '\0';

	return (line);
}

char	*ft_extract_remainder(char *stash)
{
	int	i = 0;
	int	j = 0;
	char	*remainder;

	if (!stash)
		return (NULL);

	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
	{
		free(stash);
		return (NULL);
	}
	i++;

	remainder = malloc(ft_gnl_strlen(stash) - i + 1);
	if (!remainder)
	{
		free(stash);
		return (NULL);
	}

	while (stash[i])
		remainder[j++] = stash[i++];
	remainder[j] = '\0';
	free(stash);
	return (remainder);
}