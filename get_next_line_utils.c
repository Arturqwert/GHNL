#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int		i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*d;
	char	*s;

	d = (char *)dst;
	s = (char *)src;
	if (dst == src)
		return (dst);
	if (s < d)
	{
		while (len--)
			*(d + len) = *(s + len);
		return (dst);
	}
	while (len--)
		*d++ = *s++;
	return (dst);
}

char	*str_join(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*ret;

	if (!s1 && !s2)
		return (0);
	s1_len = ft_strlen((char *)s1);
	s2_len = ft_strlen((char *)s2);
	ret = calloc((s1_len + s2_len + 1), sizeof(char));
	if (!ret)
		return (0);
	ft_memmove(ret, s1, s1_len);
	ft_memmove(ret + s1_len, s2, s2_len);
	ret[s1_len + s2_len] = '\0';
	free((char *)s1);
	return (ret);
}

int	srchn(char *str)
{
	int		i;

	i = 0;
	if (str)
	{
		while (str[i])
		{
			if (str[i] == '\n')
				return (1);
			i++;
		}
	}
	return (0);
}

char	*get_reminder(char *reminder)
{
	char	*ret;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!reminder)
		return (0);
	while (reminder[i] && reminder[i] != '\n')
		i++;
	if (!reminder[i])
	{
		free(reminder);
		return (0);
	}
	ret = calloc(((ft_strlen(reminder) - i) + 1), sizeof(char));
	if (!ret)
		return (0);
	i++;
	while (reminder[i])
		ret[j++] = reminder[i++];
	ret[j] = '\0';
	free(reminder);
	return (ret);
}
