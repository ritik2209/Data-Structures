#include<stdio.h>
#include<stdlib.h>

#define SIZE 50
struct S
{
	int arr[SIZE];
	int top;
};
void push(struct S* s,int val)
{
	if(s->top==SIZE-1)
		printf("The Stack is Full!\n");
	else
	{
		s->top++;
		s->arr[s->top]=val;
	}
}
int pop(struct S* s)
{
	int val;
	if(s->top==-1)
		printf("The Stack is Empty!\n");
	else
	{
		val=s->arr[s->top];
		(s->top)--;
	}
	return val;
}
void display(struct S* s)
{
	int i;
	if(s->top==-1)
		printf("Nothing to show!\n");
	else
	{
		for(i=s->top;i>=0;i--)
			printf("%d\n",s->arr[i]);
	}
}
int main()
{
	struct S a,b,c;
	a.top=-1;
	b.top=-1;
	c.top=-1;
	int n1,n2,n3,i,val;
	printf("Enter the number of elements of 1st Stack: ");
	scanf("%d",&n1);
	printf("Enter the number of elements of 2nd Stack: ");
	scanf("%d",&n2);
	printf("Enter the number of elements of 3rd Stack: ");
	scanf("%d",&n3);
	printf("Enter the elements of Stack1:\n");
	for(i=0;i<n1;i++)
	{
		scanf("%d",&val);
		push(&a,val);
	}
	printf("Enter the elements of Stack2:\n");
	for(i=0;i<n2;i++)
	{
		scanf("%d",&val);
		push(&b,val);
	}
	printf("Enter the elements of Stack3:\n");
	for(i=0;i<n3;i++)
	{
		scanf("%d",&val);
		push(&c,val);
	}
	printf("The elements of Stack1:\n");
	display(&a);
	printf("The elements of Stack2:\n");
	display(&b);
	printf("The elements of Stack3:\n");
	display(&c);
	while(b.top>-1)
	{
		val=pop(&b);
		push(&a,val);
	}
	while(c.top>-1)
	{
		val=pop(&c);
		push(&a,val);
	}
	while(a.top>-1)
	{
		push(&c,pop(&a));
		label:
		if(c.arr[c.top]<=b.arr[b.top] || b.top==-1)
			push(&b,pop(&c));
		else
		{
			push(&a,pop(&b));
			goto label;
		}
	}
	printf("The sorted elements in ascending order:\n");
	display(&b);
}
