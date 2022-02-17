#include<stdio.h>

#define m 10
int q[m],op,f=-1,r=-1;

void enter()
{	
	
	if(r>=m-1)
	{
		printf("Queue overflow\n");	
	}
	else if(f==-1 && r==-1)
	{
		f=0;
		r=0;		
	}
	else
	{
		r=r+1;	
	}
	int x;
	printf("Enter the element\n");
	scanf("%d",&x);	
	q[r]=x;
	
}

void delete()
{
	int val;
	if(f==-1 && f>r)
	{
		printf("Queue underflow\n");
	}
	else
	{
		val=q[f];
		q[f]=0;
		f=f+1;	
		if(f>r)
		{
			f=r=-1;	
		}	
	}
}

void display()
{
	int i=0;
	printf("The queue is:\n");
	for(i=0;i<m;i++)
	{
		printf("%d\n",q[i]);
	}
}
void main()
{
	do
	{
		printf("Enter the operation:\n");
		printf("1. Enter element\n2.Delete element\n");
		printf("3.View Queue\n4. Exit\n");
		scanf("%d",&op);
		switch(op)
		{
			case 1: 
			enter();
			break;
			case 2:
			delete();
			break;
			case 3:
			display();
			break;
			
		}
	}while(op!=4);
}
