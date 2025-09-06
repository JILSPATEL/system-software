/*
==========================================================
Name:16a.c
Author:Jils Patel 
Description:Write a program to perform mandatory locking.
 			a. Implement write lock
 			b. Implement read lock
Date: 07 September 2025
==========================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
int main(){
	int fd;
	struct flock lock;
	char buffer[50];

	fd=open("text16a.txt",O_RDWR | O_CREAT,0666);
	if(fd<0){
		perror("open");
		exit(1);
	}

	lock.l_type=F_WRLCK;
	lock.l_whence=SEEK_SET;
	lock.l_start=0;
	lock.l_len=0;
	lock.l_pid=getpid();

	printf("Trying to aquire write lock...\n");
	fcntl(fd,F_SETLKW,&lock);
	printf("Write lock aquired. Enter Data: ");

	scanf("%s", buffer);
        write(fd, buffer, sizeof(buffer));
	
	printf("Press Enter to release lock...\n");
	getchar();
	getchar();

	lock.l_type=F_UNLCK;
	fcntl(fd,F_SETLK,&lock);

	printf("write lock released.\n");
	close(fd);
	return 0;
}

/* 
=================================================================
Output: jils@Inspiron-3593:/mnt/e/ss/hands-on-list-1/16$ ./a.out
		Trying to aquire write lock...
		Write lock aquired. Enter Data: hey
		Press Enter to release lock...

		write lock released.
		jils@Inspiron-3593:/mnt/e/ss/hands-on-list-1/16$
=================================================================
*/
