#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>  

char    *get_next_line(int fd);

size_t  gnl_strlen(const char *s);
char    *gnl_strchr(const char *s, int c);
char    *gnl_strjoin(char *s1, char *s2);
char    *extract_line(char *stash);
char    *extract_remainder(char *stash);

#endif
