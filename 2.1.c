#include <stdio.h>
#include <stdlib.h>
#define SIZE 10
struct Q
{
    int Qu[10];
    int rear;
    int front;
    int count;
};
void INS(struct Q* a,int data)
{
    if(a->count==SIZE)
        printf("The Queue is Full!\n");
    else
    {
        (a->rear)=((a->rear)+1)%SIZE;
        a->Qu[a->rear]=data;
        (a->count)++;
    }
}
int DEL(struct Q* a)
{
    if(a->count==0)
        return -1;
    else
    {
        int data=a->Qu[a->front];
        a->front=((a->front)+1)%SIZE;
        (a->count)--;
        return data;
    }
}
void display(struct Q* a)
{
    if(a->count==0)
        printf("Nothing to show!");
    else
    {
        printf("The existing Queue:\n");
        int i= a->front;
        int c=0;
        while(c++<a->count)
        {
             printf("|%d|",a->Qu[i]);
             i=(i+1)%SIZE;
        }
    }
    printf("\n");
}
int main()
{
    struct Q a;
    a.rear=-1;
    a.front=0;
    a.count=0;
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
            INS(&a,data);
            break;
        case 2:
            data=DEL(&a);
            if(data==-1)
                printf("The Queue is empty!\n");
            else
                printf("The data deleted is: %d\n",data);
            break;
        case 3:
            display(&a);
            break;
        case 0:
            printf("Thank you!\n");
            exit(0);
        default:
            printf("Sorry, try again!\n");
        }
    }while(ch);
}
