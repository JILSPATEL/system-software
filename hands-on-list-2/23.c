/*
================================================================================================
Name:23.c
Author:Jils Patel
Description:Write a program to print the maximum number of files can be opened within a process 
	    and size of a pipe (circular buffer).
Date:23 September 2025
================================================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <limits.h>

#ifndef F_GETPIPE_SZ
#define F_GETPIPE_SZ 1032   
#endif

int main() {
    long open_max = sysconf(_SC_OPEN_MAX);
    printf("Maximum open files per process: %ld\n", open_max);

    int fd[2];
    pipe(fd);

    int pipe_size = fcntl(fd[0], F_GETPIPE_SZ);
    printf("Pipe buffer size: %d bytes\n", pipe_size);

    close(fd[0]);
    close(fd[1]);
    return 0;
}

/*
==============================================================
Output: jils@Inspiron-3593:/mnt/e/SS/hands-on-list-2$ cc 23.c
		jils@Inspiron-3593:/mnt/e/SS/hands-on-list-2$ ./a.out
		Maximum open files per process: 10240
		Pipe buffer size: 65536 bytes
		jils@Inspiron-3593:/mnt/e/SS/hands-on-list-2$
==============================================================
*/

