#include<stdio.h>
#define m 5
int q[m],op,ff=-1,fr=-1,rf=-1,rr=-1,dq;

void enterf()
{	
	if(rf>=m-1)
	{
		printf("Queue overflow\n");	
	}
	else if(ff==-1 && rf==-1)
	{
		ff=0;
		rf=0;		
	}
	else
	{
		rf=rf+1;	
	}
	int x;
	printf("Enter the element\n");
	scanf("%d",&x);	
	q[rf]=x;
	
}

void enterr()
{
	if(rr==-1 && fr==-1)
	{
		rr=m-1;
		fr=m-1;
	}
	else
	{
		rr=rr-1;
	}
	int x;
	printf("Enter the element:\n");
	scanf("%d",&x);
	q[rr]=x;
}
	
void deletef()
{
	int val;
	if(ff==-1 && ff>rf)
	{
		printf("Queue underflow\n");
	}
	else
	{
		val=q[ff];
		q[ff]=0;
		ff=ff+1;	
		if(ff>rf)
		{
			ff=rf=-1;	
		}	
	}
}
void deleter()
{
	int val;
	if(fr==-1 && fr<rr)
	{
		printf("Queue underflow\n");
	}
	else
	{
		val=q[fr];
		q[fr]=0;	
		fr=fr-1;
		if(fr<rr)
		{
			fr=rr=-1;
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
		printf(" 1.Insert from front\n 2.Insert from rear\n");
		printf(" 3.Delete from front\n 4.Delete from rear\n 5.Disply \n 6.Exit\n\n");
		scanf("%d",&dq);
		switch(dq)
		{
			case 1: 
			enterf();
			break;
			case 2:
			enterr();
			break;
			case 3: 
			deletef();
			break;
			case 4:
			deleter();
			break;
			case 5:
			display();	
		}
	}while(dq!=6);
}

/*

[]     [][][][][][][][]  []
fr,rf			 fr,rr
*/
