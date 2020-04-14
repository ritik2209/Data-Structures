#include <stdio.h>
#include <stdlib.h>

struct tree
{
    int data;
    struct tree* left;
    struct tree* right;
};

void DEL(struct tree** root, int target)
{
    struct tree* parent, *curr, *ptr;
    if(*root == NULL)
        printf("No Tree!\n\n");
    else
    {
        parent=*root;
        curr=*root;
        while(curr->data!=target && curr!=NULL)
        {
            if(curr->data>target)
            {
                parent=curr;
                curr=curr->left;
            }
            else
            {
                parent=curr;
                curr=curr->right;
            }

        }
        if(curr==NULL)
        {
            printf("%d not found!\n\n",target);
            return;
        }
        if(curr->right != NULL && curr->left!=NULL)
        {
            ptr=curr;
            curr=curr->right;
            while(curr->left != NULL)
            {
                parent=curr;
                curr=curr->left;
            }
            int temp=curr->data;
            curr->data=ptr->data;
            ptr->data=temp;
        }
        if(curr->right == NULL && curr->left==NULL)
        {
            if(parent->left==curr)
                parent->left=NULL;
            if(parent->right==curr)
                parent->right=NULL;
        }
        else if(curr->right == NULL && curr->left!=NULL)
        {
            if(parent->left==curr)
                parent->left=curr->left;
            if(parent->right==curr)
                parent->right=curr->left;
        }
        else if(curr->right != NULL && curr->left==NULL)
        {
            if(parent->left==curr)
                parent->left=curr->right;
            if(parent->right==curr)
                parent->right=curr->right;
        }
    }
}

void INS(struct tree** root, int data)
{

    struct tree* temp=(struct tree*)malloc(sizeof(struct tree));
    temp->data=data;
    temp->left=NULL;
    temp->right=NULL;
    if(*root==NULL)
        *root=temp;
    else
    {
        if((*root)->data>data)
            INS(&((*root)->left),data);
        else if((*root)->data<data)
            INS(&((*root)->right),data);
        else
            printf("Duplicate Data is not allowed!\n\n");
    }
}

void INORDER(struct tree* root)
{
    if(root==NULL)
        printf("No Tree");
    else
    {
        if(root->left!=NULL)
            INORDER(root->left);
        printf("%d ",root->data);
        if(root->right!=NULL)
            INORDER(root->right);
    }
}

void PREORDER(struct tree* root)
{
    if(root==NULL)
        printf("No Tree");
    else
    {
        printf("%d ",root->data);
        if(root->left!=NULL)
            INORDER(root->left);

        if(root->right!=NULL)
            INORDER(root->right);
    }
}

void POSTORDER(struct tree* root)
{
    if(root==NULL)
        printf("No Tree");
    else
    {
        if(root->left!=NULL)
            INORDER(root->left);

        if(root->right!=NULL)
            INORDER(root->right);
        printf("%d ",root->data);
    }
}

int main()
{
    struct tree* root= NULL;
    int data,ch;
    while(1){
    printf("Press 1 for Insertion\n");
    printf("Press 2 for Deletion\n");
    printf("Press 3 for Pre Order Traversal\n");
    printf("Press 4 for Post Order Traversal\n");
    printf("Press 5 for In Order Traversal\n");
    printf("Press 6 for exit\n");
    scanf("%d",&ch);
    switch(ch)
    {
    case 1:
        printf("Enter the data to insert: ");
        scanf("%d",&data);
        INS(&root,data);
        break;
    case 2:
        printf("Enter the data to delete: ");
        scanf("%d",&data);
        DEL(&root,data);
        break;
    case 3:
        PREORDER(root);
        printf("\n\n");
        break;
    case 4:
        POSTORDER(root);
        printf("\n\n");
        break;
    case 5:
        INORDER(root);
        printf("\n\n");
        break;
    case 6:
        printf("Thank you!\n");
        exit(0);
    default:
        printf("Wrong Choice!\n\n");
    }
    }
}
