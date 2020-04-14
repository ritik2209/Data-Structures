#include<stdio.h>
#include<string.h>
#define size 50
int stack[size],top=-1;
void push(int val)
{
	if(top==size-1)
		printf("Stack is full\n");
	else
	{
		top++;
		stack[top]=val;
	}
}
int pop()
{
	if(top==-1)
	{
		printf("Stack is Empty!\n");
		return -1;
	}
	else
	{
		int val=stack[top];
		top--;
		return val;
	}
}
int main()
{
	char prefix[size],postfix[size];
	int ch,i,v1,v2,res;
	printf("1.Prefix Evaluation\n2.Postfix Evaluation\nMake your choice: ");
	scanf("%d",&ch);
	if(ch==1)
	{
		printf("Enter your Prefix Expression: ");
		scanf("%s",prefix);
		int len=strlen(prefix);
		printf("You have entered: %s\tof length: %d\n",prefix,len);
		for(i=len-1;i>=0;i--)
		{
			if(prefix[i]>='0' && prefix[i]<='9')
				push(prefix[i]-'0');
			else
			{
				v1=pop();
				v2=pop();
				switch(prefix[i])
				{
					case '+': 
					{
						res=v1+v2;
						break;
					}
					case '-':
					{
						res=v1-v2;
						break;
					}
					case '*':
					{
						res=v1*v2;
						break;
					}
					case '/':
					{
						res=v1/v2;
						break;
					}
				}
				push(res);
			}
		}
		printf("The final result is: %d",pop());
	}
	else
	{
		printf("Enter your Postfix Expression: ");
		scanf("%s",postfix);
		int len=strlen(postfix);
		printf("You have entered: %s\tof length: %d\n",postfix,len);
		for(i=0;i<len;i++)
		{
			if(postfix[i]>='0' && postfix[i]<='9')
				push(postfix[i]-'0');
			else
			{
				v1=pop();
				v2=pop();
				switch(postfix[i])
				{
					case '+': 
					{
						res=v2+v1;
						break;
					}
					case '-':
					{
						res=v2-v1;
						break;
					}
					case '*':
					{
						res=v2*v1;
						break;
					}
					case '/':
					{
						res=v2/v1;
						break;
					}
				}
				push(res);
			}
		}
		printf("The final result is: %d",pop());
	}
}
				
