#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// int main(void)
// {
// 	char str[] ="mustafa";
// 	str[2]='q';
// 	(int [1]){180};
// 	int str2[3] = {'B', 'B', 'B'};
// 	str2[2]='q';
// }

#include <stdio.h>
int main(void)
{
    char *str;
    int fd;
    fd = open("test2.txt", O_CREAT | O_RDWR, 0777);

    str = get_next_line(fd);
    printf("%s", str);
    free(str);
}