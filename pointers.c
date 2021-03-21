#include <stdio.h>

int main() {
	int x;
	int *ptr;

	ptr = &x;
	printf("Enter the value of x\n");
	scanf("%d", &x);

	printf("You entered: %d\n", *ptr);
	return 0;
}