//C program to manage Binary Search Tree

#include<stdio.h>
#include<stdlib.h>

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
struct node* insert(struct node* curr,int data)
{
    if(curr==NULL)
        return create_node(data);

    if(data < curr->val)
        curr->left = insert(curr->left, data);
    else if(data > curr->val)
        curr->right=insert(curr->right, data);

}
int main()
{
    struct node *root = NULL; 
    root = insert(root, 50); 
    insert(root, 30); 
    insert(root, 20); 
    insert(root, 40); 
    insert(root, 70); 
    insert(root, 60); 
    insert(root, 80); 
    inorder(root);
    return 0;

}