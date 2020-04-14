#include<stdio.h>
#include<string.h>
#define size 50
char stack[size];
int top=-1;
void push(char c)
{
	if(top==size-1)
		printf("Stack is full!\n");
	else
	{
		top++;
		stack[top]=c;
	}
}
char pop()
{
	if(top==-1)
	{
		printf("Stack is Empty!\n");
		return -1;
	}
	else
	{
		char c=stack[top];
		top--;
		return c;
	}
}
int main()
{
	char s[100];
	int len,i,c=0;
	printf("Enter your string(in lower case): ");
	gets(s);
	len=strlen(s);
	printf("You have entered: %s\t of length: %d\n",s,len);
	for(i=0;i<len;i++)
	{
		push(s[i]);
	}
	for(i=0;i<len;i++)
	{
		if(s[i]==pop())
			c++;
		else
			break;
	}
	if(c==len)
		printf("%s is Palindrome!\n",s);
	else
		printf("%s is not Palindrome!\n",s);
} 
