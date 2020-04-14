#include <stdio.h>
#include <stdlib.h>

struct tree
{
    int data;
    struct tree* left;
    struct tree* right;
    struct tree* next;
};

struct tree* INSUCC(struct tree ** root, int target)
{
    struct tree *curr, *parent, *ptr;
    if(*root == NULL)
        return NULL;
    else
    {
        parent=*root;
        curr=*root;
        while(curr!=NULL)
        {

            if(curr->data>target)
            {

                curr=curr->left;
            }
            else if(curr->data < target)
            {
                 parent =curr;;
                curr=curr->right;
            }
            else
                break;
        }
        if(curr==NULL)
        {
            printf("%d not found!\n\n",target);
            return NULL;
        }
        else
        {
        if(curr->right != NULL)
        {
            curr=curr->right;
            while(curr->left != NULL)
                curr=curr->left;
            return curr;
        }
        else if(curr->right == NULL)
        {
            if(parent->left == curr)
                return parent;
            else if(parent->right == curr)
            {
                ptr=*root;
                if(ptr->data < target)
                {
                    while(ptr->data < curr->data && ptr!=NULL)
                        ptr=ptr->right;
                    ptr=ptr->right;
                }
                else
                {
                    while(ptr->left->data>curr->data && ptr!=NULL)
                    ptr=ptr->left;
                }
                    return ptr;
            }
        }
    }
}
}

void INSUCC_assign(struct tree** root)
{
    if(*root==NULL)
        printf("No Tree");
    else
    {
        if((*root)->left!=NULL)
            INSUCC_assign(&(*root)->left);
        (*root)->next=INSUCC(root,(*root)->data);
        //printf("Success at %d\n",(*root)->data);
        if((*root)->right!=NULL)
            INSUCC_assign(&(*root)->right);
    }
}

void INS(struct tree** root, int data)
{

    struct tree* temp=(struct tree*)malloc(sizeof(struct tree));
    temp->data=data;
    temp->left=NULL;
    temp->right=NULL;
    if(*root==NULL)
    {
        *root=temp;
        (*root)->left=NULL;
        (*root)->right=NULL;
    }

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
    struct tree* root= NULL, *ptr;
    int data,ch;
    while(1){
    printf("Press 1 for Insertion\n");
    printf("Press 2 to connect the In order Successor\n");
    printf("Press 3 for In Order Successor\n");
    printf("Press 4 for Pre Order Traversal\n");
    printf("Press 5 for Post Order Traversal\n");
    printf("Press 6 for In Order Traversal\n");
    printf("Press 7 for exit\n");
    scanf("%d",&ch);
    switch(ch)
    {
    case 1:
        printf("Enter the data to insert: ");
        scanf("%d",&data);
        INS(&root,data);
        break;
    case 2:
        INSUCC_assign(&root);
        printf("Successfully Done!\n\n");
        break;
    case 3:

        printf("Enter the target data: ");
        scanf("%d",&data);
        ptr=INSUCC(&root,data);
        if(ptr==NULL)
            printf("There is no  InOrder Successor of %d!\n\n",data);
        else
            printf("The InOrder Successor of %d is %d\n\n",data,ptr->data);
        break;
    case 4:
        PREORDER(root);
        printf("\n\n");
        break;
    case 5:
        POSTORDER(root);
        printf("\n\n");
        break;
    case 6:
        INORDER(root);
        printf("\n\n");
        break;
    case 7:
        printf("Thank you!\n");
        exit(0);
    default:
        printf("Wrong Choice!\n\n");
    }
    }
}

