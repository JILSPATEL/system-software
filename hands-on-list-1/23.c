/*
================================================================
Task:23.c
Author:Jils Patel
Write a program to create a Zombie state of the running program.
================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
	pid_t pid=fork();

	if(pid<0){
		printf("error");
		exit(1);
	}
	else if(pid==0){
		printf("Child Process PID:%d\n",getpid());
		exit(0);
	}
	else{
		printf("Parent Process PID:%d sleeping\n",getpid());
		printf("Child PID: %d has become zombie until parent calls wait()\n", pid);

       
        	sleep(90);
	}
	return 0;
}

/*
Output Terminal-1:
jils@Inspiron-3593:/mnt/e/SS/hands-on-list-1$ ./a.out
Parent Process PID:564 sleeping
Child PID: 565 has become zombie until parent calls wait()
Child Process PID:565

Output Terminal-2:
jils@Inspiron-3593:/mnt/e/ss/hands-on-list-1$ cat /proc/565/status | grep State
State:  Z (zombie)
jils@Inspiron-3593:/mnt/e/ss/hands-on-list-1$

