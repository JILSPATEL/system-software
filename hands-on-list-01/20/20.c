/*
=======================================================================
Name:20.c
Author:Jils Patel
Description:Find out the priority of your running program. Modify the 
			priority with nice command.
Date: 07 September 2025
=======================================================================
*/

#include <stdio.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <unistd.h>

int main(){
	int priority;

	priority=getpriority(PRIO_PROCESS,0);
	printf("Old priority: %d\n",priority);
	if (setpriority(PRIO_PROCESS, 0, priority + 5) == -1) {
        	perror("setpriority");
    	} 
	else {
        	printf("New priority to: %d\n", priority + 5);
    	}

    	return 0;
}

/*
=================================================================
Output: jils@Inspiron-3593:/mnt/e/SS/hands-on-list-1/20$ cc 20.c
		jils@Inspiron-3593:/mnt/e/SS/hands-on-list-1/20$ ./a.out
		Old priority: 0
		New priority to: 5
		jils@Inspiron-3593:/mnt/e/SS/hands-on-list-1/20$
=================================================================
*/
