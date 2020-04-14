#include <stdio.h>
#include <stdlib.h>
#include<string.h>
struct node
{
    int coef, power;
    struct node *prev, *next;
};

void append(struct node ** h, int coef, int power )
{
    struct node* temp= (struct node*)malloc(sizeof(struct node));
    temp->coef=coef;
    temp->power=power;
    temp->next=temp->prev=NULL;
    if(*h == NULL)
        *h=temp;
    else
    {
        struct node* current= *h;
        while(current->next!=NULL)
            current=current->next;
        current->next=temp;
        temp->prev=current;
    }
}

void display(struct node* h)
{
    while(h->next!=NULL)
    {
        printf("%dx^%d + ",h->coef,h->power);
        h=h->next;
    }
    printf("%d\n",h->coef);
}

void del(struct node** h, int power)
{
    struct node* curr, *pre;
    curr=*h;
    while(curr!=NULL)
    {
        if(curr->power==power)
            break;
        else
        {
            pre=curr;
            curr=curr->next;
        }
    }
    if(curr==*h)
        *h=curr->next;
    else
        pre->next=curr->next;
    free(curr);
}

void INSBEF(struct node** h, int c,int p, int t_c, int t_p)
{
    struct node* temp= (struct node*)malloc(sizeof(struct node));
    temp->coef=c;
    temp->power=p;
    struct node* curr=*h, *pre;
    while(curr!=NULL)
    {
        if(curr->power==t_p)
            break;
        else
        {
            pre=curr;
            curr=curr->next;
        }
    }

    if(curr==*h)
    {
        temp->next=curr;
        temp->prev=NULL;
        *h=temp;
    }
    else
    {
        temp->next=curr;
        pre->next=temp;
    }
}

void add(struct node** h1, struct node** h2)
{
    struct node* p1=*h1;
    struct node* p2=*h2;
    while(p1!=NULL)
    {
        p2=*h2;
        while(p2!=NULL)
        {
            if(p2->power==p1->power)
            {
                p1->coef=p1->coef+p2->coef;
                del(h2,p2->power);
                break;
            }
            p2=p2->next;
        }
        p1=p1->next;
    }
    p2=*h2;
    p1=*h1;
    while(p2!=NULL)
    {
        p1=*h1;
        while(p1!=NULL)
        {
            if(p2->power>p1->power)
            {
                INSBEF(h1,p2->coef,p2->power,p1->coef,p1->power);
                del(h2,p2->power);
                break;
            }
            else
            {
                 p1=p1->next;
            }

        }
        if(p1==NULL)
        {
            append(h1,p2->coef,p2->power);
            del(h2,p2->power);
        }
        p2=*h2;
    }
}
int main()
{
    int x,i;
    struct node *head1=NULL, *head2=NULL;
    int coef, power;
    printf("Enter no of terms in Polynomial 1: ");
    scanf("%d",&x);
    printf("Enter first polynomial (coefficient and power pairs): \n");
    for(i=0;i<x;i++)
    {
        printf("Enter coefficient: ");
        scanf("%d",&coef);
        printf("Enter power: ");
        scanf("%d",&power);
        append(&head1,coef,power);
    }
    printf("Enter no of terms in Polynomial 2: ");
    scanf("%d",&x);
    printf("Enter second polynomial (coefficient and power pairs): \n");
    while(x--!=0)
    {
        printf("Enter coefficient: ");
        scanf("%d",&coef);
        printf("Enter power: ");
        scanf("%d",&power);
        append(&head2,coef,power);
    }
    printf("First Polynomial of x:\n");
    display(head1);
    printf("Second Polynomial of x:\n");
    display(head2);
    add(&head1,&head2);
    printf("The sum of the polynomials:\n");
    display(head1);
}
