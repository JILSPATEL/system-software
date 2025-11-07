/*
=================================================================================================
Name:8d.c
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
    printf("Caught SIGALRM from alarm()! Signal number = %d\n", sig);
    exit(0);
}

int main() {
    signal(SIGALRM, handler);

    printf("Alarm in 5 seconds...\n");
    alarm(5); 
    while(1) pause();  
    return 0;
}
/*
==============================================================
Output: jils@Inspiron-3593:/mnt/e/SS/hands-on-list-2$ ./a.out
        Alarm in 5 seconds...
        Caught SIGALRM from alarm()! Signal number = 14
==============================================================
*/