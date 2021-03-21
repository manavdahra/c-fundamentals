#include <stdio.h>

int main() {
	int x;
	int *p;

	p = &x;
	printf("Please enter a number: ");
	scanf("%d", &x);
	printf("%d\n", *p);
	getchar();
}