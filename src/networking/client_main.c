/*
 * Created by gt on 12/20/21 - 4:10 AM.
 * Copyright (c) 2021 GTXC. All rights reserved.
 */

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

// create a socket for server communication
int socket_create() {
    int h_socket;
    puts("create the socket");
    h_socket = socket(AF_INET, SOCK_STREAM, 0);
    return h_socket;
}

// try to connect with server
int socket_conncet(int h_socket) {
    int i_retval = -1;
    int server_port = 12345;
    struct sockaddr_in remote = {0};
    remote.sin_addr.s_addr = inet_addr("127.0.0.1"); // local host
    remote.sin_family = AF_INET;
    remote.sin_port = htons(server_port);
    i_retval = connect(h_socket, (struct sockaddr *) &remote, sizeof (struct sockaddr_in));
    return i_retval;
}

// send the data to the server and set the timeout of 20 seconds
long int socket_send(int h_socket, char * rqst, int len_rqst) {
    long int l_retval = -1;
    struct timeval tv;
    tv.tv_sec = 20;
    tv.tv_usec = 0;
    if (setsockopt(h_socket, SOL_SOCKET, SO_SNDTIMEO, (char *) &tv, sizeof (tv)) < 0) {
        puts("time out");
        return -1;
    }
    l_retval = send(h_socket, rqst, len_rqst, 0);
    return l_retval;
}

// receive the data from the server
long int socket_receive(int h_socket, char *rsp, int rvc_size) {
    long int l_retval = -1;
    struct timeval tv;
    tv.tv_sec = 20;
    tv.tv_usec = 0;
    if (setsockopt(h_socket, SOL_SOCKET, SO_RCVTIMEO, (char *) &tv, sizeof(tv)) < 0) {
        puts("time out");
        return -1;
    }
    l_retval = recv(h_socket, rsp, rvc_size, 0);
    printf("response %s\n", rsp);
    return l_retval;
}

int main() {
    int h_socket = 0, read_size = 0;
    struct sockaddr_in server;
    char send_to_server[100] = {0};
    char server_reply[200] = {0};
    // create socket
    h_socket = socket_create();
    if (h_socket == -1) {
        puts("could not create socket");
        return 1;
    }
    puts("socket is created");
    // connect to remote server
    if (socket_conncet(h_socket) < 0) {
        perror("connect failed");
        return 1;
    }
    puts("successfully connected with server");
    printf("enter a message: ");
    fgets(send_to_server, 100, stdin);
    // send data to the server
    socket_send(h_socket, send_to_server, (int) strlen(send_to_server));
    //receive the data from the server
    read_size = (int) socket_receive(h_socket, server_reply, 200);
    printf("server response: %s\n\n", server_reply);
    close(h_socket);
    return 0;
}