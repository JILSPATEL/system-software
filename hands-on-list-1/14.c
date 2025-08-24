/*
======================================================
Task:14.c
Author:Jils Patel
Write a program to find the type of a file.
Input should be taken from command line.
Program should be able to identify any type of a file.
======================================================
*/

#include <stdio.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
    struct stat st;

    if (argc != 2) {
        printf("Usage: ./task14 <filename>\n");
        return 1;
    }

    if (stat(argv[1], &st) == -1) {
        perror("stat");
        return 1;
    }

    if (S_ISREG(st.st_mode))
        printf("Regular file\n");
    else if (S_ISDIR(st.st_mode))
        printf("Directory\n");
    else if (S_ISLNK(st.st_mode))
        printf("Symbolic link\n");
    else if (S_ISCHR(st.st_mode))
        printf("Character device\n");
    else if (S_ISBLK(st.st_mode))
        printf("Block device\n");
    else if (S_ISFIFO(st.st_mode))
        printf("FIFO (named pipe)\n");
    else if (S_ISSOCK(st.st_mode))
        printf("Socket\n");
    else
        printf("Unknown file type\n");

    return 0;
}

/*
Output:
jils@Inspiron-3593:/mnt/e/SS/hands-on-list-1$ ./a.out 14.c
Regular file
jils@Inspiron-3593:/mnt/e/SS/hands-on-list-1$
*/

