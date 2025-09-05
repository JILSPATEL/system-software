/* 
===================================================================
Name:8.c
Author:Jils Patel
Description:Write a program to open a file in read only mode, 
            read line by line and display each line as it is read.
            Close the file when end of file is reached. 
Date: 07 September 2025 
====================================================================
*/

#include <fcntl.h>  
#include <unistd.h> 

int main(int argc, char *argv[]) {
    int fd;
    char c;

    if (argc != 2) {
        write(1, "this is linux\n",13);
        return 1;
    }

    fd = open(argv[1], O_RDONLY);
    if (fd == -1) return 1;

    while (read(fd, &c, 1) > 0) {
        write(1, &c, 1); 
        if (c == '\n') { 
            
        }
    }

    close(fd);
    return 0;
}

/*
===============================================================
Output: jils@Inspiron-3593:/mnt/e/SS/hands-on-list-1/8$ ./a.out
        this is linux
===============================================================
*/