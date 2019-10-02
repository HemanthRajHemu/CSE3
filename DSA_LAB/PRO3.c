/* 3. Design, Develop and Implement a menu driven Program in C for the
following operations on STACK of Integers (Array Implementation of Stack
with maximum size MAX)
a. Push an Element on to Stack
b. Pop an Element from Stack
c. Demonstrate how Stack can be used to check Palindrome
d. Demonstrate Overflow and Underflow situations on Stack
e. Display the status of Stack
f. Exit
Support the program with appropriate functions for each of the above
operations */
#include<stdio.h>
#include<stdlib.h>
#define SIZE 5
void push(int ele,int *top,int stack[]);
void pop(int *top,int stack[]);
void display(int top,int stack[]);
int palindrome(int top,int stack[]);
void main()
{
	int choice,top=-1,ele,flag;
	int stack[SIZE];
	for(;;)
	{
		printf("\n-----------\nEnter Your Choice\n1.PUSH\n2.POP\n3.Display\n4.Palindrome\n5.Exit\n--------\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: if(top==(SIZE-1))
					printf("Stack OverFlow\n");
				else
				{
					printf("Enter the Element to be Pushed\n");
					scanf("%d",&ele);
					push(ele,&top,stack);
				}
				break;
			case 2:if(top==-1)
				       printf("The STACK IS UNDERFLOW\n");
			       else
				       pop(&top,stack);
			       break;
			case 3: if(top==-1)
				       printf("The STACK IS UNDERFLOW\n");
			       else
				       display(top,stack);
			       break;
			case 4:flag=palindrome(top,stack);
			       if(flag==-1)
				       printf("Not a Palindrome\n");
			       else
				       printf("A Palindrome\n");
			       break;
			case 5:exit(0);
			default :printf("INVALID CHOICE\nTRY AGAIN\n");
		}
	}
}
void push(int ele,int *top,int stack[])
{
	stack[++(*top)]=ele;
	return;
}
void pop(int *top,int stack[])
{
	printf("Element removed is %d",stack[*top]);
	*top=*top-1;
	return;
}
void display(int top,int stack[])
{
	int i;
	i=top;
	printf("The Elements in the stack are\n");
	for(;i>-1;i--)
		printf("%d\n",stack[i]);
}
int palindrome(int top,int stack[])
{
	int temp[SIZE],i,j,count=0,top1=top;
	for(j=0;top1>=0;j++)
	{
		temp[j]=stack[(top1)--];
		count++;
	}
	for(i=0;i<=count/2;i++)
	{
		if(temp[i]!=temp[count-i-1])
			return-1;
	}
	return 1;
}
