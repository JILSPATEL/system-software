/*
======================================================================
Name:21a.c
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

    fd1 = open("fifo1", O_WRONLY);
    printf("Parent: Enter data to child: ");
    scanf("%[^\n]", buff);
    write(fd1, buff, sizeof(buff));
    close(fd1);

    fd2 = open("fifo2", O_RDONLY);
    read(fd2, buff, sizeof(buff));
    printf("Parent received from child: %s\n", buff);
    close(fd2);

    return 0;
}
/*
=========================================================
Output: jils@Inspiron-3593:~$ mkfifo fifo1 fifo2
	jils@Inspiron-3593:~$ ls -l fifo*
	prw------- 1 jils jils 0 Sep  7 23:10 fifo1
	prw------- 1 jils jils 0 Sep  7 23:10 fifo2

	jils@Inspiron-3593:~$ ./21a
	Parent: Enter data to child: Hello from parent
	Parent received from child: Hello from child
==========================================================
*/
