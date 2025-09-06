/*
=================================================================
Task:26.c
Author:Jils Patel
Description:Write a program to execute an executable program.
	    a. use some executable program
	    b. pass some input to an executable program 
	    (for example execute an executable of $./a.out name).
Date: 07 September 2025
=================================================================
*/

#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    execl("./function", "function", argv[1], argv[2], NULL);
    return 0;
}

/*
============================================================================
Output: jils@Inspiron-3593:/mnt/e/SS/hands-on-list-1/26$ cc 26.c
	jils@Inspiron-3593:/mnt/e/SS/hands-on-list-1/26$ ./a.out hello world
============================================================================
*/
