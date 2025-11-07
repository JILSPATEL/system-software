/*
=========================================================================================
Name:4.c
Author:Jils Patel
Description:Write a program to measure how much time is taken to execute 100 getppid ( ) 
	    system call. Use time stamp counter.  
Date: 23 September 2025
=========================================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <stdint.h>
#include <x86intrin.h>  

int main() {
    uint64_t start, end;
    int i;

    start =_rdtsc();  
    for (i = 0; i < 100; i++) {
        getppid(); 
    }

    end =_rdtsc(); 

    printf("Total cycles for 100 getppid() calls: %llu\n",
           (unsigned long long)(end - start));

    return 0;
}
/*
===============================================================
Output: jils@Inspiron-3593:/mnt/e/SS/hands-on-list-2$ ./a.out
		Total cycles for 100 getppid() calls: 39909
===============================================================
*/