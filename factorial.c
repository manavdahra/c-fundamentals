#include <stdio.h>
#include <stdlib.h>

int fact(int x) {
	if (x <= 1) return 1;
	return x * fact(x-1);
}

int main(int argc, char **argv) {
	if (argc < 2) {
		printf("Usage: %s <integer>\n", argv[0]);
		return 1;
	}


	printf("10! = %d", fact((int)strtol(argv[1], NULL, 10)));
	return 0;
}