#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	main(void)
{
	int	fd;
    char a[7]="mustafa";
	fd = open("test.txt", O_CREAT | O_RDWR, 0777);

    read(fd,a,2);


    printf("%s",a);
}
int	main(void)
{
	int	fd;
	fd = open("test.txt", O_CREAT | O_RDWR, 0777);
	
   
	
     printf("%s",get_next_line(fd));
    // printf("%s",get_next_line(fd));
    // printf("%s",get_next_line(fd));
    // printf("%s",get_next_line(fd));
    // printf("%s",get_next_line(fd));
    // printf("%s",get_next_line(fd));

}