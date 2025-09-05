/* 
==========================================================================
Name:4.c
Author:Jils Patel
Description:Write a program to open an existing file with read write mode. 
	    Try O_EXCL flag also. 
Date: 07 September 2025
==========================================================================
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd;

    fd = open("txtFile4.txt", O_RDWR | O_CREAT, 0644);
    if (fd == -1) {
        perror("open txtFile4.txt failed");
    } else {
        printf("file created/opened. FD: %d\n", fd);
        close(fd);
    }

    fd = open("txtFile.txt", O_CREAT | O_EXCL | O_RDWR, 0644);
    if (fd == -1) {
        perror("O_EXCL failed");
    } else {
        printf("O_EXCL succeeded. FD = %d\n", fd);
        close(fd);
    }
    return 0;
}

/*
=========================================================================
Output: jils@Inspiron-3593:/mnt/e/ss/hands-on-list-1$ gcc 4.c && ./a.out
	file created/opened. FD: 3
	O_EXCL succeeded. FD = 3
	jils@Inspiron-3593:/mnt/e/ss/hands-on-list-1$
=========================================================================
*/
