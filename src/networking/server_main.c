/*
 * Created by gt on 12/20/21 - 3:48 AM.
 * Copyright (c) 2021 GTXC. All rights reserved.
 */

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int socket_create() {
    int h_socket;
    puts("create the socket");
    h_socket = socket(AF_INET, SOCK_STREAM, 0);
    return h_socket;
}

int bind_created_socket(int h_socket) {
    int i_retval = -1;
    int client_port = 12345;
    struct sockaddr_in remote = {0};
    // internet address family
    remote.sin_family = AF_INET;
    // any incoming interface
    remote.sin_addr.s_addr = htonl(INADDR_ANY);
    remote.sin_port = htons(client_port); // local port
    i_retval = bind(h_socket, (struct sockaddr *) &remote, sizeof remote);
    return i_retval;
}

int main() {
    int socket_desc = 0, sock = 0, client_len = 0;
    struct sockaddr_in client;
    char client_message[200] = {0};
    char message[100] = {0};
    const char *p_message = "hello from gt's server";
    // create socket
    socket_desc = socket_create();
    if (socket_desc == -1) {
        puts("could not create socket");
        return 1;
    }
    puts("socket created");
    //bind
    if (bind_created_socket(socket_desc) < 0) {
        perror("bind failed");
        return 1;
    }
    puts("bind done");
    //listen, max 3 connections
    listen(socket_desc, 3);
    // accept an incoming connection
    while (1) {
        puts("waiting for incoming connections...");
        client_len = sizeof (struct sockaddr_in);
        // accept connction from an incoming client
        sock = accept(socket_desc, (struct sockaddr *) &client, (socklen_t *) &client_len);
        if (sock < 0) {
            perror("accept failed");
            return 1;
        }
        puts("connection accepted");
        memset(client_message, '\0', sizeof client_message);
        memset(message, '\0', sizeof message);
        // receive a reply from the client
        if (recv(sock, client_message, 200, 0) < 0) {
            puts("receive failed");
            break;
        }
        printf("client reply: %s\n", client_message);
        if (strncmp(p_message, client_message, 4) == 0) {
            strcpy(message, "hi there!");
        } else {
            strcpy(message, "invalid message!");
        }
        // send some data
        if (send(sock, message, strlen(message), 0) < 0) {
            puts("send failed");
            return 1;
        }
        close(sock);
        sleep(1);
    }
    return 0;
}