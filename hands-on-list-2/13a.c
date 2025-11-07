/*
================================================================================================================
Name:13a.c
Author:Jils Patel
Description:Write two programs: first program is waiting to catch SIGSTOP signal, the second program
            will send the signal (using kill system call). Find out whether the first program is able to catch
            the signal or not.
Date:23 September 2025
================================================================================================================
*/

#include <signal.h> 
#include <unistd.h> 
#include <stdio.h>  
#include <stdlib.h> 

void customHandler()
{
    printf("Received SIGSTOP signal!\n");
    _exit(0);
}

void main()
{
    __sighandler_t signalStatus; 
    pid_t pid = getpid();

    printf("Process ID: %d\n", pid);

    signalStatus = signal(SIGSTOP, customHandler);
    if (signalStatus == SIG_ERR)
        perror("Error while catching signal!");

    printf("Putting the process to sleep for 15s\n");
    sleep(15);
}
/*
==============================================================
Output: jils@Inspiron-3593:/mnt/e/SS/hands-on-list-2$ ./a.out
        Process ID: 487
        Error while catching signal!: Invalid argument
        Putting the process to sleep for 15s

        [1]+  Stopped                 ./a.out
==============================================================
*/