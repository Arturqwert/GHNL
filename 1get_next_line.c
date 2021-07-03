#include "get_next_line.h"

size_t ft_strlen( const char * string )
{
	size_t	i;
	i = 0;
	while (string[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	str = (char *)malloc(sizeof(*s1) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	i = 0;
	j = 0;
	if (str)
	{
		while (s1[i])
			str[j++] = s1[i++];
		i = 0;
		while (s2[i])
			str[j++] = s2[i++];
		str[j] = '\0';
		return (str);
	}
	return (NULL);
}

char	*ft_strchr(const char *string, int symbol)
{
	int		i;

	i = 0;
	while (string[i])
	{
		if (string[i] == (char)symbol)
			return ((char *)&string[i]);
		i++;
	}
	if ((char)symbol == '\0' && string[i] == (char)symbol)
		return ((char *)&string[i]);
	return (NULL);
}

char	*ft_strdup(const char *s1)
{
	char			*ptr;
	unsigned int	i;
	unsigned int	len;

	i = 0;
	len = ft_strlen(s1);
	ptr = (char *)malloc(sizeof(char) * len + 1);
	if (ptr == NULL)
		return (NULL);
	while (s1[i])
	{
		ptr[i] = ((char *)s1)[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_strcpy(char *dst, const char *src)
{
	size_t		i;

	i = 0;

	while (src[i])
	{
		dst[i] = ((unsigned char *)src)[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

void	ft_strclr(char *s)
{
	if (s)
	{
		while (*s)
		{
			*s = '\0';
			s++;
		}
	}
}

char	*ft_strnew(size_t size)
{
	char *str;

	str = (char *)malloc(sizeof(char) * (size + 1));
	if (str == NULL)
		return (NULL);
	while (size > 0)
		str[size--] = '\0';
	str[0] = '\0';
	return (str);
}

char	*check_start(char *start, char **line)
{
	char	*ptr;

	ptr = NULL;
	if (start)
	{
		if ((ptr = ft_strchr(start, '\n')))
		{
			*ptr = '\0';
			*line = ft_strdup(start);
			ptr++;
			ft_strcpy(start, ptr);	
		}
		else
		{
			*line = ft_strdup(start);
			ft_strclr(start);
		}
	}
	else
		*line = ft_strnew(1);
	return (ptr);
}

int		get_next_line(int fd, char **line)
{
	if (fd < 0 || line == NULL || BUFF_SIZE <= 0)
		return (-1);

	char		buf[BUFF_SIZE + 1];
	int			dig;
	char		*ptr;
	char		*tmp;
	static char	*start;

	ptr = check_start(start, line);

	while (!ptr && (dig = read(fd, buf, BUFF_SIZE)))
	{
		buf[dig] = '\0';
		if ((ptr = ft_strchr(buf, '\n')))
		{
			*ptr = '\0';
			ptr++;
			start = ft_strdup(ptr);
		}
		tmp = *line;
		*line = ft_strjoin(*line, buf);
		free(tmp);
	}
	if (dig || ft_strlen(start) || ft_strlen(*line))
		return (1);
	if (dig == 0 || ft_strlen(start) == 0 || ft_strlen(*line) == 0)
		return (0);
	
	//return (dig || ft_strlen(start) || ft_strlen(*line)) ? 1 : 0;
}

int main()
{
	char 	*line;
	
	int		fd;
	fd = open("text.txt", O_RDONLY);
	while (get_next_line(fd, &line))
	{
		printf("%s\n", line);
	}
}
