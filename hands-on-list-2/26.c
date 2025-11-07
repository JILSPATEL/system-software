/*
===================================================================
Name:26.c
Author:Jils Patel
Description:Write a program to send messages to the message queue. 
	        Check $ipcs -q.
Date:23 September 2025
===================================================================
*/
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <string.h>

int main() {
    struct msg {
        long int m_type;
        char message[80];
    } myq;

    key_t key;
    int mqid;
    size_t size;

    key = ftok(".", 'a');
    mqid = msgget(key, IPC_CREAT | 0744);

    printf("Enter message type: ");
    scanf("%ld", &myq.m_type);
    getchar(); 

    printf("Enter message text: ");
    scanf("%[^\n]", myq.message);

    size = strlen(myq.message);

    msgsnd(mqid, &myq, size + 1, 0);

    return 0;
}
/*
===========================================================================
Output: jils@Inspiron-3593:/mnt/e/SS/hands-on-list-2$ cc 26.c
	jils@Inspiron-3593:/mnt/e/SS/hands-on-list-2$ ./a.out
	Enter message type: 1
	Enter message text: Hello From Jils
	jils@Inspiron-3593:/mnt/e/SS/hands-on-list-2$ ipcs -q

	------ Message Queues --------
	key        msqid      owner      perms      used-bytes   messages
	0x61480035 1          jils       744        16           1
===========================================================================
*/
