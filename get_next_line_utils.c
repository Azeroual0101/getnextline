#include "get_next_line.h"

size_t gnl_strlen(const char *s)
{
    int i;

    if (!s)
        return (0);
    i = 0;
    while(s[i])
        i++;
    return (i);
}

char *gnl_strchr(const char *s, int c)
{
    unsigned char ch;

    if (!s)
        return (NULL);
    ch = (unsigned char)c;
    while (*s)
    {
        if (*s == ch)
            return (char *)s;
        s++;
    }
    if (*s == ch)
        return (char *)s;
    return (NULL);
}


static void	ft_concat(char *dest, char *s1, char *s2)
{
	size_t i = 0;
	size_t j = 0;

	while (s1 && s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	while (s2 && s2[j])
	{
		dest[i] = s2[j];
		i++;
		j++;
	}
	dest[i] = '\0';
}

char *gnl_strjoin(char *s1, char *s2)
{
	size_t size;
	char *result;

	if (!s1 && !s2)
		return NULL;
	if (!s1)
		s1 = "";
	if (!s2)
		s2 = "";

	size = gnl_strlen(s1) + gnl_strlen(s2);
	result = malloc(size + 1);
	if (!result)
		return NULL;

	ft_concat(result, s1, s2);
	return result;
}

char    *extract_line(char *stash)
{
    int i;
    char *extract;

    if (!stash || !*stash)
        return (NULL);
    i = 0;
    while(stash[i] != 10 && stash[i])
        i++;
    if (stash[i] == '\n')
    i++;

    stash = malloc(i + 1);
    i = 0;
    while (stash[i] && stash[i] != '\n')
    {
        extract[i] = stash[i];
        i++;
    }
    if (stash[i] == '\n')
    {
        extract[i] = stash[i];
        i++;
    }
    extract[i] = '\0';
    return (extract);
}