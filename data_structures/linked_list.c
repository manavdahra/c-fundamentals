#include <stdlib.h>
#include <stdio.h>
#include "headers/singly_linked_list.h"

SLLNode * add(SLLNode * root, int value) {
	SLLNode *current = root;
	while (current->next != NULL) {
		current = current->next;
	}
	current->next = malloc(sizeof(SLLNode));
	current = current->next;
	if (current == NULL) {
		printf("Cannot allocate new node memory\n");
		return NULL;
	}
	current->data = value;
	current->next = NULL;
	return root;
}

void print(SLLNode *root) {
	SLLNode *current = root;
	while (current != NULL) {
		printf("%d->", current->data);
		current = current->next;
	}
	printf("NULL\n");
}

int main() {
	SLLNode *root = malloc(sizeof(SLLNode));
	if (root == NULL) {
		printf("Cannot allocate root node memory\n");
		return 1;
	}
	root->data = 0;
	
	root = add(root, 1);
	root = add(root, 2);
	root = add(root, 3);
	root = add(root, 4);
	root = add(root, 5);
	print(root);

	return 0;
}