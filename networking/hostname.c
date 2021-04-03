#include <stdio.h>
#include <arpa/inet.h>
#include <string.h>
#include <netdb.h>
#include <stdlib.h>

void resolve_host(char* hostname) {
	struct hostent *host_entry;
	struct in_addr **addr_list;
	if ((host_entry = gethostbyname(hostname)) == NULL) {
		// gethostbyname failed
		herror("gethostbyname");
		return;
	}

	addr_list = (struct in_addr **) host_entry->h_addr_list;
	int i;
	char ip[100];
	for (i = 0; addr_list[i] != NULL; i++) {
		strcpy(ip, inet_ntoa(*addr_list[i]));
	}
	printf("%s resolved to: %s\n", hostname, ip);
}

int main(int argc, char **argv) {
	if (argc != 2) {
		printf("Usage: <hostname>\n");
		exit(1);
	}
	resolve_host(argv[1]);
	return 0;
}