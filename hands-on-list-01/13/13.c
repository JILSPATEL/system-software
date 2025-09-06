/*
===========================================================================
Name:13.c
Author:Jils Patel
Description:Write a program to wait for STDIN for 10 seconds using select. 
            Print whether data is available within 10 seconds or not.
Date: 07 September 2025
===========================================================================
*/


#include <stdio.h>
#include <unistd.h>
#include <sys/select.h>

int main(){
    fd_set set;
    struct timeval timeout = {10, 0}; 

    FD_ZERO(&set);
    FD_SET(0, &set); 

    printf("Enter input within 10 seconds:\n");

    if (select(1, &set, NULL, NULL, &timeout) > 0) {
        char buf[100];
        read(0, buf, sizeof(buf));
        printf("You typed: %s", buf);
    } else {
        printf("No input in 10 seconds\n");
    }
    return 0;
}

/*
=============================================================================
Output: jils@Inspiron-3593:/mnt/e/ss/hands-on-list-1/13$ gcc 13.c && ./a.out
        Enter input within 10 seconds:
        hello
        You typed: hello
        jils@Inspiron-3593:/mnt/e/ss/hands-on-list-1/13$ gcc 13.c && ./a.out
        Enter input within 10 seconds:
        No input in 10 seconds
=============================================================================
*/
