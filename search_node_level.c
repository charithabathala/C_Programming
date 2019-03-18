//C program to search for the given node and return the level number

#include <stdio.h>
#include <stdlib.h>

struct node 
{
	int val;
	struct node *left,*right;
};

struct node *create_node(int data)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->val = data;
	temp->left = temp->right = NULL;
	return temp;
}

void inorder(struct node *curr)
{
    if(curr)
    {
        inorder(curr->left);
        printf("%d \n",curr->val);
        inorder(curr->right);
    }
}
struct node* insert(struct node *curr, int data)
{
	if(curr==NULL)
		return create_node(data);

	if(data < curr->val)
		curr->left = insert(curr->left, data);
	else if(data > curr->val)
		curr->right = insert(curr->right, data);
}

int search_level (struct node *curr, int data,int level)
{
	
	if(data<curr->val)
		search_level(curr->left,data,level+1);
	else if (data>curr->val)
		search_level(curr->right,data,level+1);
	else if(data==curr->val)
	    return level;
}

int main()
{
	struct node *root = NULL;
	root = insert(root,20);
	insert(root,8);
	insert(root,22);
	insert(root,4);
	insert(root,12);
	insert(root,10);
	insert(root,14);
	int key = 4;
	int result = search_level(root,key,0);
    printf("The node %d is at level %d",key,result);
	return 0;

}