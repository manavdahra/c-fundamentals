#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

void *connection_handler(void *socket_desc) {
	int sock = *(int*) socket_desc;

	char *message;
	char client_msg[2000];

	// Send message to client 
	message = "Greetings! I am your connection handler\n";
	write(sock, message, strlen(message));

	message = "I shall be handling your requests\n";
	write(sock, message, strlen(message));

	message = "I shall echo what your write\n";
	write(sock, message, strlen(message));

	int read_size;
	while ((read_size = recv(sock, client_msg, 2000, 0)) > 0) {
		write(sock, client_msg, strlen(client_msg));
	}

	if (read_size == 0) {
		puts("client disconnected");
		fflush(stdout);
	} else if (read_size == -1) {
		perror("recv failed");
	}

	free(socket_desc);

	return 0;
}

int main(int argc, char **argv) {
	int socket_desc, *new_sock;
	struct sockaddr_in server, client;

	// Create socket
	socket_desc = socket(AF_INET, SOCK_STREAM, 0);
	if (socket_desc == -1) {
		perror("Could not create socket descriptor");
		return 1;
	}
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = INADDR_ANY;
	server.sin_port = htons(8888);

	// bind socket: ip + port
	if (bind(socket_desc, (struct sockaddr*)&server, sizeof(server)) < 0) {
		perror("bind failed");
		return 1;
	}
	puts("bind done");

	// start listening for connections
	listen(socket_desc, 3);
	puts("Waiting for incoming connections...");

	int c = sizeof(struct sockaddr_in);
	int new_socket;

	// accept incoming connections and greet the clients
	while ((new_socket = accept(socket_desc, (struct sockaddr*)&client, (socklen_t*)&c))) {
		puts("Connection accepted");
		char* message = "Hello client\n";
		write(new_socket, message, strlen(message));

		pthread_t sniffer_thread;
		new_sock = malloc(1);
		*new_sock = new_socket;

		if (pthread_create(&sniffer_thread, NULL, connection_handler, (void*) new_sock) < 0) {
			perror("Could not create thread\n");
			return 1;
		}

		puts("Handler assigned");
	}

	if (new_socket < 0) {
		perror("accept failed");
		return 1;
	}
	
	return 0;
}