/*
==================================================================================
Name:19.c
Author:Jils Patel
Description:Write a program to find out time taken to execute getpid system call. 
			Use time stamp counter.
Date: 07 September 2025
==================================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <x86intrin.h>  
			
int main(){
	unsigned long long start,end;
	start=_rdtsc();
	getpid();
	end=_rdtsc();
	printf("Total Cycles: %llu\n",end-start);
	return 0;
}

/*
=================================================================
Output: jils@Inspiron-3593:/mnt/e/SS/hands-on-list-1/19$ cc 19.c
		jils@Inspiron-3593:/mnt/e/SS/hands-on-list-1/19$ ./a.out
		Total Cycles: 5454
=================================================================
*/

