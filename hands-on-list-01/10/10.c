/*
====================================================================================
Name:10.c
Author:Jils Patel
Description:Write a program to open a file with read write mode, write 10 bytes, 
            move the file pointer by 10 bytes (use lseek) and write again 10 bytes.
            a. check the return value of lseek
            b. open the file with od and check the empty spaces in between the data.
Date: 07 September 2025
====================================================================================
*/
#include <fcntl.h>   
#include <unistd.h>  
#include <stdio.h>   

int main() {
    int fd;

    fd = open("test10.txt", O_RDWR | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        perror("open failed");
        return 1;
    }

    write(fd, "ABCDEFGHIJ", 10);       
    lseek(fd, 10, SEEK_CUR);          
    write(fd, "1234567890", 10);      

    close(fd);
    return 0;
}
/*
===================================================================================
Output: jils@Inspiron-3593:/mnt/e/SS/hands-on-list-1/10$ cc 10.c
        jils@Inspiron-3593:/mnt/e/SS/hands-on-list-1/10$ ./a.out
        jils@Inspiron-3593:/mnt/e/SS/hands-on-list-1/10$ od -c test10.txt
        0000000   A   B   C   D   E   F   G   H   I   J  \0  \0  \0  \0  \0  \0
        0000020  \0  \0  \0  \0   1   2   3   4   5   6   7   8   9   0
        0000036
===================================================================================
*/

