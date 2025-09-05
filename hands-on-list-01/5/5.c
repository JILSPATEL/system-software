/* 
=================================================================================
Name:5.c
Author:Jils Patel
Description:Write a program to create five new files with infinite loop.Execute 
	    the program in the background and check the file descriptor table at 
	    /proc/pid/fd.
Date: 07 September 2025  
=================================================================================
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(){
	int fd[5];
	for(int i=0;i<5;i++){
		char filename[20];
		sprintf(filename,"file%d.txt",i+1);
		fd[i]=open(filename,O_CREAT | O_RDWR, 0644);
		if(fd[i]==-1){
			perror("error occur");
			return 1;
		}
		printf("created %s with fd= %d\n",filename,fd[i]);
	}
	printf("process ID: %d\n",getpid());

	while(1){
		
	}
	return 0;
}
/*
=====================================================================================================
Output Terminal-1: jils@Inspiron-3593:/mnt/e/SS/hands-on-list-1/5$ ./a.out
		   created file1.txt with fd= 3
		   created file2.txt with fd= 4
		   created file3.txt with fd= 5
		   created file4.txt with fd= 6
		   created file5.txt with fd= 7
		   process ID: 442

Output Terminal-2: jils@Inspiron-3593:/mnt/e/SS/hands-on-list-1/5$ ls -l /proc/442/fd
		   total 0
     		   lrwx------ 1 jils jils 64 Aug 31 07:08 0 -> /dev/pts/0
		   lrwx------ 1 jils jils 64 Aug 31 07:08 1 -> /dev/pts/0
		   lrwx------ 1 jils jils 64 Aug 31 07:08 2 -> /dev/pts/0
		   lrwx------ 1 jils jils 64 Aug 31 07:08 3 -> /mnt/e/SS/hands-on-list-1/5/file1.txt
		   lrwx------ 1 jils jils 64 Aug 31 07:08 4 -> /mnt/e/SS/hands-on-list-1/5/file2.txt
		   lrwx------ 1 jils jils 64 Aug 31 07:08 5 -> /mnt/e/SS/hands-on-list-1/5/file3.txt
		   lrwx------ 1 jils jils 64 Aug 31 07:08 6 -> /mnt/e/SS/hands-on-list-1/5/file4.txt
		   lrwx------ 1 jils jils 64 Aug 31 07:08 7 -> /mnt/e/SS/hands-on-list-1/5/file5.txt
======================================================================================================
*/
