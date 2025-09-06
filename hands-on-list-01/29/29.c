/*
========================================================================================
Name:29.c
Author:Jils Patel
Description:Write a program to get scheduling policy and modify the scheduling policy 
	    (SCHED_FIFO, SCHED_RR).
Date: 07 September 2025
========================================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sched.h>

void print_policy(int policy) {
    if (policy == SCHED_OTHER)
        printf("Policy: SCHED_OTHER (normal)\n");
    else if (policy == SCHED_FIFO)
        printf("Policy: SCHED_FIFO\n");
    else if (policy == SCHED_RR)
        printf("Policy: SCHED_RR\n");
    else
        printf("Policy: UNKNOWN (%d)\n", policy);
}

int main() {
    int pid = 0;
    int old_policy, new_policy;
    struct sched_param param;

    old_policy = sched_getscheduler(pid);
    printf("Old ");
    print_policy(old_policy);

    param.sched_priority = 10;
    sched_setscheduler(pid, SCHED_FIFO, &param);

    new_policy = sched_getscheduler(pid);
    printf("New ");
    print_policy(new_policy);

    return 0;
}
/* 
======================================================================
Output: jils@Inspiron-3593:/mnt/e/SS/hands-on-list-1/29$ cc 29.c
	jils@Inspiron-3593:/mnt/e/SS/hands-on-list-1/29$ sudo ./a.out
	[sudo] password for jils:
	Old Policy: SCHED_OTHER (normal)
	New Policy: SCHED_FIFO
	jils@Inspiron-3593:/mnt/e/SS/hands-on-list-1/29$ 
======================================================================
*/

