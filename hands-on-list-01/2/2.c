/*
=====================================================================================
Name:2.c
Author:Jils Patel
Description:Write a simple program to execute in an infinite loop at the background. 
            Go to /proc directory and identify all the process related information 
            in the corresponding proc directory.
Date: 07 September 2025   
=====================================================================================
*/

#include <stdio.h>   
#include <unistd.h>  
int main() {
    pid_t pid = getpid();
    printf("Process started. PID: %d\n", pid);
    while (1) {
        printf("Process %d is running\n", pid);
        sleep(2);
    }
    return 0;
}

/*
========================================================================
Output:jils@Inspiron-3593:/mnt/e/ss/hands-on-list-1/2$ gcc 2.c && ./a.out
       Process started. PID: 392
       Process 392 is running
       Process 392 is running
       Process 392 is running
       Process 392 is running
========================================================================
*/

