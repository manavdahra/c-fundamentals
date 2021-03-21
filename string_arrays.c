#include <stdio.h>
#include <string.h>

int main() {
	char *str;
	printf("Enter the string:\n");
	scanf("%s", str);
	int i;
	for (i = 0; i < strlen(str); i++) {
		if (str[i] == 'a') {
			printf("You entered character a!\n");
			break;
		}
	}
	return 0;
}