#include <stdio.h>
#include<string.h>

int flag=0;

int cenqueue(int Q[],int *F,int *R,int N,int ele){
 	//printf("%d",*R);
	if (*R == N){
		*R=1;
	}

	else{
		*R=*R+1;
	}

	if (*F == *R){
		printf("overflow");
		return 0;
	}

	else{
		if (*F == 0)
			*F=1;
		Q[*R]=ele;
		return Q[*R];
	}

}

int cdequeue(int Q[],int *F,int *R){
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

void display(int Q[],int *F,int *R,int N){
   int i;
   for (i = 1; i <=3; i++){
         printf("%d %d %d\t", Q[i],*F,*R);
   }
}

void main(){

int add;
int choice;
int pushed,poped;
int n=3;
int front=0,rear=0;
int s[n];
int j=0;
	while (1){
		printf("\n1.enqueue; 2.dequeue; 3.display; -1 terminate:");
		scanf("%d", &choice);
		if(choice ==1){	
			while(j<2){
				int x;
				printf("enter element to be pushed:");
				scanf("%d",&x);

				pushed=cenqueue(s,&front,&rear,n,x);
				//printf("%d",rear);
				if(pushed == 0)
					break;
				else
					printf("element pushed\n");

				j++;
			}
		}

		else if(choice == 2){
			while(1){
				poped=cdequeue(s,&front,&rear);

				if(poped == 0)
					break;
				else
					printf("\nelement popped:%d\n",poped);
				
			}
		}
		else if(choice == 3){
			display(s,&front,&rear,n);
		}
		else if(choice == -1){
			break;
		}
	}
}
