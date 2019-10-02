#include<stdio.h>
#include<stdlib.h>
void TOH( int n, char A, char B, char C);
void main()
{
	int n;
	printf("Enter number of rings:\n");
	scanf("%d", &n);
	TOH(n, 'A', 'C', 'B');
}
void TOH( int n, char A, char B, char C)
{
	if(n==1)
		printf("Move from %c to %c\n",A, B);
	else
	{
		TOH(n-1, A, C, B);
		TOH(1, A, B, C);
		TOH(n-1, C, B, A);
	}
}
