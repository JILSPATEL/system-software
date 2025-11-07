/*
==============================================================================
Name:33a.c
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
    struct sockaddr_in serv;
    int sd;
    char buf[80];

    sd = socket(AF_INET, SOCK_STREAM, 0);
    if (sd < 0) {
        perror("Socket creation failed");
        exit(1);
    }

    serv.sin_family = AF_INET;
    serv.sin_port = htons(3558);  
    if (inet_pton(AF_INET, "127.0.0.1", &serv.sin_addr) <= 0) {
        perror("Invalid address / Address not supported");
        close(sd);
        exit(1);
    }
    memset(&(serv.sin_zero), 0, 8);

    if (connect(sd, (struct sockaddr*)&serv, sizeof(serv)) < 0) {
        perror("Connection failed");
        close(sd);
        exit(1);
    }

    char *msg = "Hello Server\n";
    write(sd, msg, strlen(msg) + 1);  

    read(sd, buf, sizeof(buf));
    printf("Message from server: %s\n", buf);

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
