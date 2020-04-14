#include<stdio.h>
#include<stdlib.h>

struct tree
{
    int data;
    struct tree* left;
    struct tree* right;
};

struct stack
{
    struct tree* node;
    struct stack* next;
}*top=NULL;

void push(struct tree* ptr)
{
    struct stack* temp;
    temp=(struct stack*)malloc(sizeof(struct stack));
    temp->node=ptr;
    temp->next=top;
    top=temp;
}
struct tree* pop()
{
    struct stack* temp=top;
    struct tree* data=temp->node;
    top=temp->next;
    return data;
}

void CREATE(struct tree** r, int* data, int* left, int* right, int n)
{
    if(n==0)
        printf("There is no data to create the tree\n");
    else
    {
        int i;
        for(i=0;i<n;i++)
        {
            struct tree* temp;
            if(i==0)
            {
                temp=(struct tree*)malloc(sizeof(struct tree));
                temp->data=data[i];
                *r=temp;
            }
            else
            {
                struct tree* ptr;
                ptr=*r;
                while(ptr!=NULL)
                {
                    if(data[i]>ptr->data)
                        ptr=ptr->right;
                    else if(data[i]<ptr->data)
                        ptr=ptr->left;
                    else
                    {
                        temp=ptr;
                        //printf("%d found!\n",data[i]);
                        break;
                    }
                }
            }
            if(left[i]==-1)
                temp->left=NULL;
            else
            {
                struct tree* lc=(struct tree*)malloc(sizeof(struct tree));
                temp->left=lc;
                lc->data=data[left[i]];
            }
            if(right[i]==-1)
                temp->right=NULL;
            else
            {
                struct tree* rc=(struct tree*)malloc(sizeof(struct tree));
                temp->right=rc;
                rc->data=data[right[i]];
            }
        }
    }
}

void INORT(struct tree* ptr)
{
    if(ptr==NULL)
        printf("NO TREE!\n");
    else
    {
        struct tree* curr= ptr,*temp;
        push(curr);
        curr=curr->left;
        while(top!=NULL || curr!=NULL)
        {
            if(curr!=NULL)
            {
                push(curr);
                curr=curr->left;
            }
            if(curr==NULL)
            {
                temp=pop();
                printf("%d ",temp->data);
                curr=temp->right;
            }
        }
    }
}
int main()
{
    struct tree* root=NULL;
    int n,i;
    printf("Enter no of data: ");
    scanf("%d",&n);
    int data[n],left[n],right[n];
    printf("Enter the Data: ");
    for(i=0;i<n;i++)
        scanf("%d",&data[i]);
    printf("Enter the Left Address: ");
    for(i=0;i<n;i++)
        scanf("%d",&left[i]);
    printf("Enter the Right Address: ");
    for(i=0;i<n;i++)
        scanf("%d",&right[i]);
    CREATE(&root,data,left,right,n);
    printf("The Inorder traversal:\n");
    INORT(root);
}
