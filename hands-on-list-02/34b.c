/*
========================================================
Name:34b.c
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
#include <pthread.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define PORT 8080
#define BUF_SIZE 1024

void *handle_client(void *arg) {
    int fd = *(int*)arg;
    free(arg);
    char buf[BUF_SIZE];
    int n;

    while ((n = read(fd, buf, BUF_SIZE - 1)) > 0) {
        buf[n] = '\0';

        if (strncmp(buf, "exit", 4) == 0) {
            printf("Client requested exit.\n");
            break;
        }

        printf("Client: %s", buf);
        fflush(stdout);
        send(fd, buf, n, 0);
    }

    printf("Client disconnected.\n");
    close(fd);
    pthread_exit(NULL);
}

int main() {
    int server_fd, *client_fd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);
    pthread_t tid;

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) { perror("Socket"); exit(1); }

    int opt = 1;
    setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind"); exit(1);
    }

    if (listen(server_fd, 5) < 0) { perror("Listen"); exit(1); }

    printf("Server listening on port %d...\n", PORT);

    client_fd = malloc(sizeof(int));
    *client_fd = accept(server_fd, (struct sockaddr*)&client_addr, &addr_len);
    if (*client_fd < 0) { perror("Accept"); free(client_fd); exit(1); }

    printf("Client connected from %s:%d\n",
           inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

    pthread_create(&tid, NULL, handle_client, client_fd);
    pthread_join(tid, NULL); 

    close(server_fd);

    return 0;
}


/*
=======================================================================
Output: jils@Inspiron-3593:/mnt/e/SS/hands-on-list-2$ gcc 34c.c -o 34c
        jils@Inspiron-3593:/mnt/e/SS/hands-on-list-2$ ./34c
        Connected to server. Type messages (type 'exit' to quit)
        You: Hello
        Server: Hello
        You: This is Jils
        Server: This is Jils
        You: exit
=======================================================================
*/