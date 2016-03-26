/*

1)Given a BST ,Find its Maximum Height 

Height of a NULL BST is 0

Height of a BST which has only one node is 1

Ex Input : 

    10 
    /\
   5 80
  /  /
 2  50
  \
   4

Height of above Tree is 4

Ex Output : Return the Height of the Tree , -1 if Invalid

2) Get Sum of Left subtree gets the sum of all nodes ,in the left subtree of the given node
Ex : get_sum_left for 10 in above Tree ,returns 11
get_sum_left for 80 returns 0
Return -1 for invalid inputs

3) Get Sum of Left subtree gets the sum of all nodes ,in the left subtree of the given node
Ex : get_sum_left for 10 in above Tree ,returns 130
get_sum_left for 80 returns 0
Return -1 for invalid inputs

*/
#include <stdlib.h>
#include <stdio.h>

struct node{
	struct node * left;
	int data;
	struct node *right;
};

int sum(struct node* root){


	if (root == NULL)
		return 0;

	if (root->left == NULL && root->right == NULL)
		return root->data;


	return root->data + sum(root->left) + sum(root->right); /* traverse through whole left or right subtree*/

}

int get_height(struct node *root){

	if (root == NULL)
		return 0;

	if (root->right == NULL && root->left ==NULL)
		return 1;

	int HeightOfLeftSubtree = get_height(root->left);
	int HeightOfRightSubtree = get_height(root->right);

	return HeightOfLeftSubtree > HeightOfRightSubtree ? HeightOfLeftSubtree + 1 : HeightOfRightSubtree + 1;


}


int get_left_subtree_sum(struct node *root){

	if (root == 0)
		return 0;
	return sum(root->left);

}

int get_right_subtree_sum(struct node *root){

	if (root == 0)
		return 0;
    return sum(root->right);
}
