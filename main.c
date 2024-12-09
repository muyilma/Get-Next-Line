#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	main(void)
{
	int	fd;
    char *a;
	fd = open("test.txt", O_CREAT | O_RDWR, 0777);
	a=malloc(BUFFER_SIZE);

    read(fd,a,BUFFER_SIZE);
    read(fd,a,BUFFER_SIZE);
    read(fd,a,BUFFER_SIZE);

    printf("%s",a);
}