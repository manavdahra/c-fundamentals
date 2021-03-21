#include <stdlib.h>
#include <stdio.h>
#include "header.h"

struct node * add(struct node * root, int value) {
	struct node *current = root;
	while (current->next != NULL) {
		current = current->next;
	}
	current->next = malloc(sizeof(struct node));
	current = current->next;
	if (current == NULL) {
		printf("Cannot allocate new node memory\n");
		return NULL;
	}
	current->x = value;
	current->next = NULL;
	return root;
}

void print(struct node *root) {
	struct node *current = root;
	while (current != NULL) {
		printf("%d->", current->x);
		current = current->next;
	}
	printf("NULL\n");
}

int main() {
	struct node *root = malloc(sizeof(struct node));
	if (root == NULL) {
		printf("Cannot allocate root node memory\n");
		return 1;
	}
	root->x = 0;
	
	root = add(root, 1);
	root = add(root, 2);
	root = add(root, 3);
	root = add(root, 4);
	root = add(root, 5);
	print(root);

	return 0;
}