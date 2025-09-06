/*
==========================================================
Name:16b.c
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

	fd=open("text16a.txt",O_RDONLY);
	if (fd < 0) {
        	perror("open");
        	exit(1);
    	}
		
	lock.l_type=F_RDLCK;
	lock.l_whence=SEEK_SET;
	lock.l_start=0;
	lock.l_len=0;
	lock.l_pid=getpid();

	printf("Trying to acquire read lock...\n");
	fcntl(fd,F_SETLKW,&lock);
	printf("Read lock acquired.\n");

	read(fd,buffer,sizeof(buffer));
	printf("Press Enter To Release lock...\n");
	getchar();

	lock.l_type=F_UNLCK;
	fcntl(fd,F_SETLK,&lock);

	printf("Read Lock released.\n");
	close(fd);
	return 0;
}

/*
==================================================================
Output: jils@Inspiron-3593:/mnt/e/ss/hands-on-list-1/16$ cc 16b.c
		jils@Inspiron-3593:/mnt/e/ss/hands-on-list-1/16$ ./a.out
		Trying to acquire read lock...
		Read lock acquired.
		Press Enter To Release lock...

		Read Lock released.
		jils@Inspiron-3593:/mnt/e/ss/hands-on-list-1/16$
===================================================================
*/
