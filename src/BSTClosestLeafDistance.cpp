/*
Given a Binary Search Tree and a Node(temp).Find the Closest Distance from the Node to 
any leaf of the Tree.
(Least number of Edges needed to be travelled to go to the Node )

Ex : Consider the below tree .
      2
     / \
,   1   3
         \
         14
For 3 ,Output is 1 . As its closest leaf is 14 and 3 is at a distance of 1 to 14 .

Ex 2: Consider the below tree .
    2
   / \
  1   3
       \
        14
        / \
       9   20
      /      \
     6       25
For 3 ,Output is now 2 . As closest leaf to 3 is 1 and 3 is at a distance of 2 to 1 .
(through root 2 )

For 14 ,O/P : 2
For 2 , O/P : 1

Return -1 ,for Invalid Inputs
*/

#include <stdlib.h>
#include <stdio.h>

struct node{
  struct node * left;
  int data;
  struct node *right;
};


struct node* getParentNode(struct node* root, int data){

	struct node *leftNode = NULL, *rightNode = NULL;

	if (root == NULL)
		return NULL;

	if (root->left != NULL){
		if (root->left->data == data)
			return root;
	}
	if (root->right != NULL){
		if (root->right->data == data)
			return root;
	}

	if (root->left != NULL){
		leftNode = getParentNode(root->left, data);
	}
	if (root->right != NULL){
		rightNode = getParentNode(root->right, data);
	}

	
	return leftNode!=NULL?leftNode:rightNode;
	
		
}




int min(int a, int b){

	if (a != -1 && b != -1)
		return a > b ? b : a;

	if (a == -1){
		return b;
	}
	if (b == -1){
		return a;
	}

}

int downTraversalDisatnce(struct node *root){

	int leftDistance, rightDistance;
	if (root == NULL)
		return -1;

	if (root->left == NULL && root->right == NULL)
		return 0;

	leftDistance = downTraversalDisatnce(root->left);
	rightDistance = downTraversalDisatnce(root->right);

	int minimum = min(leftDistance, rightDistance);

	return minimum+1;

}



int get_closest_leaf_distance(struct node *root, struct node *temp)
{
	if (root == NULL || temp == NULL)
		return -1;

	int downDistance = downTraversalDisatnce(temp);

	struct node* parent = getParentNode(root, temp->data);

	if (parent == NULL)
		return downDistance;

	int topTraversalDistance = get_closest_leaf_distance(root, parent);

	if (topTraversalDistance == downDistance)
		return topTraversalDistance;

	int minimum = min(topTraversalDistance, downDistance);

	if (minimum == topTraversalDistance)
		return 1 + topTraversalDistance;

	return downDistance;
}