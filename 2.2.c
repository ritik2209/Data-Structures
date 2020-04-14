#include<stdio.h>
#include<stdlib.h>
#define size 5

struct stack
{
    int S[size];
    int top;
};
void push(struct stack* s, int val)
{
    (s->top)++;
    s->S[s->top]=val;
}
int pop(struct stack* s)
{
    int val=s->S[s->top];
    (s->top)--;
    return val;
}
void display(struct stack* s)
{
    for(int i=s->top;i>=0;i--)
        printf("|%d|",s->S[i]);
    printf("\n");
}
void INS(struct stack* a, struct stack* b, int data)
{
    if(a->top==size-1)
        printf("Queue is FULL!\n");
    else if(a->top==-1)
        push(a,data);
    else
    {
        while(a->top>-1)
        {
            int temp=pop(a);
            push(b,temp);
        }
        push(a,data);
        while(b->top>-1)
        {
            int temp=pop(b);
            push(a,temp);
        }
    }
}
int DEL(struct stack* a)
{
    if(a->top==-1)
        return -1;
    else
    {
        return pop(a);
    }
}
void DISP(struct stack* a)
{
    if(a->top==-1)
        printf("Nothing to show!\n");
    else
    {
        printf("The Existing Queue:\n");
        display(a);
    }
}
int main()
{
    struct stack a,b;
    a.top=-1;
    b.top=-1;
    int ch,data,key;
    do
    {
        printf("1.Insert\n2.Delete\n3.Display\n0.Exit\nEnter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            printf("Enter the data: ");
            scanf("%d",&data);
            INS(&a,&b,data);
            break;
        case 2:
            data=DEL(&a);
            if(data==-1)
                printf("The Queue is empty!\n");
            else
                printf("The data deleted is: %d\n",data);
            break;
        case 3:
            DISP(&a);
            break;
        case 0:
            printf("Thank you!\n");
            exit(0);
        default:
            printf("Sorry, try again!\n");
        }
    }while(ch);
}
