#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
    int data;
    struct node* next;
};

void append(struct node** h, int data)
{
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->next=NULL;
    if(*h == NULL)
        *h=temp;
    else
    {
        struct node* current=*h;
        while(current->next!=NULL)
            current=current->next;
        current->next=temp;
    }
}

void display(struct node* h)
{
    if(h==NULL)
        printf("NULL");
    else
    {
        while(h->next!=NULL)
        {
            printf("%d->",h->data);
            h=h->next;
        }
        printf("%d",h->data);
    }
}

int search(struct node* h, int data)
{
	if(h==NULL)
		return -1;
	else
	{
		while(h!=NULL)
		{
			if(h->data==data)
				return 1;
			else
				h=h->next;
		}
		if(h==NULL)
			return -1;
	}
}	
int main()
{
    struct node* list[10];
    int i,n,d,target;
    for(i=0;i<10;i++)
        list[i]=NULL;
    printf("Enter the no of data: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the data: ");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    for(i=0;i<n;i++)
    {
        d=arr[i]%10;
        append(&list[d],arr[i]);
    }
    for(i=0;i<10;i++)
    {
        printf("[%d]->",i);
        display(list[i]);
        printf("\n");
    }
    printf("Enter the target you want to search: ");
    scanf("%d",&target);
    d=target%10;
    int check=search(list[d],target);
    if(check == -1)
    	printf("Element not found!\n");
    else
    	printf("Element found!\n");
}
