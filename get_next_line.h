#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char				*str_join(const char *s1, const char *s2);
char				*get_line(char *str);
char				*get_reminder(char *save);
int					get_next_line(int fd, char **line);
int					srchn(char *str);
size_t				ft_strlen(const char *s);

#endif