/* 
========================================================================
Name:7.c
Author:Jils Patel
Description:Write a program to copy file1 into file2 ($cp file1 file2).
Date: 07 September 2025  
========================================================================
*/

#include <fcntl.h>   
#include <stdio.h>
#include <unistd.h>  

#define BUF_SIZE 1024

int main() {
    int fd_src = open("file1.txt", O_RDONLY);
    int fd_dest = open("file2.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    
    char buffer[BUF_SIZE];
    int bytesRead;

    while ((bytesRead = read(fd_src, buffer, BUF_SIZE)) > 0) {
        write(fd_dest, buffer, bytesRead);
    }

    printf("Copy Successfully\n");

    close(fd_src);
    close(fd_dest);
    return 0;
}

/*
=================================================================
Output: jils@Inspiron-3593:/mnt/e/SS/hands-on-list-1/7$ cc 7.c
        jils@Inspiron-3593:/mnt/e/SS/hands-on-list-1/7$ ./a.out
        Copy Successfully
=================================================================
*/
