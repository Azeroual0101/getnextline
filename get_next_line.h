#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# if BUFFER_SIZE < 1
#  error "BUFFER_SIZE must be at least 1"
# endif

char	*get_next_line(int fd);

// Utils
size_t	ft_gnl_strlen(const char *s);
char	*ft_gnl_strchr(const char *s, int c);
char	*ft_gnl_strjoin(char *s1, char *s2);
char	*ft_extract_line(char *stash);
char	*ft_extract_remainder(char *stash);

#endif