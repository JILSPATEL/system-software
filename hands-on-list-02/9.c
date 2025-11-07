/*
==================================================================================================
Name:9.c
Author:Jils Patel
Description:Write a program to ignore a SIGINT signal then reset the default action of the SIGINT
	    signal - Use signal system call.
Date:23 September 2025
==================================================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void my_handler(int sig) {
    printf("I got SIGINT number %d\n", sig);
    exit(0); 
}

int main(void) {
    signal(SIGINT, my_handler);
    printf("Catching SIGINT\n");
    sleep(10);
    printf("No SIGINT within 10 seconds\n\n");

    signal(SIGINT, SIG_IGN);  
    printf("Ignoring SIGINT\n");
    sleep(10);
    printf("No SIGINT within 10 seconds\n\n");

    signal(SIGINT, SIG_DFL);
    printf("Default action for SIGINT\n");
    sleep(10);
    printf("No SIGINT within 10 seconds\n\n");

    return 0;
}
/*
==============================================================
Output: jils@Inspiron-3593:/mnt/e/SS/hands-on-list-2$ ./a.out
	Catching SIGINT
	No SIGINT within 10 seconds

	Ignoring SIGINT
	^C^C^C^C^C^C^C^C
	No SIGINT within 10 seconds

	Default action for SIGINT
	^C
===============================================================
*/
