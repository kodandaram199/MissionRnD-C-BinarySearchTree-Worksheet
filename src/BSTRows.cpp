/*
Given a Binary Search Tree ,Copy All Elements in BST into a Array in horizontal row by row fashion where
each row is copied from Right to Left.

First copy the Frist row ,Next the second row etc .
Ex : If Bst is 
    6                        <-- Copy this first 
   / \
  4  10                      <-- Copy this row next from 10 and next 4 ..
 / \   \
1   5   15                   <-- Order her is 15 ,5 ,1 
          \
          17

Output will be a array consisting of [6,10,4,15,5,1,17];

Input : BST head node ;
Output :Return An array which has All the elements in row by row order (R->L) .

Note : Return -1 for Invalid Cases .
*/

#include <stdlib.h>
#include <stdio.h>

struct node{
	struct node * left;
	int data;
	struct node *right;
};

int getHeight(struct node *root){

	if (root == NULL)
		return -1;

	if (root->right == NULL && root->left == NULL)
		return 1;

	int HeightOfLeftSubtree = getHeight(root->left);
	int HeightOfRightSubtree = getHeight(root->right);

	return HeightOfLeftSubtree > HeightOfRightSubtree ? HeightOfLeftSubtree + 1 : HeightOfRightSubtree + 1;
}

void toArray(struct node *root, int *arr, int level, int *position)
{
	if (root == NULL)
		return;
	if (level == 1)
	{
		arr[(*position)++] = root->data;
	}
	else
	{
		toArray(root->right, arr, level - 1, position);
		toArray(root->left, arr, level - 1, position);
	}

}

int* BSTRighttoLeftRows(struct node* root)
{ 
	if (root == NULL)
		return NULL;
	int position = 0; 
	int level;
	int * array = (int *)malloc(sizeof(int) * 30);
	int height = getHeight(root);
	for (level = 1; level <= height; level++)
	{
		toArray(root, array, level, &position);
	}
	return array;
}
