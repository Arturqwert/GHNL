#include "get_next_line.h"

//add comment
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

int	ft_read(int fd, char **reminder, char *buff)
{
	int	bwr;

	bwr = 1;
	while (!srchn(*reminder) && bwr != 0)
	{
		bwr = read(fd, buff, BUFFER_SIZE);
		if (bwr == -1)
			return (-1);
		buff[bwr] = '\0';
		*reminder = str_join(*reminder, buff);
	}
	return (bwr);
}

int	get_next_line(int fd, char **line)
{
	static char		*reminder;
	char			*buff;
	int				bwr;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	buff = calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!buff)
		return (-1);
	bwr = ft_read(fd, &reminder, buff);
	free(buff);
	if (bwr == -1)
		return (-1);
	*line = get_line(reminder);
	reminder = get_reminder(reminder);
	if (bwr == 0)
		return (0);
	return (1);
}
