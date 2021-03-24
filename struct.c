#include <stdlib.h>
#include <stdio.h>
#include "headers/employee.h"

int main() {
	struct employee db;

	db.id = 1;
	db.age = 30;
	db.salary = 15000;

	printf("id: %d age: %d salary: %f\n", db.id, db.age, db.salary);
}
