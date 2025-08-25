/*
======================================================================================
Task:22.c
Author:Jils Patel
Write a program, open a file, call fork, and then write to the file by both the child
as well as the parent processes. Check output of the file.
======================================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

int main() {
    int fd;
    pid_t pid;

    fd = open("output22.txt", O_CREAT | O_WRONLY | O_APPEND, 0644);
    if (fd < 0) {
        perror("open");
        exit(1);
    }

    pid = fork();

    if (pid < 0) {
        perror("fork");
        exit(1);
    }

    if (pid == 0) {
        char child_msg[] = "Message from Child process\n";
        write(fd, child_msg, sizeof(child_msg) - 1);
        printf("Child (PID=%d) wrote to file.\n", getpid());
    } 
    else {
        
        char parent_msg[] = "Message from Parent process\n";
        write(fd, parent_msg, sizeof(parent_msg) - 1);
        printf("Parent (PID=%d) wrote to file.\n", getpid());
    }

    close(fd);
    return 0;
}

/*
Output:
jils@Inspiron-3593:/mnt/e/ss/hands-on-list-1$ ./a.out
Parent (PID=425) wrote to file.
Child (PID=426) wrote to file.
jils@Inspiron-3593:/mnt/e/ss/hands-on-list-1$
*/
