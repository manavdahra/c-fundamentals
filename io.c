#include <stdio.h>
#include "header.h"

int main() {
	char *text_file_path = "data/test.txt";
	char *text_file_data = "Testing the file writing\n";
	FILE *fp = fopen(text_file_path, "w");
	fprintf(fp, "%s", text_file_data);
	fclose(fp);

	char *bin_file_path = "data/test.bin";
	fp = fopen(bin_file_path, "wb");

	struct database write_db;
	write_db.id = 1;
	write_db.age = 30;
	write_db.salary = 15000;

	fwrite(&write_db, sizeof(write_db), 1, fp);
	fclose(fp);
	
	fp = fopen(bin_file_path, "rb");
	
	struct database read_db;
	fread(&read_db, sizeof(read_db), 1, fp);
	fclose(fp);

	printf("Data read from binary file: id = %d, age = %d, salary = %f\n", read_db.id, read_db.age, read_db.salary);
	return 0;
}