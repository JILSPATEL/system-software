/*
========================================================================
Name: 28.c
Author: Jils Patel
Description: Program to change the existing message queue permission
             (using msqid_ds structure).
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
    struct msqid_ds buf;

    key = ftok(".", 'a');
    mqid = msgget(key, 0);

    msgctl(mqid, IPC_STAT, &buf);

    printf("Old permissions: %o\n", buf.msg_perm.mode);

    buf.msg_perm.mode = 0666;  

    msgctl(mqid, IPC_SET, &buf);

    msgctl(mqid, IPC_STAT, &buf);
    printf("New permissions: %o\n", buf.msg_perm.mode);

    return 0;
}
/*
===============================================================
Ouput: jils@Inspiron-3593:/mnt/e/SS/hands-on-list-2$ cc 28.c
	jils@Inspiron-3593:/mnt/e/SS/hands-on-list-2$ ./a.out
	Old permissions: 0
	New permissions: 666
===============================================================
*/

