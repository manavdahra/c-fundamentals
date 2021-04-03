#include <sys/socket.h>
#include <stdio.h>
#include <arpa/inet.h>
#include <string.h>
#include <netdb.h>

int main() {
	
	// create socket
	int socket_desc = socket(AF_INET, SOCK_STREAM, 0);
	if (socket_desc == -1) {
		printf("Could not create socket\n");
	}

	struct sockaddr_in server;
	server.sin_addr.s_addr = inet_addr("74.125.68.104");
	server.sin_family = AF_INET;
	server.sin_port = htons(80);

	// Connect to the remote server
	if (connect(socket_desc, (struct sockaddr *)&server, sizeof(server)) < 0) {
		puts("connection error\n");
		return 1;
	}
	puts("Connected\n");

	char *message;
	message = "GET / HTTP/1.1\r\n\r\n";
	if (send(socket_desc, message, strlen(message), 0) < 0) {
		puts("Send failed");
		return 1;
	}
	puts("Data sent\n");
	
	char server_reply[2000];
	if (recv(socket_desc, server_reply, 2000, 0) < 0) {
		puts("Receive failed\n");
	}
	puts("Reply received\n");
	puts(server_reply);

	return 0;
}