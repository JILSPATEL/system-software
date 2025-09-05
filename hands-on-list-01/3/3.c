/*
================================================================ 
Name=3.c
Author: Jils Patel
Description:Write a program to create a file and print the file 
	    descriptor value. Use creat ( ) system call.
Date: 07 September 2025  
================================================================ 
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(){
	
    int fd = creat("myfile.txt", 0644);

    if(fd==-1){
    	perror("error occurs");
	return 1;
    }

    printf("File created : %d\n",fd);
    close(fd);
    return 0;
}
/*
===========================================================================
Output: jils@Inspiron-3593:/mnt/e/ss/hands-on-list-1/3$ gcc 3.c && ./a.out
	File created : 3
===========================================================================
*/
