#include "get_next_line.h"

size_t	ft_gnl_strlen(const char *str)
{
	size_t	len;

	if (!str)
		return (0);
	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_gnl_strchr(const char *str, int c)
{
	unsigned char	ch;

	if (!str)
		return (NULL);
	ch = (unsigned char)c;
	while (*str)
	{
		if (*str == ch)
			return ((char *)str);
		str++;
	}
	if (*str == ch)
		return ((char *)str);
	return (NULL);
}

char	*ft_gnl_strjoin(char *s1, char *s2)
{
	char	*joined;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	joined = malloc(sizeof(char) * (ft_gnl_strlen(s1) + ft_gnl_strlen(s2) + 1));
	if (!joined)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
		joined[j++] = s1[i++];
	i = 0;
	while (s2[i])
		joined[j++] = s2[i++];
	joined[j] = '\0';
	free(s1);
	return (joined);
}

char	*ft_gnl_strdup(const char *src)
{
	char	*res;
	int		i;

	i = 0;
	if (!src)
		return (NULL);
	res = (char *)malloc ((ft_gnl_strlen(src) + 1) * sizeof(char));
	if (!res)
		return (NULL);
	while (src[i])
	{
		res[i] = src[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*ft_gnl_substr(const char *str, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	avail_len;

	if (!str)
		return (NULL);
	if (start >= ft_gnl_strlen(str))
		return (ft_gnl_strdup(""));
	avail_len = ft_gnl_strlen(str + start);
	if (avail_len < len)
		substr = malloc(sizeof(char) * (avail_len + 1));
	else
		substr = malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	i = 0;
	while (i < len && str[start + i])
	{
		substr[i] = str[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
