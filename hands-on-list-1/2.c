/*Write a simple program to execute in an infinite loop at the background. Go to /proc directory and
identify all the process related information in the corresponding proc directory.   */

#include <stdio.h>   
#include <unistd.h>  
int main() {
   
    pid_t pid = getpid();
    printf("Program started. PID: %d\n", pid);
    while (1) {
        printf("Process %d is running\n", pid);
    }

    return 0;
}

