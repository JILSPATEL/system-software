/*
==============================================================================
Name:33b.c
Author:Jils Patel
Description:Write a program to communicate between two machines using socket.
Date:23 September 2025
==============================================================================
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

int main() {
    struct sockaddr_in srv, cli;
    int sd, nsd;
    char buf[80];
    socklen_t sz;
    sd = socket(AF_INET, SOCK_STREAM, 0);
    if (sd < 0) {
        perror("Socket creation failed");
        exit(1);
    }

    srv.sin_family = AF_INET;
    srv.sin_port = htons(3558);          
    srv.sin_addr.s_addr = INADDR_ANY;  
    memset(&(srv.sin_zero), 0, 8);      

    if (bind(sd, (struct sockaddr*) &srv, sizeof(srv)) < 0) {
        perror("Bind failed");
        close(sd);
        exit(1);
    }

    if (listen(sd, 5) < 0) {
        perror("Listen failed");
        close(sd);
        exit(1);
    }

    printf("Server listening on port 3558...\n");

    sz = sizeof(cli);
    nsd = accept(sd, (struct sockaddr*) &cli, &sz);
    if (nsd < 0) {
        perror("Accept failed");
        close(sd);
        exit(1);
    }

    read(nsd, buf, sizeof(buf));
    printf("Message from client: %s\n", buf);

    write(nsd, "ACK from Server\n", 17);

    close(nsd);
    close(sd);

    return 0;
}
/*
===============================================================
Output: jils@Inspiron-3593:/mnt/e/SS/hands-on-list-2$ ./a.out
        Server listening on port 3558...
        Message from client: Hello Server
        jils@Inspiron-3593:/mnt/e/SS/hands-on-list-2$ ./a.out
        Message from server: ACK from Server
===============================================================
*/
