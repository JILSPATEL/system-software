/*
=============================================================================================================
Name:11.c
Author:Jils Patel
Description:Write a program to ignore a SIGINT signal then reset the default action of the SIGINT signal -
            use sigaction system call.
Date:23 September 2025
=============================================================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/time.h>
void main()
{
    int status;

    printf("ignoring the SIGINT signal for 5 seconds\n");
    struct sigaction act;

    act.sa_handler = SIG_IGN; 
    act.sa_flags = 0;
    status = sigaction(SIGINT, &act,NULL);
    sleep(5);

    printf("reseting the default action of the SIGINT signal\n");
    struct sigaction actdefault;

    actdefault.sa_handler = SIG_DFL; 
    actdefault.sa_flags = 0;
    status = sigaction(SIGINT, &actdefault,NULL);
    sleep(5);
}

/*
===============================================================
Output: jils@Inspiron-3593:/mnt/e/SS/hands-on-list-2$ ./a.out
        ignoring the SIGINT signal for 5 seconds
        reseting the default action of the SIGINT signal
===============================================================
*/