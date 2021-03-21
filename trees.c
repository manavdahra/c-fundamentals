#include <stdio.h>
#include <stdlib.h>
#include "header.h"

void delete_tree(struct tree_node ** root) {
	if (*root == NULL) return;
	
	delete_tree((&(*root)->left));	
	(*root)->left = NULL;

	delete_tree((&(*root)->right));	
	(*root)->right = NULL;
		
	free(*root);
	*root = NULL;
}

void add_tree_node(int value, struct tree_node ** root) {
	if (*root == NULL) {
		*root = (struct tree_node *) malloc(sizeof(struct tree_node));
		(*root)->val = value;
		(*root)->left = NULL;
		(*root)->right = NULL;
		return;
	}

	if (value <= (*root)->val) {
		add_tree_node(value, &((*root)->left));
	} else if (value > (*root)->val) {
		add_tree_node(value, &((*root)->right));
	}
}

void inorder(struct tree_node * root) {
	if (root == NULL) return;

	inorder(root->left);
	printf("%d ", root->val);
	inorder(root->right);
}

void postorder(struct tree_node * root) {
	if (root == NULL) return;

	postorder(root->left);
	postorder(root->right);
	printf("%d ", root->val);
}

void preorder(struct tree_node * root) {
	if (root == NULL) return;

	printf("%d ", root->val);
	preorder(root->left);
	preorder(root->right);
}

int main() {
	
	struct tree_node * root = NULL;
	add_tree_node(2, &root);
	add_tree_node(1, &root);
	add_tree_node(3, &root);
	add_tree_node(4, &root);
	
	inorder(root);
	printf("\n");

	preorder(root);
	printf("\n");

	postorder(root);
	printf("\n");

	delete_tree(&root);
	
	inorder(root);
	printf("\n");

	preorder(root);
	printf("\n");

	postorder(root);
	printf("\n");

	return 0;
}