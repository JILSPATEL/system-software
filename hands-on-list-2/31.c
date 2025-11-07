/*
=========================================================================================
Name:31.c
Author:Jils Patel
Decription:Write a program to create a semaphore and initialize value to the semaphore.
            a. create a binary semaphore
            b. create a counting semaphore
Date:23 September 2025
=========================================================================================
*/
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdio.h>
typedef union semun
{
    int val;                   
    struct semid_ds *buf;     
    unsigned short int *array; 
} semun;

int main()
{

    semun arg;
    key_t key = ftok(".", 3);
    int semid = semget(key, 1, IPC_CREAT | 0744);
    arg.val = 1; 
    printf("binary semaphore created size is :%d \n",arg.val);
    semctl(semid, 0, SETVAL, arg); 

    semun args;
    key = ftok(".", 4);
    semid = semget(key, 1, IPC_CREAT | 0744);
    args.val = 10; 
    printf("counting semaphore created size is :%d \n", args.val);
    semctl(semid, 1, SETVAL, args); 

    return 0;
}

/*
==============================================================
Output: jils@Inspiron-3593:/mnt/e/SS/hands-on-list-2$ ./a.out
        binary semaphore created size is :1
        counting semaphore created size is :10
==============================================================
*/
