#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	char usn[10],name[25],branch[10];
	int sem;
	char phno[15];
	struct node *link;
}NODE;
typedef struct head_node
{
	int count;
	NODE *link;
}HEAD;
void ins_front(HEAD *head);
void ins_rear(HEAD *head);
void del_front(HEAD *head);
void del_rear(HEAD *head);
void display(HEAD *head);
void main()
{
	HEAD *head=(HEAD*)malloc(sizeof(HEAD));
	head->count=0;
	head->link=NULL;
	int choice;
	for(;;)
	{
		printf("Enter your choice\n1.Insert Front\n2.Insert Rear\n3.Delete Front\n4.Delete Rear\n5.Display\n6.exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: ins_front(head); break;
			case 2: ins_rear(head); break;
			case 3: del_front(head); break;
			case 4: del_rear(head); break;
			case 5: display(head); break;
			case 6: exit(0);
			default :printf("INVALID CHOICE\n");
		}
	}
}
void ins_front(HEAD *head)
{
	NODE *newN=(NODE*)malloc(sizeof(NODE));
	printf("ENter USN,Name,Branch,SEM,Phno\n");
	scanf("%s%s%s%d%s",(newN->usn),(newN->name),(newN->branch),&(newN->sem),(newN->phno));
	newN->link=head->link; //check its tricky
	(head->count)++;
	head->link=newN;
}
void ins_rear(HEAD *head)
{	
	NODE *newN=(NODE*)malloc(sizeof(NODE));
	NODE *temp;
	printf("ENter USN,Name,Branch,SEM,Phno\n");
	scanf("%s%s%s%d%s",(newN->usn),(newN->name),(newN->branch),&(newN->sem),(newN->phno));
	if(head->link==NULL)  //case 1 if no node are there
	{
		head->link=newN;
		(head->count)++;
		return;
	}
	temp=head->link;
	while(temp->link!=NULL) //traverse till end and add
		temp=temp->link;
	temp->link=newN;
	(head->count)++;
}
void del_front(HEAD *head)
{
	NODE *temp;
	if(head->link==NULL)
	{
		printf("No node available \n");
		return;
	}
	else
	{
		temp=head->link;
		printf("Deleted record :\n");
		printf("Usn : %s\nName : %s\nBranch : %s\nSemster : %d%\nPhone Number : %s\n",(temp->usn),(temp->name),(temp->branch),(temp->sem),(temp->phno));
		head->link=temp->link; //to attach nxt node
		(head->count)--;
		free(temp);
	}
}
void del_rear(HEAD *head)
{
	NODE *present,*previous;
	if(head->link==NULL)
	{
		printf("List is Empty\n");
		return;
	}
	present=head->link;
	if(present->link==NULL)
	{
		printf("list contains one record\n");
		head->link=NULL;
	}
	else
	{
		while(present->link!=NULL)
		{
			previous=present;
			present=present->link;
		}
		previous->link=NULL;
	}
	printf("Deleted record is\n");
	printf("USN : %s\nName : %s\nBranch : %s\nSemester : %d\nPhone Number : %s\n",(present->usn),(present->name),(present->branch),(present->sem),(present->phno));
	(head->count)--;
	free(present);
}
void display(HEAD *head)
{
	NODE *temp;
	if(head->link==NULL)
	{
		printf("List is Empty\n");
		return;
	}
	else
	{
		printf("Number of nodes : %d\n",head->count);
		printf("Contents of the List \n----------\n");
		temp=head->link;
		while(temp!=NULL)
		{
			printf("----------\nUSN : %s\nName : %s\nBranch : %s\nSem : %d\nPhone Number : %s\n",(temp->usn),(temp->name),(temp->branch),(temp->sem),(temp->phno));
			temp=temp->link;
		}
		printf("----------------\n\n");
	}
}



