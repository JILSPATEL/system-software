/*
=================================================================================
Name:30b.c
Author:Jils Patel
Description:Write a program to create a shared memory.
            a. write some data to the shared memory
            b. attach with O_RDONLY and check whether you are able to overwrite.
            c. detach the shared memory
            d. remove the shared memory
Date:23 September 2025
=================================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#define SHM_SIZE 1024

int main(){
    key_t key = ftok("shmfile", 86);
    int shmid = shmget(key, SHM_SIZE, 0666);
 
    char *data = (char *)shmat(shmid, NULL, SHM_RDONLY);

    printf("Data read from shared memory: %s\n", data);

    printf("Trying to overwrite in read-only mode...\n");
    strcpy(data, "This should fail!");

    shmdt(data); 
    return 0;

}
/*
================================================================
Output: jils@Inspiron-3593:/mnt/e/SS/hands-on-list-2$ cc 30b.c
        jils@Inspiron-3593:/mnt/e/SS/hands-on-list-2$ ./a.out
        Data read from shared memory: This is Shared Memory

        Trying to overwrite in read-only mode...
=================================================================
*/
