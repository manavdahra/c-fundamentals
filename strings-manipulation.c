#include <string.h>
#include <stdio.h>

void strip_newline(char *string, int size) {
	for (int i = 0; i < size; i++) {
		if (string[i] == '\n') {
			string[i] = '\0';
			break;
		}
	}
	return;
}

int main() {
	char name[50];
	char lastname[50];
	char fullname[100];

	printf("Enter your name: \n");
	fgets(name, 50, stdin);
	strip_newline(name, 50);

	if (strcmp(name, "Manav") == 0) {
		printf("That is my name too!\n");
	} else {
		printf("That is not my name.\n");
	}

	printf("your name is %lu letters long\n", strlen(name));
	printf("Enter your lastname: \n");
	fgets(lastname, 50, stdin);
	strip_newline(lastname, 50);

	fullname[0] = '\0';
	strcat(fullname, name);
	strcat(fullname, " ");
	strcat(fullname, lastname);

	printf("Your fullname is %s\n", fullname);
	getchar();

	return 0;
}