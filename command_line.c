#include <stdio.h>

int main(int argc, char *argv[]) {
	if (argc != 2) {
		printf("Usage: %s <filepath>\n", argv[0]);
		return 1;
	}

	FILE *fp = fopen(argv[1], "r");

	if (fp == NULL) {
		printf("could not open file %s\n", argv[1]);
		return 1;
	}

	int c;
	while ((c = fgetc(fp)) != EOF) {
		printf("%c", (char)c);
	}
	fclose(fp);

	return 0;
}