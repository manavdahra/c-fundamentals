struct sll_node {
	int data;					/* value if node */
	struct sll_node *next; 	/* next node */
} sll_node;
typedef struct sll_node SLLNode;

SLLNode * add(SLLNode * head, int value); 	/* adds the new node with value x in the end of the linked list */
void print(SLLNode * head); 				/* prints the nodes in the linked list */