#include "get_next_line.h"

char	*get_line(char *str)
{
	int		i;
	char	*rtn;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	if (!(rtn = malloc(sizeof(char) * (i + 1))))
		return (0);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		rtn[i] = str[i];
		i++;
	}
	rtn[i] = '\0';
	return (rtn);
}

int		get_next_line(int fd, char **line)
{
	char			*buff;
	static char		*save;
	int				reader;

	reader = 1;
	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	if (!(buff = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	while (!srchn(save) && reader != 0)
	{
		reader = read(fd, buff, BUFFER_SIZE);
		if (reader == -1)
		{
			free(buff);
			return (-1);
		}
		buff[reader] = '\0';
		save = join_str(save, buff);
	}
	free(buff);
	*line = get_line(save);
	save = get_save(save);
	if (reader || ft_strlen(save) || ft_strlen(*line))
		return (1);
	if (reader == 0 || ft_strlen(save) == 0 || ft_strlen(*line) == 0)
		return (0);
}

// int main()
// {
// 	char 	*line;
	
// 	int		fd;
// 	fd = open("text.txt", O_RDONLY);
// 	while (get_next_line(fd, &line))
// 	{
// 		printf("%s\n", line);
// 	}
// }
