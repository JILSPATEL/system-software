/*
==============================================================================
Name:18a.c
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
}db;

int main(){
	int fd,input;
	struct flock lock;

	fd=open("record.txt",O_RDWR);
	if(fd<0){
		perror("open");
		exit(1);
	}

	printf("select train number (1-3): ");
	scanf("%d",&input);

	lock.l_type=F_WRLCK;
	lock.l_whence=SEEK_SET;
	lock.l_start=(input-1)*sizeof(db);
	lock.l_len=sizeof(db);
	lock.l_pid=getpid();

	lseek(fd, (input - 1) * sizeof(db), SEEK_SET);
        read(fd, &db, sizeof(db));

	fcntl(fd,F_SETLKW,&lock);
	printf("Train %d - Current ticket count: %d\n", db.train_num, db.ticket_count);
	db.ticket_count++;

	lseek(fd,(input-1)*sizeof(db),SEEK_SET);
	write(fd,&db,sizeof(db));

	printf("Booked! New ticket count for train %d: %d\n", db.train_num, db.ticket_count);

    	printf("Press Enter to unlock...\n");
    	getchar(); getchar();

    	lock.l_type = F_UNLCK;
    	fcntl(fd, F_SETLK, &lock);

    	printf("Exited critical section.\n");
    	close(fd);
    	return 0;
}

/*
=================================================================
Output: jils@Inspiron-3593:/mnt/e/ss/hands-on-list-1/18$ ./a.out
		select train number (1-3): 1
		Train 1 - Current ticket count: 2
		Booked! New ticket count for train 1: 3
		Press Enter to unlock...

		Exited critical section.
		jils@Inspiron-3593:/mnt/e/ss/hands-on-list-1/18$
=================================================================
*/
