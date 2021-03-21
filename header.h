struct database {
	int id;			/* id */
	int age; 		/* age */
	float salary; 	/* salary */
};

struct node {
	int x;				/* value if node */
	struct node *next; 	/* next node */
};

struct node * add(struct node * root, int value); /* adds the new node with value x in the end of the linked list */
void print(struct node * root); 				  /* prints the nodes in the linked list */

struct tree_node {
	int val; 											/* value */
	struct tree_node *left; 							/* root of left subtree */
	struct tree_node *right; 							/* root of right subtree */ 
} tree_node;

void delete_tree(struct tree_node ** root);				/* deletes the tree from given root */
void inorder(struct tree_node * root);					/* prints the tree */
void postorder(struct tree_node * root);				/* prints the tree */
void preorder(struct tree_node * root);					/* prints the tree */
void add_tree_node(int value, struct tree_node ** root); /* adds a tree node in the tree */
