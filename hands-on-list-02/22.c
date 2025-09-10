/*
========================================================================================
Name:22.c
Author:Jils Patel
Description:Write a program to wait for data to be written into FIFO within 10 seconds, 
	    use select system call with FIFO.
Date:
========================================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/select.h>
#include <sys/stat.h>

int main() {
    int fd;
    char buff[100];
    fd_set rfds;
    struct timeval tv;

    tv.tv_sec = 10;
    tv.tv_usec = 0;

    mkfifo("myfifo", 0666);

    fd = open("myfifo", O_RDONLY | O_NONBLOCK);
    FD_ZERO(&rfds);
    FD_SET(fd, &rfds);

    // Wait for data
    if (select(fd + 1, &rfds, NULL, NULL, &tv) == 0) {
        printf("No data is available for reading yet\n");
    } else {
        printf("Data is available now\n");
        int n = read(fd, buff, sizeof(buff)-1);
        if (n > 0) {
            buff[n] = '\0';
            printf("Data from FIFO: %s\n", buff);
        }
    }

    close(fd);
    return 0;
}
/*
============================================================================
Output-1: jils@Inspiron-3593:~$ mkdir 22
	  jils@Inspiron-3593:~$ cd 22
	  jils@Inspiron-3593:~/22$  cc /mnt/e/SS/hands-on-list-2/22.c -o 22
	  jils@Inspiron-3593:~/22$ ./22
	  Data is available now
	  Data from FIFO: Hello FIFO
Output-2: jils@Inspiron-3593:~$ cd 22
	  jils@Inspiron-3593:~/22$ echo "Hello FIFO" > myfifo
	  jils@Inspiron-3593:~/22$
============================================================================
*/
