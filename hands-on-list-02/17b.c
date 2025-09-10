/*
======================================================
Name:17b.c
Author:Jils Patel
Description:Write a program to execute ls -l | wc.
 	    a. use dup
 	    b. use dup2
 	    c. use fcntl
Date: 
======================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    int fd[2];
    pipe(fd);

    if (fork() == 0) {
        // Child: ls -l
        dup2(fd[1], 1); 
        close(fd[0]);     
        close(fd[1]);
        execlp("ls", "ls", "-l", (char *)NULL);
        perror("execlp ls");
        exit(1);
    } else {
        // Parent: wc
        dup2(fd[0], 0);  
        close(fd[1]);
        close(fd[0]);
        execlp("wc", "wc", (char *)NULL);
        perror("execlp wc");
        exit(1);
    }
}
/*
===============================================================
Output: jils@Inspiron-3593:/mnt/e/SS/hands-on-list-2$ cc 17b.c
	jils@Inspiron-3593:/mnt/e/SS/hands-on-list-2$ ./a.out
      	8      65     342 
===============================================================
*/
