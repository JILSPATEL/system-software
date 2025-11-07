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
#include <sys/types.h> 
#include <signal.h>    
#include <unistd.h>    
#include <stdio.h>     
#include <stdlib.h> 

void main(int argc, char *argv[])
{
    int killStatus; 
    pid_t pid;

    if (argc != 2)
    {
        printf("Pass the PID of the process to whom the SIGSTOP signal is to be sent!\n");
        _exit(0);
    }

    pid = atoi(argv[1]);

    killStatus = kill(pid, SIGSTOP);

    if(!killStatus) 
        printf("Successfully sent SIGSTOP signal to process (%d)\n", pid);
    else 
        perror("Error while sending signal!");
}
/*
==================================================================
Output: jils@Inspiron-3593:/mnt/e/SS/hands-on-list-2$ ./a.out 487
        Successfully sent SIGSTOP signal to process (487)
==================================================================
*/