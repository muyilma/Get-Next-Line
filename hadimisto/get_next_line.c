#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void *ft_memset(void *b, int c, size_t len)
{
	unsigned char *s;
	size_t i;

	s = b;
	i = 0;
	while (i < len)
	{
		*(s + i) = c;
		i++;
	}
	return (b);
}

void *ft_calloc(size_t count, size_t size)
{
	int *a;

	a = malloc(count * size);
	if (a == NULL)
		return (NULL);
	ft_memset(a, 0, count * size);
	return (a);
}

char *ft_read(int fd, char *str)
{
	char *readstr;
	int byte;
	char *tmp;

	readstr = ft_calloc(BUFFER_SIZE + 1, 1);
	if (!readstr)
		return NULL;
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
		if (byte == 0 && !str[0])
		{
			free(str);
			free(readstr);
			return (NULL);
		}
		tmp = str;
		str = ft_strjoin(str, readstr);
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

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);

	beforestr = NULL;
	j = -1;
	afterstr = ft_read(fd, afterstr);
	// if(!afterstr)
	//	return NULL;

	while (afterstr && afterstr[++j]) // sadece after str yazınca leak  gidiyor
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
	}
	return (beforestr);
}
