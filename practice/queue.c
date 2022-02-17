#include <stdio.h>
#include<string.h>

int flag=0;

int enqueue(int Q[],int *F,int *R,int N,int ele){
 	if(flag==0){
		*F=0;
		*R=0;
		flag=1;
	}
	if (*R >= N){
		printf("Queue Overflow \n");
		return 0;
	}
	else{
		*R=*R+1;
		*F=1;
		Q[*R]=ele;
		return Q[*R];
	}
}

int dequeue(int Q[],int *F,int *R){
	int y;
	if(*F == 0){
		printf("Queue Underflowed \n");
		
		return 0;	
	}
	
	else {
		y=Q[*F];
		if(*F == *R){
			*F=0;	
			*R=0;
		}
		else{
			*F=*F+1;
		}
		return y;
	}
}

void display(int Q[],int *F,int *R){
   int i;
   for (i = *F; i <= *R; i++){
         printf("%d ", Q[i]);
   }
}

void main(){

int add;
int choice;
int pushed,poped;
int n=3;
int front=0,rear=0;
int s[n];

	while (1){
		printf("\n1.enqueue; 2.dequeue; 3.display; -1 terminate:");
		scanf("%d", &choice);
		if(choice ==1){	
			while(1){
				int x;
				printf("enter element to be pushed:");
				scanf("%d",&x);

				pushed=enqueue(s,&front,&rear,n,x);
			
				if(pushed == 0)
					break;
				else
					printf("element pushed\n");
			}
		}

		else if(choice == 2){
			while(1){
				poped=dequeue(s,&front,&rear);

				if(poped == 0)
					break;
				else
					printf("\nelement popped:%d\n",poped);
				
			}
		}
		else if(choice == 3){
			display(s,&front,&rear);
		}
		else if(choice == -1){
			break;
		}
	}
}
