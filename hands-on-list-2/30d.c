/*
=================================================================================
Name:30d.c
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

    	if (shmctl(shmid, IPC_RMID, NULL) == 0) {
        	printf("Shared memory removed successfully.\n");
    	} else {
        	perror("shmctl");
    	}

    	return 0;

}
/*
=================================================================
Output: jils@Inspiron-3593:/mnt/e/SS/hands-on-list-2$ cc 30d.c
		jils@Inspiron-3593:/mnt/e/SS/hands-on-list-2$ ./a.out
		Shared memory removed successfully.
=================================================================
*/

