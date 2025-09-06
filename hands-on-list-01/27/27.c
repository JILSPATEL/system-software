/*
============================================================================
Name:27.c
Author:Jils Patel
Description:Write a program to execute ls -Rl by the following system calls
            a. execl
            b. execlp
            c. execle
            d. execv
            e. execvp
Date: 07 September 2025
===========================================================================
*/
#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    execl("/bin/ls", "ls", "-Rl", NULL);
    execlp("ls", "ls", "-Rl", NULL);

    char *envp[] = {"PATH=/bin", NULL};
    execle("/bin/ls", "ls", "-Rl", NULL, envp);

    char *args[] = {"ls", "-Rl", NULL};
    execv("/bin/ls", args);
    execvp("ls", args);

    return 0;
}
/*
=================================================================
Output: jils@Inspiron-3593:/mnt/e/SS/hands-on-list-1/27$ cc 27.c
	jils@Inspiron-3593:/mnt/e/SS/hands-on-list-1/27$ ./a.out
	.:
	total 20
	-rwxrwxrwx 1 jils jils  1079 Sep  5 10:27 27.c
	-rwxrwxrwx 1 jils jils 16184 Sep  5 11:55 a.out
	jils@Inspiron-3593:/mnt/e/SS/hands-on-list-1/27$
==================================================================
*/
