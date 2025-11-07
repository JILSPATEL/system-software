/*
===================================================================================================
Name:1.c
Author:Jils Patel
Description: Write a separate program (for each time domain) to set a interval timer in 10sec and 
	     10micro second 
       	     a. ITIMER_REAL 
             b. ITIMER_VIRTUAL 
       	     c. ITIMER_PROF
Date: 23 September 2025
===================================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/time.h>

void handler(int sig) {
    printf("ITIMER_PROF: Timer expired! (signal %d)\n", sig);
}

int main() {
    struct itimerval timer;

    signal(SIGPROF, handler);

    timer.it_value.tv_sec = 10;
    timer.it_value.tv_usec = 10;
    timer.it_interval.tv_sec = 10;
    timer.it_interval.tv_usec = 10;

    setitimer(ITIMER_PROF, &timer, NULL);

    printf("ITIMER_PROF started. Busy loop...\n");

    while (1);  
    return 0;
}
/*
==============================================================
Output: jils@Inspiron-3593:/mnt/e/SS/hands-on-list-2$ ./a.out
		ITIMER_PROF started. Busy loop...
		ITIMER_PROF: Timer expired! (signal 27)
		ITIMER_PROF: Timer expired! (signal 27)
==============================================================
*/
