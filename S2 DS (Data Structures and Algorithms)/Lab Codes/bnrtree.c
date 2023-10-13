//Binary Tree with inorder preorder and postorder Traversal
#include<stdio.h>
#include<stdlib.h>

struct node
{   struct node *left;
    int data;
    struct node *right;
};

void inorder(struct node *root)
{
    if(root==NULL)
        return;
    else
    {
        inorder(root->left);
        printf("%d  ",root->data);
        inorder(root->right);
    }
}

void preorder(struct node *root)
{
    if(root==NULL)
        return;
    else
    {
        printf("%d  ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node *root)
{
    if(root==NULL)
        return;
    else
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d  ",root->data);
    }
}

struct node* newnode(int val)
{
    struct node *new=(struct node*)malloc(sizeof(struct node));
    new->data=val;
    new->left=NULL;
    new->right=NULL;
    return new;
}

void main()
{
    printf("\n******BINARY TREE and TRAVERSAL******\n\n");
    int ch;
    struct node *root=NULL;
    root=newnode(1);
    root->left=newnode(2);
    root->right=newnode(3);
    root->left->left=newnode(4);
    root->left->right=newnode(5);
    root->right->left=newnode(6);
    root->right->right=newnode(7);
    printf("MENU:-\n\n1.INORDER TRAVERSAL\n2.PREORDER TAVERSAL\n3.POSTORDER TRAVERSAL\n4.EXIT\n");
    while(1)
    {
        printf("\n\nEnter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: {
                        printf("The inorder traversal of the tree is: ");
                        inorder(root);
                        break;
                    }
            case 2: {
                        printf("The preorder traversal of the tree is: ");
                        preorder(root);
                        break;
                    }
            case 3: {
                        printf("The postorder traversal of the tree is: ");
                        postorder(root);
                        break;
                    }
            case 4: {
                        printf("OHK BEI:)\n");
                        exit(0);
                    }
            default:{
                        printf("INVAID CHOICE!");
                        break;
                    }
                     
        }
    }
    printf("\n");
}
