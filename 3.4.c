#include <stdio.h>
#include <stdlib.h>
#include<string.h>

struct node
{
    int data;
    struct node *next;
};

struct node* top=NULL;
void display()
{
    if(top==NULL)
        printf("Nothing to display!\n");
    else
    {
        struct node *ptr;
        ptr=top;
        printf("The stack is:\n");
        while(ptr!=NULL)
        {
            printf("%d\n",ptr->data);
            ptr=ptr->next;
        }
    }
}
void push(int data)
{
    struct node* temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->next=top;
    top=temp;
    display();
}
int pop()
{
    if(top==NULL)
        printf("Stack is Empty!\n");
    else
    {
        struct node *temp;
        temp=(struct node*)malloc(sizeof(struct node));
        temp=top;
        top=temp->next;
        temp->next=NULL;
        int data=(temp->data);
        free(temp);
        return data;
    }
    //display();
}
int main()
{
    int ch,i,len,num,v1,v2;
   char s[100];
   printf("Press 1 for Postfix Evaluation\nPress 2 for Prefix Evaluation\n");
   scanf("%d",&ch);
   switch(ch)
   {
   case 1:
    {
        printf("Enter your postfix expression: ");
        getchar();
        gets(s);
        len=strlen(s);
        printf("You have entered : ");
        puts(s);
        printf("With length: %d\n",len);
        i=0;
        while(i<len)
        {
            num=0;
            if(s[i]>='0' && s[i]<='9')
            {
                while(s[i]!=' ')
                {
                    num=num*10+(s[i]-'0');
                    i++;
                }
                i++;
                push(num);
            }
            else if(s[i]== ' ')
                i++;
            else
            {
                v1=pop();
                v2=pop();
                switch(s[i])
                {
                case '+':
                    push(v2+v1);break;
                case '-':
                    push(v2-v1);break;
                case '*':
                    push(v2*v1);break;
                case '/':
                    push(v2/v1);break;
                }
                i++;
            }
        }
        printf("Your Evaluated Answer is: %d\n",pop());
    }

    case 2:
    {
        printf("Enter your prefix expression: ");
        getchar();
        gets(s);
        len=strlen(s);
        printf("You have entered : ");
        puts(s);
        printf("With length: %d\n",len);
        i=len-1;
        while(i>=0)
        {
            num=0;
            int j=1;
            if(s[i]>='0' && s[i]<='9')
            {
                while(s[i]!=' ')
                {
                    num=num+j*(s[i]-'0');
                    j=j*10;
                    i--;
                }
                push(num);
            }
            else if(s[i]== ' ')
                i--;
            else
            {
                v1=pop();
                v2=pop();
                switch(s[i])
                {
                case '+':
                    push(v2+v1);break;
                case '-':
                    push(v1-v2);break;
                case '*':
                    push(v2*v1);break;
                case '/':
                    push(v1/v2);break;
                }
                i--;
            }
        }
        printf("Your Evaluated Answer is: %d\n",pop());
    }
   }
}
