#include <stdio.h>
#include <stdlib.h>
#include "headers/employee.h"

int main() {
	struct employee *db = malloc(sizeof(*db));
	printf("%p\n", db);
	free(db);
	db = NULL;
	printf("%p\n", db);
}