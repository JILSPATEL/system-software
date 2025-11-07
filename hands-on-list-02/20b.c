/*
=============================================================================
Name:20b.c
Author:Jils Patel
Description:Write two programs so that both can communicate by FIFO -Use one
            way communication.
Date:23 September 2025
=============================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

int main() {
    int fd;
    char buff[100];

    fd = open("myfifo", O_RDONLY);      

    read(fd, buff, sizeof(buff));
    printf("The text from FIFO file: %s\n", buff);

    close(fd);
    return 0;
}
/*
==================================================
Output: jils@Inspiron-3593:~$ ./reader
	The text from FIFO file: Hello FIFO World
==================================================
*/
