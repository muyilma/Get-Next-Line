#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char	*ft_read(int fd, char *str)
{
	char	*readstr;
	int		byte;
	char	*tmp;

	readstr = calloc(BUFFER_SIZE + 1, 1);
	byte = 1;
	if (!str)
		str = ft_strdup("");
	while (ft_strchr(readstr, '\n') == 0 && byte > 0)
	{
		byte = read(fd, readstr, BUFFER_SIZE);
		if (byte == -1)
		{
			free(str);
			free(readstr);
			return (NULL);
		}
		readstr[byte] = '\0';
		if (byte == 0)
		{
			if (!str[0])
			{
				free(str);
				free(readstr);
				return (NULL);
			}
		}
		tmp = str;
		str = ft_strjoin(str, readstr);
		free(tmp);
	}
	free(readstr);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*afterstr;
	int			j;
	char		*beforestr;
	char		*temp;

	temp = NULL;
	beforestr = NULL;
	j = 0;
	afterstr = ft_read(fd, afterstr);
	while (afterstr && afterstr[j])
	{
		if (afterstr[j] == '\n' || afterstr[j + 1] == '\0')
		{
			j++;
			beforestr = ft_substr(afterstr, 0, j);
			temp = afterstr;
			afterstr = ft_strdup(afterstr + j);
			free(temp);
			return (beforestr);
		}
		j++;
	}
	return (beforestr);
}
