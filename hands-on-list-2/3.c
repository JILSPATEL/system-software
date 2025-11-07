/*
====================================================================
Name:3.c
Author:Jils Patel
Description:Write a program to set (any one) system resource limit. 
	    Use setrlimit system call.
Date: 23 September 2025
====================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <unistd.h>

int main() {
    struct rlimit limit;

    if (getrlimit(RLIMIT_CORE, &limit) == -1) {
        perror("getrlimit");
        exit(1);
    }

    printf("Current core file size limit: soft = %ld, hard = %ld\n",
           (long)limit.rlim_cur, (long)limit.rlim_max);

    limit.rlim_cur = 1024;   
    limit.rlim_max = 2048;   

    if (setrlimit(RLIMIT_CORE, &limit) == -1) {
        perror("setrlimit");
        exit(1);
    }

    printf("New core file size limit set: soft = %ld, hard = %ld\n",
           (long)limit.rlim_cur, (long)limit.rlim_max);

 
    printf("Aborting the program to generate core file...\n");
    abort();  

    return 0;
}
/*
===============================================================
Output: jils@Inspiron-3593:/mnt/e/SS/hands-on-list-2$ ./a.out
	Current core file size limit: soft = 0, hard = -1
	New core file size limit set: soft = 1024, hard = 2048
	Aborting the program to generate core file...
	Aborted (core dumped)
===============================================================
*/
