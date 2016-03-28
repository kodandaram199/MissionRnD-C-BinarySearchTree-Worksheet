/*
Given a Sorted Array of integers .Create a new Balanced Binary Search Tree from the Array
and return the head of the new BST .

Ex : Input : [1,6,10]
Output : A new BST which structure is as follows 
  6
 / \
1  10

A BST is said to be balanced ,when it satisifes the following property 

Every node's Difference of Left subtree height and right-subtree height is not more than 1 .

Below Tree is Not a Balanced BST ,as 1's left subtree has height of 0 ,but 
right subtree height is 2 
(Diff >1)

  1
   \
    3
   / \
  10  5

Note : Return head of newly created BST
Note : Return Null for invalid Inputs
Note : Donot create a new BST .
*/
#include <stdlib.h>
struct node{
	struct node * left;
	int data;
	struct node *right;
};

struct node * bst(int *arr, int begin, int end)
{


	if (begin > end)
		return NULL;
	/*
	calculate mid point.
	All the values to left of mid are less than mid.
	Similarly values to right of mid are less than mid
	we take mid as root and values < mid as left subtree
	and values > mid as right subtree
	
	*/

	/*
	If tree is not balanced AVL rotations can be applied
	*/

	int mid = (begin + end) / 2;

	struct node *root = (struct node*) malloc(sizeof(struct node));

	root->data = arr[mid];
	root->left = bst(arr, begin, mid - 1);
	root->right = bst(arr, mid + 1, end);

	return root;


}
struct node * convert_array_to_bst(int *arr, int len){
	
	if (arr == NULL)
		return NULL;

	int begin = 0;
	int end = len;
	return bst(arr, begin, end);
	
	}

