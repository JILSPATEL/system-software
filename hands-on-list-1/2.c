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

