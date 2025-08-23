/*Write a program to display the environmental variable of the user (use environ).*/

#include <stdio.h>

extern char **environ; // gives access to environment variables

int main() {
    int i = 0;
    while (environ[i] != NULL) {
        printf("%s\n", environ[i]);
        i++;
    }
    return 0;
}

