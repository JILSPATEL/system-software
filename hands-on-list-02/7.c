/*
======================================================================
Name:7.c
Author:Jils Patel
Description:Write a simple program to print the created thread IDs.
Date:23 September 2025
======================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void *myThreadFunction(void *argvp) {
    printf("HELLO WORLD from Thread | Thread ID = %lu\n", pthread_self());
    return NULL;    
}

int main() {
    pthread_t tid;

    if (pthread_create(&tid, NULL, myThreadFunction, NULL) != 0) {
        perror("pthread_create failed");
        exit(1);
    }

    pthread_join(tid, NULL);

    printf("Main Thread ID = %lu\n", pthread_self());

    return 0;
}
/*
==============================================================
Output: jils@Inspiron-3593:/mnt/e/SS/hands-on-list-2$ ./a.out
        HELLO WORLD from Thread | Thread ID = 127881724294848
        Main Thread ID = 127881728083776
==============================================================
*/