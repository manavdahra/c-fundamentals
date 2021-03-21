#include <stdio.h>

int main() {
	for (int i = 0; i < 128; i++) {
		printf("%d -> %c\n", i, (char) i);
	}
	printf("floating point value: %f\n", (float)3/5);
	return 0;
}