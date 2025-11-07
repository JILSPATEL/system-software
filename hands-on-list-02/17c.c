/*
===================================================
Name:17c.c
Author:Jils Patel
Description:Write a program to execute ls -l | wc.
            a. use dup
            b. use dup2
            c. use fcntl
Date: 23 September 2025
===================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int main() {
    int fd[2];
    pipe(fd);

    if (fork() == 0) {
        // Child: ls -l
        close(1);                       
        fcntl(fd[1], F_DUPFD, 1);       
        close(fd[0]);
        close(fd[1]);
        execlp("ls", "ls", "-l", (char *)NULL);
        perror("execlp ls");
        exit(1);
    } else {
        // Parent: wc
        close(0);                      
        fcntl(fd[0], F_DUPFD, 0);       
        close(fd[1]);
        close(fd[0]);
        execlp("wc", "wc", (char *)NULL);
        perror("execlp wc");
        exit(1);
    }
}
/*
==============================================================
Output: jils@Inspiron-3593:/mnt/e/SS/hands-on-list-2$ ./a.out
      8      65     342
==============================================================
*/
