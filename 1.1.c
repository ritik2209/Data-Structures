#include <stdio.h>
#include <stdlib.h>
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
        printf("%d\n",s->S[i]);
}
struct stack DuplicateStack(struct stack* s)
{
    int val;
    struct stack temp,s2;
    temp.top=-1;
    s2.top=-1;
    while(s->top>-1)
    {
        val=pop(s);
        push(&temp,val);
    }
    while(temp.top>-1)
    {
        val=pop(&temp);
        push(&s2,val);
        push(s,val);
    }
    return s2;
}
int main()
{
    int val;
    struct stack s1,s2;
    s1.top=-1;
    printf("Enter the data:\n");
    for(int i=0;i<size;i++)
    {
        scanf("%d",&val);
        push(&s1,val);
    }
    printf("The Original Stack before duplicating:\n");
    display(&s1);
    s2=DuplicateStack(&s1);
    printf("The Duplicate Stack:\n");
    display(&s2);
    printf("The Original Stack after duplicating:\n");
    display(&s1);
}
