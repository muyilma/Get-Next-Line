#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char	*ft_read(int fd, char *str)
{
	char	*readstr;
	int		byte;

	if (str == NULL)
		str = malloc(1);
	readstr = malloc(BUFFER_SIZE + 1);
	byte = 1;
	while (byte > 0)
	{
		byte = read(fd, readstr, BUFFER_SIZE);
		if (byte == 0)
		{
			free(readstr);
			return (str);
		}
		
		readstr[byte] = '\0';
		str = ft_strjoin(str, readstr);
		if (ft_strchr(readstr, '\n'))
		{
			free(readstr);
			return (str);
		}
	}
	free(readstr);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*afterstr;
	int			j;
	char		*beforestr;

	beforestr = malloc(BUFFER_SIZE);
	afterstr = ft_read(fd, afterstr);
	j = 0;
	while (afterstr[j])
	{
		if (afterstr[j] == '\n' || afterstr[j + 1] == '\0')
		{
			j++;
			beforestr = ft_substr(afterstr, 0, j);
			afterstr += j;
			return (beforestr);
		}
		j++;
	}
	return (beforestr);
}

int	main(void)
{
	int		fd;
	char	*str;

	fd = open("test.txt", O_CREAT | O_RDWR, 0777);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	
}
