#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void infix_postfix(char infix[],char postfix[]);
int F(char sym);
int G(char sym);
void main()
{
	char infix[20],postfix[30];
	printf("Enter the infix expression\n");
	scanf("%s",infix);
	printf("The POSTFIX Expression is \n");
	infix_postfix(infix,postfix);
	printf("%s\n",postfix);
}
int F(char sym)
{
	switch(sym)
	{
		case '+':
		case '-': return 2;
		case '*':
		case '/':
		case '%': return 4;
		case '$':
		case '^': return 5;
		case '(': return 0;
		case '#': return -1;
		default : return 8;
	}
}
int G(char sym)
{
	switch(sym)
	{
		case '+':
		case '-': return 1;
		case '*':
		case '/':
		case '%': return 3;
		case '$':
		case '^': return 4;
		case '(': return 9;
		case ')': return 0;
		default : return 7;
	}
}
void infix_postfix(char infix[],char postfix[])
{
	int top=-1,j,i;
	char s[30],symbol;
	s[++top]='#';
	j=0;
	for(i=0;i<strlen(infix);i++)
	{
		symbol=infix[i];
		while(F(s[top])>G(symbol))
			postfix[j++]=s[top--];
		if(F(s[top])!=G(symbol))
			s[++top]=symbol;
		else
			top--;
	}
	while(s[top]!='#')
		postfix[j++]=s[top--];
	postfix[j]='\0';
}
