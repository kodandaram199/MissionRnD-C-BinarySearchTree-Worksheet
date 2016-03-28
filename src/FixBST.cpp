/*

Given a Binary Search Tree ,with two misplaced Node .Find those nodes and fix them .

Do not create a new tree ,Modify the original tree
Ex : In the below tree 3 and 30 is misplaced .

  5
 / \
2   3
 \
  30
When fixed 30 will be right node of 5 , and 3 will be right node of 2 .

Ex :In the below tree 1 and 20 are misplaced

         9
        / \
       4   1
      /     \
    20      30
Nodes 1 and 20 need to be fixed here .

*/
#include <stdio.h>
#include <stdlib.h>


struct node{
	struct node * left;
	int data;
	struct node *right;
};

void fixedBST(struct node* root, struct node** current, struct node** middle, struct node** last, struct node** prev)
{
	if (root!=NULL)
	{
		fixedBST(root->left, current, middle, last, prev);
		if ((*prev!=NULL) && (root->data < (*prev)->data))
		{
			
			if (*current==NULL)
			{
				*current = *prev;
				*middle = root;
			}
			else
				*last = root;
		}
		*prev = root;
		fixedBST(root->right, current, middle, last, prev);
	}
}
void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void fix_bst(struct node *root){
	struct node *first, *middle, *last, *prev;
	first = middle = last = prev = NULL;
	fixedBST(root, &first, &middle, &last, &prev);
	if (first && last)
		swap(&(first->data), &(last->data));
	else if (first && middle)
		swap(&(first->data), &(middle->data));
	else
		return;
}
