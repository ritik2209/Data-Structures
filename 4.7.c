#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct tree
{
    char data;
    struct tree* left;
    struct tree* right;
};

struct stack
{
    struct tree* node;
    struct stack* next;
};

void push(struct stack** top,struct tree* ptr)
{
    struct stack* temp;
    temp=(struct stack*)malloc(sizeof(struct stack));
    temp->node=ptr;
    temp->next=*top;
    *top=temp;
}
struct tree* pop(struct stack **top)
{
    struct stack* temp=*top;
    struct tree* data=temp->node;
    *top=temp->next;
    return data;
}
void display(struct stack *top)
{
    while(top!=NULL)
    {
        printf("%c\n",top->node->data);
        top=top->next;
    }
     printf("\n\n");
}
int IsOperator(char c)
{
    if(c=='+' || c=='-' || c=='*' || c=='/' )
        return 1;
    else
        return 0;
}
void ExpressionTree(char* in,struct tree** root,struct stack** top1,struct stack** top2)
{
    for(int i=0;i<strlen(in);i++)
    {
        if(IsOperator(in[i]) || in[i]=='(')
        {
            struct tree* temp=(struct tree*)malloc(sizeof(struct tree));
            temp->data=in[i];
            temp->left=NULL;
            temp->right=NULL;
            push(top1,temp);
           /* printf("Operator stack:\n");
            display(*top1);
            printf("Operand stack:\n");
            display(*top2);*/
        }
        else if(in[i]==')')
        {
            struct tree* temp1, *temp2, *temp3;
            temp1=pop(top2);
            temp2=pop(top2);
            temp3=pop(top1);
            pop(top1);
            temp3->right=temp1;
            temp3->left=temp2;
            *root=temp3;
            push(top2,temp3);
            /*printf("Parent: %c\nLC: %c\n RC: %c\n",temp3->data,temp2->data,temp1->data);
            printf("Operator stack:\n");
            display(*top1);
            printf("Operand stack:\n");
            display(*top2);*/
        }
        else
        {
            struct tree* temp=(struct tree*)malloc(sizeof(struct tree));
            temp->data=in[i];
            temp->left=NULL;
            temp->right=NULL;
            push(top2,temp);
            /*printf("Operator stack:\n");
            display(*top1);
            printf("Operand stack:\n");
            display(*top2);*/
        }
    }

}

void inort(struct tree* root)
{
    if(root->left!=NULL)
        inort(root->left);
    printf("%c",root->data);
    if(root->right!=NULL)
        inort(root->right);
}

void preort(struct tree* root)
{
    printf("%c",root->data);
    if(root->left!=NULL)
        preort(root->left);
    if(root->right!=NULL)
        preort(root->right);
}
void postort(struct tree* root)
{
    if(root->left!=NULL)
        postort(root->left);
    if(root->right!=NULL)
        postort(root->right);
    printf("%c",root->data);
}
int main()
{
    struct tree* root=NULL;
    struct stack* top1=NULL;
    struct stack* top2=NULL;
    char inf[100];
    printf("Enter your infix expression: ");
    gets(inf);
    int len=strlen(inf);
    char in[len+2];
    in[0]='(';
    in[len+1]=')';
    for(int i=0;i<len;i++)
        in[i+1]=inf[i];
    ExpressionTree(in,&root,&top1,&top2);
    printf("The Preorder Expression:\n");
    preort(root);
    printf("\nThe postOrder Expression:\n");
    postort(root);
}
