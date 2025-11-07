/*
=========================================================
Name:25.c
Author:Jils Patel
Description:Write a program to print a message queue's 
            (use msqid_ds and ipc_perm structures)
            a. access permission
            b. uid, gid
                c. time of last message sent and received
            d. time of last change in the message queue
                e. size of the queue
            f. number of messages in the queue
            g. maximum number of bytes allowed
            h. pid of the msgsnd and msgrcv
Date:23 September 2025
=========================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <time.h>

struct msg_buffer {
    long msg_type;
    char msg_text[100];
};

int main() {
    key_t key;
    int msqid;
    struct msqid_ds info;
    struct msg_buffer message;

    key = ftok("msgfile", 86);

    msqid = msgget(key, 0666 | IPC_CREAT);
    if (msqid == -1) {
        perror("msgget");
        exit(1);
    }

    message.msg_type = 1;
    strcpy(message.msg_text, "test message");
    if (msgsnd(msqid, &message, sizeof(message.msg_text), 0) == -1) {
        perror("msgsnd");
        exit(1);
    }

    if (msgrcv(msqid, &message, sizeof(message.msg_text), 1, 0) == -1) {
        perror("msgrcv");
        exit(1);
    }

    if (msgctl(msqid, IPC_STAT, &info) == -1) {
        perror("msgctl");
        exit(1);
    }

    // a
    printf("Access Permissions : %o\n", info.msg_perm.mode);

    // b
    printf("UID : %d\n", info.msg_perm.uid);
    printf("GID : %d\n", info.msg_perm.gid);

    // c
    printf("Last msgsnd time   : %s", ctime(&info.msg_stime));
    printf("Last msgrcv time   : %s", ctime(&info.msg_rtime));

    // d
    printf("Last change time   : %s", ctime(&info.msg_ctime));

    // e
    printf("Number of messages : %lu\n", info.msg_qnum);

    // f
    printf("Max bytes allowed  : %lu\n", info.msg_qbytes);

    // g
    printf("PID of last msgsnd : %d\n", info.msg_lspid);
    printf("PID of last msgrcv : %d\n", info.msg_lrpid);

    return 0;
}

/*
===============================================================
Output: jils@Inspiron-3593:/mnt/e/SS/hands-on-list-2$ cc 25.c
        jils@Inspiron-3593:/mnt/e/SS/hands-on-list-2$ ./a.out
        Access Permissions : 666
        UID : 1000
        GID : 1000
        Last msgsnd time   : Wed Sep 10 17:00:18 2025
        Last msgrcv time   : Wed Sep 10 17:00:18 2025
        Last change time   : Wed Sep 10 16:57:31 2025
        Number of messages : 0
        Max bytes allowed  : 16384
        PID of last msgsnd : 1049
        PID of last msgrcv : 1049
================================================================
*/
