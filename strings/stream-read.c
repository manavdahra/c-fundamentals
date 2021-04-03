#include <stdio.h>

int main() {
	char string[256];
	
	printf("Please enter a long string: \n");
	
	fgets(string, 256, stdin);
	for (int i = 0;i < 256; i++) {
		if (string[i] == '\n') {
			string[i] = '\0';
			break;
		}
	}
	printf("You have entered a very long string: %s\n", string);

	return 0;
}