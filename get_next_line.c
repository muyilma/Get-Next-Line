#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char	*get_next_line(int fd)
{
	static char	*a;
	int			i;
	char		*hola;
    hola=malloc(5);

	i = 0;
	a = malloc(5);
	read(fd, a, 5);
	while (*a)
	{
		while (*a != '\n' && *a)
		{
			hola[i] = *a;
			if (*a + 1 == '\n')
			{
				a++;
				break ;
			}
			i++;
			a++;
		}
		if (*a == '\n')
		{
			a++;
			break ;
		}
		read(fd, a, 5);
	}
	return (hola);
}

int	main(void)
{
	int		fd;

	fd = open("test.txt", O_CREAT | O_RDWR, 0777);
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));

}
