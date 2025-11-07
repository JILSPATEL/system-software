/*
=================================================================================================
Name:8c.c
Author:Jils Patel
Description: Write a separate program using signal system call to catch the following signals. 
            a. SIGSEGV 
            b. SIGINT 
            c. SIGFPE 
            d. SIGALRM (use alarm system call) 
            e. SIGALRM (use setitimer system call) 
            f. SIGVTALRM (use setitimer system call) 
            g. SIGPROF (use setitimer system call)
Date:23 September 2025
=================================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void handler(int sig) {
    printf("Caught SIGFPE! Signal number = %d\n", sig);
    exit(1);
}

int main() {
    signal(SIGFPE, handler);  

    int a = 5, b = 0;
    int c = a / b; 
    printf("%d\n", c);

    return 0;
}
/*
==============================================================
Output: jils@Inspiron-3593:/mnt/e/SS/hands-on-list-2$ ./a.out
        Caught SIGFPE! Signal number = 8
==============================================================
*/