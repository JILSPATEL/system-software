/*
============================================================================
Name:6.c
Author:Jils Patel  
Description:Write a program to take input from STDIN and display on STDOUT. 
			Use only read/write system calls
Date: 07 September 2025
============================================================================
*/
#include <unistd.h>

int main(){
	char c;
	while(read(0,&c,1)>0){
		write(1,&c,1);
	}
	return 0;
}
/*
================================================================
Output:jils@Inspiron-3593:/mnt/e/SS/hands-on-list-1/6$ ./a.out
	Hello
	Hello
================================================================
*/