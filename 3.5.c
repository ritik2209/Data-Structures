#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    int data;
    struct node* next;
};
struct node* head=NULL;

void del(int data)
{
	struct node *prev, *current;
    current=head;
    prev=head;
    if(current->data==data)
    {
    	head=current->next;
    }
    else
    {
    	current=current->next;
    	while(current!=NULL)
    	{
        	if(current->data==data)
        	    break;
        	else
        	{
            	prev=current;
            	current=current->next;
        	}
        }
        prev->next=current->next;
    }
    free(current);
}

void append(int data)
{
    struct node* temp=(struct node*) malloc(sizeof(struct node));
    temp->data=data;
    temp->next=NULL;
    if(head==NULL)
        head=temp;
    else
    {
        struct node* current=head;
        while(current->next !=NULL)
            current=current->next;
        current->next=temp;
    }
}
void INSBEF(int data, int target)
{
    struct node *prev, *current;
    current=head;
    while(current!=NULL)
    {
        if(current->data==target)
        {
            if(current!=head)
            {
            struct node* temp=(struct node*) malloc(sizeof(struct node));
            temp->data=data;
            temp->next=current;
            prev->next=temp;
            }
            else
            {
                struct node* temp=(struct node*) malloc(sizeof(struct node));
                temp->data=data;
                temp->next=current;
                head=temp;
            }
            break;
        }

        else
        {
            prev=current;
            current=current->next;
        }
    }

}

void display()
{
    struct node* current= head;
    printf("Head[%p]-->",head);
    while(current!=NULL)
    {
        printf("[%d|%p]-->",current->data,current->next);
        current=current->next;
    }
    printf("NULL\n");
}

void distinct()
{
	struct node* curr=head;
	while(curr->next!=NULL)
	{
		if(curr->data == curr->next->data)
		{
			del(curr->data);	
			curr=head;
		}
		else
			curr=curr->next;
	}
}
		

int main(int argc , char *argv[])
{
    int i=0,j=0,num=0;
    char s[100];
    printf("The numbers before sorting: \n");
    for(i=1;i<argc;i++)
    	printf("%s ",argv[i]);
    printf("\n");
    for(j=1;j<argc;j++)
    {
    	i=0;
    	while(i<strlen(argv[j]))
  		{
        if(argv[j][i]>='0' && argv[j][i]<='9')
            {
                num=0;
                while(argv[j][i]!=' ' && i<strlen(argv[j]))
                {
                    num=num*10+(argv[j][i]-'0');
                    i++;
                }
                if(head==NULL)
                {
                    append(num);
                }
                else
                {
                    struct node* current=head;
                    while(current!=NULL)
                    {
                        if(current->data > num)
                        {
                            INSBEF(num,current->data);
                            break;
                        }
                        else
                            current=current->next;
                    }
                    if(current==NULL)
                    {
                        append(num);
                    }

                }
            }
    	}
    }
    distinct();
    printf("The List after sorting:\n");
    display();
}
