#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void strip_newline(char *str) {
	int i;
	for (i = 0; i < strlen(str); i++) {
		if (str[i] == '\n') {
			str[i] = '\0';
			break;
		}
	}
}

int main() {
	char *firstname = malloc(256);
	char *lastname = malloc(256);
	char *fullname = malloc(256);

	printf("Enter your firstname:\n");
	fgets(firstname, 128, stdin);

	printf("Enter your lastname:\n");
	fgets(lastname, 128, stdin);

	strip_newline(firstname);
	strip_newline(lastname);

	fullname[0] = '\0';
	strcat(fullname, firstname);
	strcat(fullname, " ");
	strcat(fullname, lastname);

	printf("Your fullname is: %s\n", fullname);
	getchar();
	return 0;
}