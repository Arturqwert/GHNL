#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42

int					get_next_line(int fd, char **line);
int					srchn(char *str);

size_t				ft_strlen(const char *s);

char				*join_str(const char *s1, const char *s2);
char				*get_line(char *str);
char				*get_save(char *save);

#endif