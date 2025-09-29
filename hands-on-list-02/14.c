/*
===========================================================
Name:14.c
Author:Jils Patel
Write a simple program to create a pipe, write to the pipe,
read from pipe and display on the monitor.
===========================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(){
	int fd[2];
	char write_msg[]="Hello Through pipe!";
	char read_msg[100];

	if(pipe(fd)==-1){
		perror("pipe");
		return 1;
	}

	write(fd[1],write_msg,strlen(write_msg) + 1);
	read(fd[0],read_msg,sizeof(read_msg));
	printf("Message %s\n",read_msg);
	return 0;
}
/*
=============================================================
Output:	jils@Inspiron-3593:/mnt/e/ss/hands-on-list-2$ ./a.out
		Message Hello Through pipe!
		jils@Inspiron-3593:/mnt/e/ss/hands-on-list-2$
=============================================================
*/
