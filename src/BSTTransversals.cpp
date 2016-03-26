/*
Given a Binary Search Tree ,Calculate its Inorder ,Postorder and PreOrder
Input : A BST
Output : Copy Inorder/Postorder/Preorder into the array specified .
Note : Memory for the Array is already allocated ,Dont allocate it again using malloc
->Take help of helper functions which are actually solving the problem .
->Dont Process Invalid Inputs
Bonus Task :
->Go to the BSTTransversals Spec File ,We have left a custom test case for you ,Try to fill
it and understand how testing works .
*/

#include <stdio.h>

struct node{
	struct node * left;
	int data;
	struct node *right;
};


void inorder_call(node * root, int * arr, int * ptr){
	/*

	  1. First Left subtree
	  2. Next visit data
	  3.Next Right subtree

	*/
	if (root == NULL)
		return;
	inorder_call(root->left, arr, ptr);
	arr[*ptr] = root->data;
	(*ptr)++;//must increament here only to retain value in next function call
	inorder_call(root->right, arr, ptr);
}

void preorder_call(node * root, int * arr, int * ptr){
	/*

	1. First visit data
	2. Next Left subtree
	3.Next Right subtree

	*/
	if (root == NULL)
		return;
	arr[*ptr] = root->data;
	(*ptr)++;//must increament here only to retain value in next function call
	preorder_call(root->left, arr, ptr);
	preorder_call(root->right, arr, ptr);
}

void postorder_call(node * root, int * arr, int * ptr){

	/*

	1. First Left subtree
	2.Next Right subtree
	3.Next visit data

	*/

	if (root == NULL)
		return;
	postorder_call(root->left, arr, ptr);
	postorder_call(root->right, arr, ptr);
	arr[*ptr] = root->data;
	(*ptr)++;//must increament here only to retain value in next function call
}

void inorder(struct node *root, int *arr){
	if (root == NULL || arr == NULL){
		return;
	}
	int ptr = 0;
	inorder_call(root, arr, &ptr);
}
void preorder(struct node *root, int *arr){
	if (root == NULL || arr == NULL){
		return;
	}
	int ptr = 0;
	preorder_call(root, arr, &ptr);
}
void postorder(struct node *root, int *arr){
	if (root == NULL || arr == NULL){
		return;
	}
	int ptr = 0;
	postorder_call(root, arr, &ptr);
}