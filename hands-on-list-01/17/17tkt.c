/*
==========================================================================================
Name:17txt.c
Author:Jils Patel
Description:Write a program to simulate online ticket reservation. Implement write lock
			Write a program to open a file, store a ticket number and exit. 
			Write a separate program, to open the file, implement write lock, 
			read the ticket number, increment the number and print the new ticket number 
			then close the file.
Date: 07 September 2025
==========================================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

struct {
    int ticket_no;
} db;

int main(){
	struct flock lock;
	int fd;

	fd=open("db",O_RDWR);
	if(fd<0){
		perror("open");
		exit(1);
	}
	lock.l_type = F_WRLCK;
        lock.l_whence = SEEK_SET;
        lock.l_start = 0;
        lock.l_len = 0;
        lock.l_pid = getpid();

	printf("Before entering critical section...\n");
	fcntl(fd,F_SETLKW,&lock);
	printf("Inside critical section.\n");

	lseek(fd, 0, SEEK_SET);
    	read(fd, &db, sizeof(db));
	printf("Current ticket Number: %d\n",db.ticket_no);
	
	db.ticket_no++;
	lseek(fd,0,SEEK_SET);
	write(fd, &db, sizeof(db));
    	printf("New ticket Number: %d\n", db.ticket_no);
	
	printf("Press Enter to unlock..\n");
	getchar();

	lock.l_type=F_UNLCK;
	fcntl(fd,F_SETLK,&lock);

	printf("exit from cs\n");
	close(fd);
	return 0;
}

/*
========================================================================
Output: jils@Inspiron-3593:/mnt/e/ss/hands-on-list-1/17$ cc 17db.c
		jils@Inspiron-3593:/mnt/e/ss/hands-on-list-1/17$ ./a.out
		Initial ticket number stored: 10
		jils@Inspiron-3593:/mnt/e/ss/hands-on-list-1/17$ cc 17tkt.c
		jils@Inspiron-3593:/mnt/e/ss/hands-on-list-1/17$ ./a.out
		Before entering critical section...
		Inside critical section.
		Current ticket Number: 10
		New ticket Number: 11
		Press Enter to unlock..

		exit from cs
		jils@Inspiron-3593:/mnt/e/ss/hands-on-list-1/17$
========================================================================
*/
