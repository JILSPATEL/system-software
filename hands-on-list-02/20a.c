/*
=============================================================================
Name:20a.c
Author:Jils Patel
Description:Write two programs so that both can communicate by FIFO -Use one 
	    way communication.
Date:
=============================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

int main(){
	int fd;
	char buff[100];
	fd=open("myfifo",O_WRONLY);

	printf("Enter Data: ");
	scanf("%[^\n]",buff);
	write(fd, buff, sizeof(buff));
	close(fd);
	return 0;
}
/*
===============================================================
Output: jils@Inspiron-3593:/mnt/e/SS/hands-on-list-2$ cd ~
	jils@Inspiron-3593:~$ mkfifo myfifo
	jils@Inspiron-3593:~$ ls -l myfifo
	prw------- 1 jils jils 0 Sep  7 22:15 myfifo

	jils@Inspiron-3593:~$ ./writer
	Enter Data: Hello FIFO World
===============================================================
*/
