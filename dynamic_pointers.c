#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main() {
	struct database *db = malloc(sizeof(*db));
	printf("%p\n", db);
	free(db);
	db = NULL;
	printf("%p\n", db);
}