/*
=================================================================================================
Name:10b.c
Author:Jils Patel
Description:Write a separate program using sigaction system call to catch the following signals. 
   	    a. SIGSEGV 
   	    b. SIGINT 
	    c. SIGFPE 
Date: 23 September 2025
=================================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>

void handler(int sig) {
    printf("Caught SIGINT! Signal number = %d\n", sig);
    exit(0);
}

int main() {
    struct sigaction sa;
    sa.sa_handler = handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;

    sigaction(SIGINT, &sa, NULL); 

    printf("Press Ctrl+C to trigger SIGINT\n");
    while(1) sleep(1); 
    return 0;
}


/*
=================================================================
Output: jils@Inspiron-3593:/mnt/e/SS/hands-on-list-2$ ./a.out
		Press Ctrl+C to trigger SIGINT
		^CCaught SIGINT! Signal number = 2
=================================================================
*/
