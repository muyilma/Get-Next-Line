#include "get_next_line.h"
#include <stdlib.h>
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

char	*get_next_line(int fd)
{
	static char	*a;
	char		*b;
	int			j;
	char		*hola;

	hola = malloc(BUFFER_SIZE);
	j = 0;
	a = malloc(BUFFER_SIZE);
	b = malloc(BUFFER_SIZE);
	read(fd, a, BUFFER_SIZE);
	while (a[j])
	{
		while (a[j] != '\n' && a[j])
		{
			if (a[j + 1] == '\n')
			{
				j ++;
				b = ft_substr(a, 0, j);
				a += j;
				hola = ft_strjoin(hola, b);
				return (hola);
			}
			j++;
		}
		if (a[j] == '\n' )
		{
			j++;
			b = ft_substr(a, 0, j);
			a += j;
			hola = ft_strjoin(hola, b);
			break ;
		}
		hola = ft_strjoin(hola, a);
		read(fd, a, BUFFER_SIZE);
		j = 0;
	}
	return (hola);
}

int	main(void)
{
	int	fd;

	fd = open("test.txt", O_CREAT | O_RDWR, 0777);
	printf("%s",get_next_line(fd));
	printf("%s", get_next_line(fd));
}


// char	*get_next_line(int fd)
// {
// 	static char	*a;
// 	int			i;
// 	int			j;
// 	char		*hola;

// 	hola = malloc(BUFFER_SIZE);
// 	i = 0;
// 	j = 0;
// 	a = malloc(BUFFER_SIZE);
// 	read(fd, a, BUFFER_SIZE);
// 	while (a[j])
// 	{
// 		while (a[j] != '\n' && a[j])
// 		{
// 			hola[i] = a[j];
// 			if (a[j] + 1 == '\n')
// 			{
// 				i++;
// 				j++;
// 				break ;
// 			}
// 			j++;
// 			i++;
// 		}
// 		if (a[j] == '\n')
// 		{
// 			i++;
// 			j++;
// 			break ;
// 		}
// 		read(fd, a, BUFFER_SIZE);
// 		j = 0;
// 	}
// 	a = a + j;
// 	printf("%s\n", a);
// 	return (hola);
// }







char	*get_next_line(int fd)
{
	static char *afterStr;

	char *beforeStr;

	char *str;

	while(*str)
	{
		while(*str)
		{
			if(str=='\n')
			{
				
			}
		}	
	}
}