/*
=============================================================================
Name:23.c
Author:Jils Patel
Description:Write a program to create a Zombie state of the running program.
Date: 07 September 2025
=============================================================================
*/
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
	if (!fork()) {
		printf("In child - PID = %d\n", getpid());
	}
	else {
		printf("This is parent process %d\n", getpid());
		sleep(30);
		wait(0);
	}
}

/*
====================================================================================================
Output Terminal-1:jils@Inspiron-3593:/mnt/e/SS/hands-on-list-1/23$ ./a.out
		  This is parent process 472
		  In child - PID = 473

Output Terminal-2:jils@Inspiron-3593:/mnt/e/SS/hands-on-list-1/23$ cat /proc/473/status | grep State
		  State:  Z (zombie)
		  jils@Inspiron-3593:/mnt/e/SS/hands-on-list-1/23$
====================================================================================================
*/
