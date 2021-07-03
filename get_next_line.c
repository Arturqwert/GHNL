#include "get_next_line.h"

char	*get_line(char *str)
{
	int		i;
	char	*tmp;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	tmp = calloc((i + 1), sizeof(char));
	if (!tmp)
		return (0);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		tmp[i] = str[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

int		get_next_line(int fd, char **line)
{
	static char		*reminder;
	char			*buff;
	int				bwr;

	bwr = 1;
	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	buff = calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!buff)
		return (-1);
	while (!srchn(reminder) && bwr != 0)
	{
		bwr = read(fd, buff, BUFFER_SIZE);
		if (bwr == -1)
		{
			free(buff);
			return (-1);
		}
		buff[bwr] = '\0';
		reminder = str_join(reminder, buff);
	}
	free(buff);
	*line = get_line(reminder);
	reminder = get_reminder(reminder);
	if (bwr || ft_strlen(reminder) || ft_strlen(*line))
		return (1);
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
