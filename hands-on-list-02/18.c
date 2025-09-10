/*
===============================================================================
Name:18.c
Author:Jils Patel
Description:Write a program to find out total number of directories on the pwd.
 	    execute ls -l | grep ^d | wc ? Use only d
Date:
===============================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    int fd1[2], fd2[2];
    // First child: "ls -l"
    if (fork() == 0) {
        dup2(fd1[1], STDOUT_FILENO);  
        close(fd1[0]);
        close(fd1[1]);
        close(fd2[0]);
        close(fd2[1]);
        execlp("ls", "ls", "-l", (char*)NULL);
        perror("execlp ls");
        exit(1);
    }

    // Second child: "grep ^d"
    if (fork() == 0) {
        dup2(fd1[0], STDIN_FILENO);   
        dup2(fd2[1], STDOUT_FILENO);  
        close(fd1[0]);
        close(fd1[1]);
        close(fd2[0]);
        close(fd2[1]);
        execlp("grep", "grep", "^d", (char*)NULL);
        perror("execlp grep");
        exit(1);
    }

    // Parent: "wc -l"
    dup2(fd2[0], STDIN_FILENO);        
    close(fd1[0]);
    close(fd1[1]);
    close(fd2[0]);
    close(fd2[1]);
    execlp("wc", "wc", "-l", (char*)NULL);  
    perror("execlp wc");
    exit(1);
}
/*
==============================================================
Output: jils@Inspiron-3593:/mnt/e/SS/hands-on-list-2$ cc 18.c
        jils@Inspiron-3593:/mnt/e/SS/hands-on-list-2$ ./a.out
        total 60
        -rwxrwxrwx 1 jils jils   862 Sep  6 16:30 14.c
        -rwxrwxrwx 1 jils jils  1071 Sep  6 16:33 15.c
        -rwxrwxrwx 1 jils jils  1518 Sep  6 17:00 16.c
        -rwxrwxrwx 1 jils jils  1013 Sep  7 15:55 17a.c
        -rwxrwxrwx 1 jils jils  1054 Sep  7 15:57 17b.c
        -rwxrwxrwx 1 jils jils  1114 Sep  7 16:00 17c.c
        -rwxrwxrwx 1 jils jils 16168 Sep  7 16:04 18
        -rwxrwxrwx 1 jils jils  1277 Sep  7 16:07 18.c
        -rwxrwxrwx 1 jils jils 16168 Sep  7 16:07 a.out
===============================================================
*/

