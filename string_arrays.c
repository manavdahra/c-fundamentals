#include <stdio.h>

int main() {
	char str[10];
	int i = 0;
	scanf("%s", str);
	for (i = 0; i < 10; i++) {
		if (str[i] == 'a') {
			printf("you entered a!\n");
		}
	}
	getchar();
}