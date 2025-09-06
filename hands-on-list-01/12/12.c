/*
====================================================================
Name:12.c
Author:Jils Patel
Description:Write a program to find out the opening mode of a file. 
			Use fcntl.
====================================================================
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main(){
	int fd = open("test12.txt", O_RDWR | O_CREAT, 0644);
	int flags = fcntl(fd, F_GETFL);
	if ((flags & O_ACCMODE) == O_RDONLY)
       	 	printf("READ ONLY\n");
    	else if ((flags & O_ACCMODE) == O_WRONLY)
        	printf("WRITE ONLY\n");
    	else if ((flags & O_ACCMODE) == O_RDWR)
        	printf("READ & WRITE\n");
	return 0;
}

/*
=================================================================
Output: jils@Inspiron-3593:/mnt/e/SS/hands-on-list-1/12$ cc 12.c
		jils@Inspiron-3593:/mnt/e/SS/hands-on-list-1/12$ ./a.out
		READ & WRITE
		jils@Inspiron-3593:/mnt/e/SS/hands-on-list-1/12$
=================================================================
*/
