/*
=================================================================================================
Name:10a.c
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
#include <string.h>

void handler(int sig) {
    printf("Caught SIGSEGV! Signal number = %d\n", sig);
    exit(1);
}

int main() {
    struct sigaction sa;
    sa.sa_handler = handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;

    sigaction(SIGSEGV, &sa, NULL);  

    int *p = NULL;
    *p = 42;  

    return 0;
}


/*
==============================================================
Output: jils@Inspiron-3593:/mnt/e/SS/hands-on-list-2$ ./a.out
		Caught SIGSEGV! Signal number = 11
==============================================================
*/
