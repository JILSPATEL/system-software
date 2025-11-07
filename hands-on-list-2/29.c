/*
========================================================================
Name: 29.c
Author: Jils Patel
Description: Program to remove the existing message queue.
Date:23 September 2025
========================================================================
*/

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>

int main() {
    key_t key;
    int mqid;

    key = ftok(".", 'a');
    mqid = msgget(key, 0);

    msgctl(mqid, IPC_RMID, NULL);

    printf("Message queue removed.\n");

    return 0;
}
/*
==============================================================
Output: jils@Inspiron-3593:/mnt/e/SS/hands-on-list-2$ cc 29.c
	jils@Inspiron-3593:/mnt/e/SS/hands-on-list-2$ ./a.out
	Message queue removed. 
==============================================================
*/
