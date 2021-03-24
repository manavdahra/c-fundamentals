#include "singly_linked_list.h"

struct stack {
	int size;
	SLLNode * head;
	SLLNode * top;
} stack;

typedef struct stack Stack;

void printStack(Stack * s);			/* prints stack */
int push(Stack * s, int value);		/* pushes an item of struct type SLLNode into the stack. Returns the size of the stack after pushing */
int pop(Stack *s);					/* pops an item of struct type SLLNode into the stack. If success returns popped item value (!= -1) else returns -1; */
void deleteStack(Stack *s);			/* deletes the stack by popping each element from stack one by one */