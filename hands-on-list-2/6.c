/*
===========================================================
Name:6.c
Author:Jils Patel
Description:Write a simple program to create three threads.
Date:23 September 2025
===========================================================
*/
#include <stdio.h>
#include <pthread.h>

void* threadFunc(void* arg){
	int threadNum=*(int*)arg;
	printf("Hello From Thread %d\n",threadNum);
	return NULL;
}
int main(){
	pthread_t t1,t2,t3;
	int n1=1,n2=2,n3=3;

	pthread_create(&t1, NULL, threadFunc, &n1);
    	pthread_create(&t2, NULL, threadFunc, &n2);
    	pthread_create(&t3, NULL, threadFunc, &n3);

	pthread_join(t1, NULL);
    	pthread_join(t2, NULL);
    	pthread_join(t3, NULL);

    	printf("All threads finished.\n");
    	return 0;
}
/*
===============================================================
Output:	jils@Inspiron-3593:/mnt/e/SS/hands-on-list-2$ cc 6.c
	jils@Inspiron-3593:/mnt/e/SS/hands-on-list-2$ ./a.out
	Hello From Thread 1
	Hello From Thread 2
	Hello From Thread 3
	All threads finished.
===============================================================
*/
