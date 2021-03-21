#include <stdio.h>

int main() {
	int array[3][3];
	int i;
	int j;
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			array[i][j] = i*j;
		}
	}
	printf("array:\n");
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			printf("array[%d][%d]=%d\n", i, j, array[i][j]);
		}
		printf("\n");
	}
}