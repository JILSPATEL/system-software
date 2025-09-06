/*
=========================================================
Name:24.c
Author:Jils Patel
Description:Write a program to create an orphan process.
Date: 07 September 2025
=========================================================
*/

#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
	if (!fork()) {
		printf("In child - Before orphan PPID = %d\n", getppid());
		sleep(1);
		printf("In child - After orphan PPID = %d\n", getppid());
	}
	else {
		printf("This is parent process %d\n", getpid());
		exit(0);
	}
}

/*
=======================================================================================================
Output Terminal-1:jils@Inspiron-3593:/mnt/e/SS/hands-on-list-1/24$ ./a.out
		  This is parent process 505
		  In child - Before orphan PPID = 505
		  jils@Inspiron-3593:/mnt/e/SS/hands-on-list-1/24$ In child - After orphan PPID = 421

Output Terminal-2:jils@Inspiron-3593:/mnt/e/SS/hands-on-list-1/24$ cat /proc/421/status | grep State
		  State:  S (sleeping)
		  jils@Inspiron-3593:/mnt/e/SS/hands-on-list-1/24$
=======================================================================================================
*/
