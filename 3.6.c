#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* prev;
    struct node* next;
};

struct node* head=NULL;

void showList()
{
    printf("The List:\n");
    if(head==NULL)
        printf("Head[%p]-->NULL\n",head);
    else
    {
        printf("Head[%p]-->",head);
        struct node* current=head;
        while(current->next!=head)
        {
            printf("[%p|%d|%p]-->",current->prev,current->data,current->next);
            current=current->next;
        }
        printf("[%p|%d|%p]-->Head\n",current->prev,current->data,current->next);
    }
}

void append(int data)
{
    struct node* temp=(struct node*) malloc(sizeof(struct node*));
    temp->data=data;
    if(head==NULL)
    {
        head=temp;
        temp->next=head;
        temp->prev=head;
    }
    else
    {
        struct node* current=head;
        while(current->next!=head)
            current=current->next;
        current->next=temp;
        temp->prev=current;
        temp->next=head;
        current=head;
        current->prev=temp;
    }
    printf("The data inserted: %d\n",data);
}

void del()
{
    if(head==NULL)
        printf("Nothing to delete!\n");
    else
    {
        struct node* current=head;
        printf("The data deleted: %d\n",current->data);
        if(current->next==head)
        {
        	printf("\t\tTEST\n");
            head=NULL;
        }
        else{
        head=current->next;
     
        struct node* ptr=head;
        while(ptr->next!=current)
            ptr=ptr->next;
      	ptr->next=head;
        struct node* last = ptr;
        ptr=head;
        ptr->prev=last;
        free(current);
        }
        
        
    }
}
void display()
{
    printf("The Queue:\n");
    if(head==NULL)
        printf("Nothing to show!\n");
    else
    {
        struct node* current=head;
        while(current->next!=head)
        {
            printf("|%d|",current->data);
            current=current->next;
        }
        printf("|%d|\n",current->data);
    }
}

int main()
{
    int ch,data;
    while(1)
    {
        printf("QUEUE with DOUBLY CIRCULAR LINKED LIST\n1.Insertion\n2.Deletion\n3.Display The Queue\n4.Display the Background DCLL\n5.Exit\nEnter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            printf("Enter the data: ");
            scanf("%d",&data);
            append(data);
            break;
        case 2:
            del();
            break;
        case 3:
            display();
            break;
        case 4:
            showList();
            break;
        case 5:
            printf("Thank You!\n");
            exit(0);
        default:
            printf("Sorry, Wrong Choice!\n");
        }
    }

}
