/*
==============================================================================
Name:18.c
Author:Jils Patel
Description:Write a program to perform Record locking.
			a. Implement write lock
			b. Implement read lock
			Create three records in a file. Whenever you access a particular 
			record, first lock it then modify/access to avoid race condition.
Date: 07 September 2025
==============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

struct{
	int train_num;
	int ticket_count;
}db[3];

int main(){
 	int fd,i;

 	for(int i=0;i<3;i++){
 		db[i].train_num=i+1;
		db[i].ticket_count=0;
 	}

	fd=open("record.txt",O_CREAT|O_RDWR,0666);
	if(fd<0){
		perror("open");
		exit(1);
	}

	write(fd,db,sizeof(db));
	close(fd);

	printf("created 3 train records in record.txt\n");
	return 0;
}
/*
=================================================================
Output: jils@Inspiron-3593:/mnt/e/ss/hands-on-list-1/18$ ./a.out
		created 3 train records in record.txt
		jils@Inspiron-3593:/mnt/e/ss/hands-on-list-1/18$
=================================================================
*/
