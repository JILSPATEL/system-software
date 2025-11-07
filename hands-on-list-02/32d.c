/*
==========================================================================================
Name:32d.c
Author:Jils Patel
Description:Write a program to implement semaphore to protect any critical section.
            a. rewrite the ticket number creation program using semaphore
            b. protect shared memory from concurrent write access
            c. protect multiple pseudo resources ( may be two) using counting semaphore
            d. remove the created semaphore
Date:23 September 2025
==========================================================================================
*/
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/types.h>
#include <stdio.h>
#include <sys/shm.h>
#include <unistd.h>
void main()
{
    key_t shaKey = ftok(".", 666);
    int shmid = shmget(shaKey, 1024, IPC_CREAT | 0744);
    char *shmPointer;
    shmPointer = shmat(shmid, (void *)0, 0);
    key_t semKey;
    int semIdentifier;
    int semctlStatus;
    int semopStatus;

    union semun
    {
        int val;               
        struct semid_ds *buf;  
        unsigned short *array; 
        struct seminfo *__buf; 
    } semSet;

    semKey = ftok(".", 335);

    semIdentifier = semget(semKey, 1, 0); 
    if (semIdentifier == -1)
    {
        semIdentifier = semget(semKey, 1, IPC_CREAT | 0700);

        semSet.val = 1; 
        semctlStatus = semctl(semIdentifier, 0, SETVAL, semSet);
    }

    struct sembuf semOp; 
    semOp.sem_num = 0;
    semOp.sem_flg = 0;

    printf("entering to obtain lock on the critical section\n");

    semOp.sem_op = -1;
    semopStatus = semop(semIdentifier, &semOp, 1);

    printf("Obtained lock on critical section!\n");
    printf("Now entering critical section!\n");

    printf("write in shared memory\n");
    scanf("%[^\n]", shmPointer);
    printf("data from shared memory : %s\n", shmPointer);
    printf("entering to exit from critical section!\n");

    semOp.sem_op = 1;
    semopStatus = semop(semIdentifier, &semOp, 1);

    printf("deleting binary semaphore");
    semctlStatus = semctl(semIdentifier, 0, IPC_RMID);
}


/*
==============================================================
Output: jils@Inspiron-3593:/mnt/e/SS/hands-on-list-2$ ./a.out
        entering to obtain lock on the critical section
        Obtained lock on critical section!
        Now entering critical section!
        write in shared memory
        Jils
        data from shared memory : Jils
        entering to exit from critical section!
        deleting binary semaphore
==============================================================
*/
