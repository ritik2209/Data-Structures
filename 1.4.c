#include<stdio.h>
#include<stdlib.h>

#define SIZE 50

void push(int* s,int *t,int val)
{
	if(*t==SIZE-1)
		printf("The Stack is Full!\n");
	else
	{
		(*t)=(*t)+3;
		s[*t]=val;
	}
}
int pop(int* s,int* t)
{
	int val;
	if(*t==-1)
		printf("The Stack is Empty!\n");
	else
	{
		val=s[*t];
		(*t)=(*t)-3;
	}
	return val;
}
void display(int* s,int t)
{
	int i;
	if(t==-1)
		printf("Nothing to show!\n");
	else
	{
		printf("The elements are:\n");
		for(i=t;i>=0;i=i-3)
			printf("%d\n",s[i]);
	}
}
int main()
{
	int s[SIZE],t1=-3,t2=-2,t3=-1,key,ch,val,data;
	do{
	
	printf("1.Push in Stack1\n2.Pop from Stack1\n3.Display the elements of Stack1\n4.Push in Stack2\n5.Pop from Stack2\n6.Display the elements of Stack2\n7.Push in Stack3\n8.Pop from Stack3\n9.Display the elements of Stack3\nMake Your Choice: ");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
		{
			printf("Enter your data: ");
			scanf("%d",&data);
			push(s,&t1,data);
			break;
		}
		case 2:
		{
			printf("The deleted data is: %d\n",pop(s,&t1));
			break;
		}
		case 3:
		{
			display(s,t1);
			break;
		}
		case 4:
		{
			printf("Enter your data: ");
			scanf("%d",&data);
			push(s,&t2,data);
			break;
		}
		case 5:
		{
			printf("The deleted data is: %d\n",pop(s,&t2));
			break;
		}
		case 6:
		{
			display(s,t2);
			break;
		}
		case 7:
		{
			printf("Enter your data: ");
			scanf("%d",&data);
			push(s,&t3,data);
			break;
		}
		case 8:
		{
			printf("The deleted data is: %d\n",pop(s,&t3));
			break;
		}
		case 9:
		{
			display(s,t3);
			break;
		}
		default:
			printf("Wrong Choice!\n");
	}
	printf("Do You want to continue? Press 1 for yes 0 for no: ");
	scanf("%d",&key);		
	}while(key);
}
	
