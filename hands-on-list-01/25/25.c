/*
==========================================================================
Name:25.c
Author:Jils Patel
Description:Write a program to create three child processes. The parent
            should wait for a particular child (use waitpid system call).
Date: 07 September 2025
==========================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    pid_t cpid[3];  
    for (int i = 0; i < 3; i++) {
        cpid[i] = fork();
        if (cpid[i] == 0) {
            printf("Child %d (PID: %d) created\n", i + 1, getpid());
            sleep(2); 
            exit(0);  
        }
    }

    
    printf("Parent PID: %d waiting for Child 2 (PID: %d)\n", getpid(), cpid[1]);

    int status;
    pid_t wpid = waitpid(cpid[1], &status, 0);

    if (WIFEXITED(status)) {
        printf("Child 2 (PID: %d) exited with status %d\n", wpid, WEXITSTATUS(status));
    }

    return 0;
}

/*
=================================================================
Output: jils@Inspiron-3593:/mnt/e/SS/hands-on-list-1$ cc 25.c
        jils@Inspiron-3593:/mnt/e/SS/hands-on-list-1$ ./a.out
        Child 1 (PID: 390) created
        Child 2 (PID: 391) created
        Parent PID: 389 waiting for Child 2 (PID: 391)
        Child 3 (PID: 392) created
        Child 2 (PID: 391) exited with status 0
        jils@Inspiron-3593:/mnt/e/SS/hands-on-list-1$
=================================================================
*/
