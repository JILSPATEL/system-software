/*
=================================================================================================
Name:8e.c
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
#include <sys/time.h>
#include <unistd.h>

void handler(int sig) {
    printf("Caught SIGALRM from setitimer()! Signal number = %d\n", sig);
    exit(0);
}

int main() {
  
    signal(SIGALRM, handler);

    struct itimerval timer;
    timer.it_value.tv_sec = 5;      
    timer.it_value.tv_usec = 0;
    timer.it_interval.tv_sec = 0;   
    timer.it_interval.tv_usec = 0;

    setitimer(ITIMER_REAL, &timer, NULL);

    while(1) pause();
    return 0;
}
/*
==============================================================
Output: jils@Inspiron-3593:/mnt/e/SS/hands-on-list-2$ ./a.out
        Caught SIGALRM from setitimer()! Signal number = 14
==============================================================
*/

