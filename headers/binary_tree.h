struct binary_tree_node {
	int val; 												/* value */
	struct binary_tree_node *left; 							/* root of left subtree */
	struct binary_tree_node *right; 							/* root of right subtree */ 
} binary_tree_node;
typedef struct binary_tree_node BinaryTreeNode;

void delete_tree(BinaryTreeNode ** root);				/* deletes the tree from given root */
void inorder(BinaryTreeNode * root);						/* prints the tree */
void postorder(BinaryTreeNode * root);					/* prints the tree */
void preorder(BinaryTreeNode * root);					/* prints the tree */
void add_tree_node(int value, BinaryTreeNode ** root); 	/* adds a tree node in the tree */