/*
=========================================================================================
Name:31a.c
Author:Jils Patel
Decription:Write a program to create a semaphore and initialize value to the semaphore.
	   a. create a binary semaphore
 	   b. create a counting semaphore
Date:
=========================================================================================
*/
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/sem.h>

// union required for semctl
union semun {
    int val;
};

int main() {
    key_t key = ftok("semfile", 86);          
    int semid = semget(key, 1, 0666 | IPC_CREAT);   
    union semun arg;
    arg.val = 1;   
    semctl(semid, 0, SETVAL, arg);

    printf("Binary semaphore created with ID: %d, value = %d\n", semid, arg.val);
    return 0;
}
/*
==============================================================
Output: jils@Inspiron-3593:/mnt/e/SS/hands-on-list-2$ cc 31.c
	jils@Inspiron-3593:/mnt/e/SS/hands-on-list-2$ ./a.out
	Binary semaphore created with ID: 0, value = 1
==============================================================
*/
