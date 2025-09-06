/*
==================================================================================
Name:21.c
Author:Jils Patel
Description:Write a program, call fork and print the parent and child process id.
Date: 07 September 2025
==================================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(){
	pid_t pid;
	pid=fork();
	if(pid<0){
		printf("error");
		return 1;
	}
	else if(pid==0){
		printf("Child Process: PID = %d, Parent PID = %d\n", getpid(), getppid());
	}
	else {
        	printf("Parent Process: PID = %d, Child PID = %d\n", getpid(), pid);
    	}
	return 0;
}

/*
=================================================================
Output: jils@Inspiron-3593:/mnt/e/ss/hands-on-list-1/21$ ./a.out
	Parent Process: PID = 402, Child PID = 403
	Child Process: PID = 403, Parent PID = 301
	jils@Inspiron-3593:/mnt/e/ss/hands-on-list-1/21$
=================================================================
*/
