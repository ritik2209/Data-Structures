#include<stdio.h>
#include<string.h>
char stack[100];
int top=-1;
void push(char c)
{
	top++;
	stack[top]=c;
}
char pop()
{
	char c=stack[top];
	top--;
	return c;
}
int prec(char c)
{
	switch(c)
	{
		case '/':
		{
			return 4;
			break;
		}
		case '*':
		{
			return 3;
			break;
		}
		case '+':
		{
			return 2;
			break;
		}
		case '-':
		{
			return 1;
			break;
		}
	}
}
int main()
{
	char infix[100],postfix[100];
	int len,i,j=0;;
	printf("Enter your Infix Expression: ");
	scanf("%s",infix);
	len=strlen(infix);
	printf("You have entered: %s\twith length:%d\n",infix,len);
	for(i=0;i<len;i++)
	{
		if(infix[i]=='(')
			push(infix[i]);
		else if(infix[i]>='0' && infix[i]<='9')
		{
			postfix[j++]=infix[i];
		}
		else if(infix[i]==')')
		{
			while(stack[top]!='(')
			{
				postfix[j++]=pop();
			}
			top--;
		}
		else
		{
			label:
			if(stack[top]=='(' || prec(infix[i])>=prec(stack[top]) || top==-1) 
				push(infix[i]);
			else
			{
				postfix[j++]=pop();
				goto label;
			}
		}
	}
	while(top>-1)
		postfix[j++]=pop();
	printf("The Postfix is: %s\n",postfix);
}
