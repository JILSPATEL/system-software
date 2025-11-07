/*
Name:34c.c
Author:Jils Patel
Description:Write Program to create a concurrent server.
            a. use fork
            b. use pthread_create
Date: 23 September 2025
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUF_SIZE 1024

int main() {
    int sock_fd;
    struct sockaddr_in server_addr;
    char buffer[BUF_SIZE];

    sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd < 0) {
        perror("Socket failed");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1"); 

    if (connect(sock_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        exit(1);
    }

    printf("Connected to server. Type messages (type 'exit' to quit)\n");

    while (1) {
        printf("You: ");
        fgets(buffer, BUF_SIZE, stdin);

        if (strncmp(buffer, "exit", 4) == 0) {
            break;
        }

        send(sock_fd, buffer, strlen(buffer), 0);

        int n = read(sock_fd, buffer, BUF_SIZE);
        if (n <= 0) {
            printf("Server disconnected.\n");
            break;
        }
        buffer[n] = '\0';
        printf("Server: %s", buffer);
    }

    close(sock_fd);
    return 0;
}

/*
=======================================================================
Output: jils@Inspiron-3593:/mnt/e/ss/hands-on-list-2$ gcc 34c.c -o 34c
        jils@Inspiron-3593:/mnt/e/ss/hands-on-list-2$ ./34c
        Connected to server. Type messages (type 'exit' to quit)
        You: Hello
        Server: Hello
        You: This is Jils Patel
        Server: This is Jils Patel
        You: exit
========================================================================
*/