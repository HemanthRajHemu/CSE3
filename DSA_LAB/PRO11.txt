#include<stdio.h>
#include<stdlib.h>
int a[23][12],q[23],visited[23],n,front=0,rear=-1;
void bfs_search(int s)
{
	int d;
	for(d=1;d<=n;d++)
		if(a[s][d] && visited[d]!=1)
		{
			rear=rear+1;
			q[rear]=d;
		}
	if(front<=rear)
	{
		visited[q[front]]=1;
		bfs_search(q[front++]);
	}
}
void main()
{
	int s,col,row;
	printf("Enter the number of vertices\n");
	scanf("%d",&n);
	for(col=1;col<=n;col++)
	{
		q[col]=0;
		visited[col]=0;
	}
	printf("Enter the graph datain the matrix form\n");
	for(row=1;row<=n;row++)
		for(col=1;col<=n;col++)
			scanf("%d",&a[row][col]);
	printf("Enter the starting vertex\n\n");
	scanf("%d",&s);
	bfs_search(s);
	printf("Node reachable are\n");
	for(col=1;col<=n;col++)
		if(visited[col])
			printf("%d\t",col);
}
