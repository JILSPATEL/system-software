/*
===========================================================================
Name:28.c
Author:Jils Patel
Description:Write a program to get maximum and minimum real time priority.
Date: 07 September 2025
===========================================================================
*/
#include <stdio.h>
#include <sched.h>

int main()
{
    int mpf = sched_get_priority_min(SCHED_FIFO);
    int mxpf = sched_get_priority_max(SCHED_FIFO);

    int mpr = sched_get_priority_min(SCHED_RR);
    int mxpr = sched_get_priority_max(SCHED_RR);

    printf("%d %d\n", mpf, mxpf);
    printf("%d %d\n", mpr, mxpr);

    return 0;
}
/*
================================================================
Output: jils@Inspiron-3593:/mnt/e/SS/hands-on-list-1$ ./a.out
        1 99
        1 99
        jils@Inspiron-3593:/mnt/e/SS/hands-on-list-1$
================================================================
*/
