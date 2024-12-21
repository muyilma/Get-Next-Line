#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char *ft_read(int fd, char *str)
{
	char *readstr;
	int byte;
	readstr = calloc(BUFFER_SIZE + 1, 1);

	// if (!readstr)
	//	return NULL;
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
			return NULL;
		}
		readstr[byte] = '\0';
		char *tmp = str;
		str = ft_strjoin(tmp, readstr);
		free(tmp);
	}
	free(readstr);
	return (str);
}

char *get_next_line(int fd)
{
	static char *afterstr;
	int j;
	char *beforestr;
	char *temp;
	beforestr = NULL;
	// if (fd < 0 && BUFFER_SIZE < 1)
	//	return (NULL);
	j = 0;
	afterstr = ft_read(fd, afterstr);
	if (!afterstr)
		return NULL;
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
// int main(void)
//{
//	char *str;
//	int fd;
//	fd = open("test.txt", O_CREAT | O_RDWR, 0777);
//
//	str = get_next_line(fd);
//	printf("%s", str);
//	free(str);
// }