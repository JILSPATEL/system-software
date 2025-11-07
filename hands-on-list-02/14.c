/*
===========================================================
Name:14.c
Author:Jils Patel
Description:Write a simple program to create a pipe, write to the pipe,
			read from pipe and display on the monitor.
Date:23 September 2025
===========================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int fd[2];
    pid_t pid;
    char write_msg[] = "Hello from parent!";
    char read_msg[100];

    if (pipe(fd) == -1) {
        perror("pipe");
        return 1;
    }

    pid = fork();

    if (pid < 0) {
        perror("fork");
        return 1;
    }

    if (pid > 0) {
        // Parent process
        close(fd[0]); // close read end
        write(fd[1], write_msg, strlen(write_msg) + 1);
        close(fd[1]);
    } else {
        // Child process
        close(fd[1]); // close write end
        read(fd[0], read_msg, sizeof(read_msg));
        printf("Child received: %s\n", read_msg);
        close(fd[0]);
    }

    return 0;
}


/*
=============================================================
Output:	jils@Inspiron-3593:/mnt/e/ss/hands-on-list-2$ ./a.out
		Child received: Hello from parent!
		jils@Inspiron-3593:/mnt/e/ss/hands-on-list-2$
=============================================================
*/
