#include "get_next_line.h"

char *get_next_line(int fd)
{
	static char *stash = NULL;
	char *buffer;
	char *line;
	ssize_t bytes_read;

	// Input validation
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);

	// Allocate buffer on heap, not stack
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);

	// Read until we find a newline or EOF
	while (!ft_gnl_strchr(stash, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(buffer);
			free(stash);
			stash = NULL;
			return (NULL);
		}
		if (bytes_read == 0)
			break;
		buffer[bytes_read] = '\0';
		char *tmp = ft_gnl_strjoin(stash, buffer);
		free(stash);
		if (!tmp)
		{
			free(buffer);
			return (NULL);
		}
		stash = tmp;
	}

	free(buffer);

	// Extract and return the line
	line = ft_extract_line(stash);
	char *new_stash = ft_extract_remainder(stash);
	stash = new_stash;

	return (line);
}