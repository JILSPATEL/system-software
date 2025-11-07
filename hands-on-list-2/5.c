/*
================================================================================
Name: 5.c
Author:Jils Patel
Description:Write a program to print the system limitation of  
            a. maximum length of the arguments to the exec family of functions.  
            b. maximum number of simultaneous process per user id.  
            c. number of clock ticks (jiffy) per second.  
            d. maximum number of open files 
            e. size of a page 
            f. total number of pages in the physical memory 
            g. number of currently available pages in the physical memory. 
Date: 23 September 2025
=================================================================================
*/
/*
===============================================================================
Name   : system_limits.c
Author : Jils Patel
Desc   : Print various system limitations using sysconf()
===============================================================================
*/

#include <stdio.h>
#include <unistd.h>

int main() {
    long val;

    val = sysconf(_SC_ARG_MAX);
    printf("a) Max length of arguments to exec()        : %ld\n", val);

    val = sysconf(_SC_CHILD_MAX);
    printf("b) Max simultaneous processes per user ID   : %ld\n", val);

    val = sysconf(_SC_CLK_TCK);
    printf("c) Number of clock ticks (jiffy) per second : %ld\n", val);

    val = sysconf(_SC_OPEN_MAX);
    printf("d) Max number of open files                 : %ld\n", val);

    val = sysconf(_SC_PAGESIZE);
    printf("e) Size of a page                           : %ld bytes\n", val);

    val = sysconf(_SC_PHYS_PAGES);
    printf("f) Total number of pages in physical memory : %ld\n", val);

    val = sysconf(_SC_AVPHYS_PAGES);
    printf("g) Currently available pages in memory      : %ld\n", val);

    return 0;
}
/*
==================================================================
Output: jils@Inspiron-3593:/mnt/e/SS/hands-on-list-2$ ./a.out
        a) Max length of arguments to exec()        : 2097152
        b) Max simultaneous processes per user ID   : 15153
        c) Number of clock ticks (jiffy) per second : 100
        d) Max number of open files                 : 10240
        e) Size of a page                           : 4096 bytes
        f) Total number of pages in physical memory : 972344
        g) Currently available pages in memory      : 836541
===================================================================
*/
