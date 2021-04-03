#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

int g_counter = 0;
void *run(void *var) {
	int* id = (int*) var;
	
	static int i = 0;
	
	i++; 
	g_counter++;

	printf("Thread id: %d, static: %d, global: %d\n", *id, i, g_counter);
	return NULL;
}

int main() {
	pthread_t thread_id;
	
	int i = 0;
	for (i = 0; i < 3; i++)
		pthread_create(&thread_id, NULL, run, (void *)&thread_id);
	
	pthread_exit(NULL);

	return 0;
}