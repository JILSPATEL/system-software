/*
=================================================================
Name:2.c
Author:Jils Patel
Description:Write a program to print the system resource limits. 
	    Use getrlimit system call.
Date:23 September 2025
=================================================================
*/
#include <stdio.h>
#include <sys/resource.h>

int main() {
    struct rlimit limit;

    getrlimit(RLIMIT_CPU, &limit);
    printf("CPU time: soft=%llu hard=%llu\n",
           (unsigned long long)limit.rlim_cur,
           (unsigned long long)limit.rlim_max);

    getrlimit(RLIMIT_FSIZE, &limit);
    printf("File size: soft=%llu hard=%llu\n",
           (unsigned long long)limit.rlim_cur,
           (unsigned long long)limit.rlim_max);

    getrlimit(RLIMIT_STACK, &limit);
    printf("Stack size: soft=%llu hard=%llu\n",
           (unsigned long long)limit.rlim_cur,
           (unsigned long long)limit.rlim_max);

    return 0;
}
/*
===========================================================================
Output: jils@Inspiron-3593:/mnt/e/SS/hands-on-list-2$ cc 2.c
	jils@Inspiron-3593:/mnt/e/SS/hands-on-list-2$ ./a.out
	CPU time: soft=18446744073709551615 hard=18446744073709551615
	File size: soft=18446744073709551615 hard=18446744073709551615
	Stack size: soft=8388608 hard=18446744073709551615
===========================================================================
*/
