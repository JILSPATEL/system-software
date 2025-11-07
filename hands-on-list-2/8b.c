/*
=================================================================================================
Name:8b.c
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
#include <unistd.h>

void handler(int sig) {
    printf("Caught SIGINT! Signal number = %d\n", sig);
    exit(0);
}

int main() {
    signal(SIGINT, handler);  

    printf("Press Ctrl+C to trigger SIGINT\n");
    while(1) sleep(1);  
    return 0;
}
/*
==============================================================
Output: jils@Inspiron-3593:/mnt/e/SS/hands-on-list-2$ ./a.out
        Press Ctrl+C to trigger SIGINT
        ^CCaught SIGINT! Signal number = 2
==============================================================
*/
