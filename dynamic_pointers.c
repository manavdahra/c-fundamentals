#include <stdio.h>
#include <stdlib.h>

int main() {
	int *ptr = malloc(sizeof(*ptr));
	printf("%p\n", ptr);
	free(ptr);
	printf("%p\n", ptr);
}