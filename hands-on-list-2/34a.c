/*
========================================================
Name:34a.c
Author:Jils Patel
Description:Write Program to create a concurrent server.
            a. use fork
            b. use pthread_create
Date: 23 September 2025
========================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUF_SIZE 1024

int main() {
    int server_fd, client_fd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len = sizeof(client_addr);
    char buffer[BUF_SIZE];

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        perror("Socket failed");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(server_fd);
        exit(1);
    }

    if (listen(server_fd, 5) < 0) {
        perror("Listen failed");
        close(server_fd);
        exit(1);
    }

    printf("Server ready on port %d...\n", PORT);

    client_fd = accept(server_fd, (struct sockaddr*)&client_addr, &client_len);
    if (client_fd < 0) {
        perror("Accept failed");
        close(server_fd);
        exit(1);
    }

    printf("Client connected from %s:%d\n",
           inet_ntoa(client_addr.sin_addr),
           ntohs(client_addr.sin_port));

    while (1) {
        int n = read(client_fd, buffer, BUF_SIZE - 1);
        if (n <= 0) {
            printf("Client disconnected.\n");
            break;
        }

        buffer[n] = '\0';
        printf("Client: %s", buffer);

        if (strncmp(buffer, "exit", 4) == 0) {
            printf("Closing connection.\n");
            break;
        }

        send(client_fd, buffer, strlen(buffer), 0);
    }

    close(client_fd);
    close(server_fd);
    return 0;
}

/*
========================================================================
Output: jils@Inspiron-3593:/mnt/e/SS/hands-on-list-2$ gcc 34a.c -o 34a
        jils@Inspiron-3593:/mnt/e/SS/hands-on-list-2$ ./34a
        Server ready on port 8080...
        Client connected from 127.0.0.1:38728
        Client: Hello
        Client: This is Jils Patel
        Client disconnected.
========================================================================
*/