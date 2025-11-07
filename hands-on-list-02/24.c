/*
========================================================================
Name:24.c
Author:Jils Patel
Description:Write a program to create a message queue and print the key 
	    	and message queue id.
Date:23 September 2025
========================================================================
*/
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
	key_t key;
	int msgid;
	key=ftok(".",'a');
	msgid=msgget(key, IPC_CREAT | IPC_EXCL | 0744);
	printf("Key=0x%0x\t msgid=%d\n", key, msgid);
	return 0;
}
/*
===============================================================
Output: jils@Inspiron-3593:/mnt/e/SS/hands-on-list-2$ ./a.out
	Key=0x61480035   msgid=0
===============================================================
*/
