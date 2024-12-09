#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*a;
	unsigned int	i;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (calloc(sizeof(char), 1));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	a = malloc(len * sizeof(char) + 1);
	if (a == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		a[i] = s[start + i];
		i++;
	}
	a[i] = '\0';
	return (a);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}
char	*ft_strjoin(char const *s1, char const *s2)
{
	int		a;
	char	*str;
	int		i;
	int		b;

	a = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(a + 1);
	if (str == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	b = 0;
	while (s2[b])
	{
		str[i] = s2[b];
		b++;
		i++;
	}
	str[i] = '\0';
	return (str);
}

// char	*get_next_line(int fd)
// {
// 	static char	*afterstr;
// 	char		*str;
// 	int			j;
// 	char		*beforestr;

// 	beforestr = malloc(BUFFER_SIZE);
// 	str = malloc(BUFFER_SIZE);
// 	str = ft_strjoin(str, afterstr);
// 	j = 0;
// 	if (afterstr == NULL)
// 	{
// 		afterstr = malloc(BUFFER_SIZE);
// 		read(fd, afterstr, BUFFER_SIZE);
// 	}
// 	while (afterstr[j])
// 	{
// 		while (afterstr[j])
// 		{
// 			if (afterstr[j] == '\n')
// 			{
// 				j++;
// 				str = ft_substr(afterstr, 0, j);
// 				afterstr += j;
// 				beforestr = ft_strjoin(beforestr, str);
// 				return (beforestr);
// 			}
// 			j++;
// 		}
// 		if (afterstr[j] == '\n')
// 		{
// 			j++;
// 			str = ft_substr(afterstr, 0, j);
// 			afterstr += j;
// 			beforestr = ft_strjoin(beforestr, str);
// 			break ;
// 		}
// 		beforestr = ft_strjoin(beforestr, afterstr);
// 		read(fd, afterstr, BUFFER_SIZE);
// 		j = 0;
// 	}
// 	return (beforestr);
// }

char	*get_next_line(int fd)
{
	static char	*afterstr;
	char		*str;
	int			j;
	char		*beforestr;

	beforestr = calloc(BUFFER_SIZE,1);
	str = calloc(BUFFER_SIZE,1);
	j = 0;
	if (afterstr == NULL || *afterstr)
	{
		afterstr = calloc(BUFFER_SIZE,1);
		read(fd, str, BUFFER_SIZE);
	}
	else 
	{
		str = calloc(BUFFER_SIZE,1);
		str = ft_strjoin(str, afterstr);
	}

	while (str[j])
	{
		while (str[j])
		{
			if (str[j] == '\n')
			{
				j++;
				afterstr = str + j;
				str = ft_substr(str, 0, j);
				beforestr = ft_strjoin(beforestr, str);
				return (beforestr);
			}
			j++;
		}
		if (str[j] == '\n')
		{
			j++;
			str = ft_substr(str, 0, j);
			afterstr = str + j;
			beforestr = ft_strjoin(beforestr, str);
			return (beforestr);
		}
		beforestr = ft_strjoin(beforestr, str);
		read(fd, str, BUFFER_SIZE);
		j = 0;
	}
	return (beforestr);
}

int	main(void)
{
	int	fd;

	fd = open("test.txt", O_CREAT | O_RDWR, 0777);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
}
