/*
======================================================================
Name:21b.c
Author:Jils Patel
Description: Write two programs so that both can communicate by FIFO
             -Use two way communications.
Date:23 September 2025
======================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

int main() {
    int fd1, fd2;
    char buff[100];

    fd1 = open("fifo1", O_RDONLY);
    read(fd1, buff, sizeof(buff));
    printf("Child received: %s\n", buff);
    close(fd1);

    fd2 = open("fifo2", O_WRONLY);
    printf("Child: Enter reply to parent: ");
    scanf(" %[^\n]", buff);
    write(fd2, buff, sizeof(buff));
    close(fd2);

    return 0;
}
/*
=======================================================
Output: jils@Inspiron-3593:~$ ./21b
	Child received: Hello from parent
	Child: Enter reply to parent: Hello from child
=======================================================
*/
