/*
=======================================================================================
Name:15.c
Author:Jils Patel
Description:Write a simple program to send some data from parent to the child process.
Date:
=======================================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {
    int fd[2];
    char write_msg[] = "Hello Through pipe!";
    char read_msg[100];
    pid_t pid = fork();
    if (pid > 0) {  
        close(fd[0]); 
        write(fd[1], write_msg, strlen(write_msg) + 1);
        close(fd[1]);
    }
    else{  
        close(fd[1]); 
        read(fd[0], read_msg, sizeof(read_msg));
        printf("Child received: %s\n", read_msg);
        close(fd[0]);
    }

    return 0;
}


/*
==============================================================
Output: jils@Inspiron-3593:/mnt/e/SS/hands-on-list-2$ ./a.out
	Hello Through pipe!Child received:
	jils@Inspiron-3593:/mnt/e/SS/hands-on-list-2$
==============================================================
*/
