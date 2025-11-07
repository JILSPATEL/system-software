/*
======================================================================================
Name:16.c
Author:Jils Patel
Description:Write a program to send and receive data from parent to child vice versa. 
	        Use two way communication.
Date:23 September 2025
======================================================================================
*/
#include <stdio.h>
#include <unistd.h>
int main() {
    int fd1[2], fd2[2];
    char buff1[80], buff2[80];
    pipe(fd1);
    pipe(fd2);
    if (!fork()) {
        // Child
        close(fd1[0]);
        close(fd2[1]); 
        printf("Enter message to parent: ");
        scanf(" %[^\n]", buff1);
        write(fd1[1], buff1, sizeof(buff1));  
        read(fd2[0], buff2, sizeof(buff2));    
        printf("Message from parent: %s\n", buff2);
    }
    else {
        // Parent
        close(fd1[1]); 
        close(fd2[0]); 
        read(fd1[0], buff1, sizeof(buff1));    
        printf("Message from child: %s\n", buff1);
        printf("Enter message to child: ");
        scanf(" %[^\n]", buff2);
        write(fd2[1], buff2, sizeof(buff2));   
    }
}
/*
==============================================================
Output: jils@Inspiron-3593:/mnt/e/SS/hands-on-list-2$ cc 16.c
	jils@Inspiron-3593:/mnt/e/SS/hands-on-list-2$ ./a.out
	Enter message to parent: Hello This is Child
	Message from child: Hello This is Child
	Enter message to child: Hello This is Parent
	Message from parent: Hello This is Parent
==============================================================
*/
