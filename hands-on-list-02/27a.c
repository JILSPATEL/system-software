/*
========================================================================
Name:27a.c
Author:Jils Patel
Description:Write a program to receive messages from the message queue.
 	    a. with 0 as a flag
 	    b. with IPC_NOWAIT as a flag.
Date:
========================================================================
*/
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    struct msg {
        long int m_type;
        char message[80];
    } myq;

    key_t key;
    int mqid;
    int ret;

    key = ftok(".", 'a');
    mqid = msgget(key, 0);

    printf("Enter message type: ");
    scanf("%ld", &myq.m_type);

    ret = msgrcv(mqid, &myq, sizeof(myq.message), myq.m_type, 0);

    if (ret == -1)
        exit(-1);

    printf("Message type: %ld\nMessage: %s\n", myq.m_type, myq.message);

    return 0;
}
/*
=================================================================
Output: jils@Inspiron-3593:/mnt/e/SS/hands-on-list-2$ cc 27a.c
	jils@Inspiron-3593:/mnt/e/SS/hands-on-list-2$ ./a.out
	Enter message type: 1
	Message type: 1
	Message: Hello From Jils
=================================================================
*/
