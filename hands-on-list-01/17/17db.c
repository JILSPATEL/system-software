/*
==========================================================================================
Name:17db.c
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

struct{
	int ticket_no;
}db;

int main(){
	int fd;
	db.ticket_no=10;

	fd=open("db",O_CREAT | O_RDWR,0766);
	if(fd<0){
		perror("open");
		exit(1);
	}
	
	if (write(fd, &db, sizeof(db)) < 0) {
        	perror("write");
        	close(fd);
        	exit(1);
    	}

	printf("Initial ticket number stored: %d\n", db.ticket_no);
        return 0;
}

/*
========================================================================
Output: jils@Inspiron-3593:/mnt/e/ss/hands-on-list-1/17$ cc 17db.c
		jils@Inspiron-3593:/mnt/e/ss/hands-on-list-1/17$ ./a.out
		Initial ticket number stored: 10
		jils@Inspiron-3593:/mnt/e/ss/hands-on-list-1/17$
========================================================================
*/
