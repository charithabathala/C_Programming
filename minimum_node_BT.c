//C program to search for minimum node

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

int min_node (struct node *curr)
{
    struct node *temp = curr;
    while(curr->left!=NULL)
        curr=curr->left;
    return curr->val;
}

int max_node (struct node *curr)
{
    struct node *temp = curr;
    while(curr->right!=NULL)
        curr=curr->right;
    return curr->val;
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
	//inorder(root);
	int min_result = min_node(root);
	printf("min node = %d",min_result);
	int max_result = max_node(root);
	printf("max node = %d",max_result);
	return 0;

}