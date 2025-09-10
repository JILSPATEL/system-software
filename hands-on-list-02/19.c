/*
=============================================================================================
Name:19.c
Author:Jils Patel
Description:Create a FIFO file by
            a. mknod command
            b. mkfifo command
            c. use strace command to find out, which command (mknod or mkfifo) is better.
            d. mknod system call
            e. mkfifo library function
Date:
==============================================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

int main() {
    int ret;

    // Using system() with mknod command
    ret = system("mknod fifo_mknod_cmd p");
    if (ret == 0) 
        printf("FIFO created using mknod command.\n");
    else 
        printf("Error creating FIFO using mknod command.\n");

    // Using system() with mkfifo command
    ret = system("mkfifo fifo_mkfifo_cmd");
    if (ret == 0) 
        printf("FIFO created using mkfifo command.\n");
    else 
        printf("Error creating FIFO using mkfifo command.\n");

    // Using mknod() system call
    ret = mknod("fifo_mknod_syscall", S_IFIFO | 0666, 0);
    if (ret == 0)
        printf("FIFO created using mknod system call.\n");
    else
        perror("mknod system call");

    // Using mkfifo() library function
    ret = mkfifo("fifo_mkfifo_lib", 0666);
    if (ret == 0)
        printf("FIFO created using mkfifo library function.\n");
    else
        perror("mkfifo library function");

    return 0;
}
/*
==========================================================================
Output: jils@Inspiron-3593:~$ sudo mkdir 19
        [sudo] password for jils:
        jils@Inspiron-3593:~$ cd 19
        jils@Inspiron-3593:~/19$ cc /mnt/e/SS/hands-on-list-2/19.c -o 19
        jils@Inspiron-3593:~/19$ ./19
        FIFO created using mknod command.
        FIFO created using mkfifo command.
        FIFO created using mknod system call.
        FIFO created using mkfifo library function.
        jils@Inspiron-3593:~/19$ ls -l fifo_*
        prw-r--r-- 1 jils jils 0 Sep  7 17:18 fifo_mkfifo_cmd
        prw-r--r-- 1 jils jils 0 Sep  7 17:18 fifo_mkfifo_lib
        prw-r--r-- 1 jils jils 0 Sep  7 17:18 fifo_mknod_cmd
        prw-r--r-- 1 jils jils 0 Sep  7 17:18 fifo_mknod_syscall
        jils@Inspiron-3593:~/19$
===========================================================================
*/
