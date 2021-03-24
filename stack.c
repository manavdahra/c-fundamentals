#include <stdio.h>
#include <stdlib.h>
#include "headers/stack.h"

void printStack(Stack * s) {
	SLLNode * current = s->head;
	printf("stack: [");
	while (current != NULL) {
		printf("%d->", current->data);
		current = current->next;
	}
	printf("NULL] top: %p head: %p size: %d\n", s->top, s->head, s->size);
}

int push(Stack * s, int value) {
	if (s == NULL) return -1;
	SLLNode * node = malloc(sizeof(SLLNode));
	node->data = value;
	node->next = NULL;
	if (s->head == NULL) {
		s->head = node;
	} else {
		s->top->next = node;
	}
	s->top = node;
	s->size++;
	return s->size-1;
}

int pop(Stack *s) {
	if (s == NULL || s->size == 0 || s->head == NULL || s->top == NULL) return -1;

	int value;
	if (s->top == s->head) {
		free(s->top);
		value = s->top->data;
		s->top = NULL;
		s->head = NULL;
		s->size--;
		return value;
	}

	SLLNode * node = s->head;
	value = s->top->data;
	while (node->next != s->top) node = node->next;
	free(s->top);
	s->top = node;
	node->next = NULL;
	s->size--;
	return value;
}

void deleteStack(Stack *s) {
	int top;
	while ((top = pop(s)) != -1) {
		printf("popped=%d\n", top);
	}
}

int main() {
	Stack * s = malloc(sizeof(Stack));
	s->head = NULL;
	s->top = NULL;
	s->size = 0;

	push(s, 1);
	push(s, 2);
	push(s, 3);	
	
	pop(s);
	
	pop(s);
	
	push(s, 4);

	printStack(s);

	deleteStack(s);
	printStack(s);

	return 0;
}