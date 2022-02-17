#include<stdio.h>


int push(int a[],int *t, int e,int n){
	if(*t <n){
		*t=*t+1;
		a[*t]=e;
		return 1;
	}
	else{
		printf("overflow\n");
		return 0;
	}
}

int pop(int a[],int *t){
	if(*t == 0){
		printf("\nunderflowed\n");
		return 0;
	}
	else{
		*t=*t-1;
		return a[*t+1];
	}
}


int peep(int a[],int *t, int i){ 			////with reference to TOP
	if((*t-i+1) == 0){
		printf("\nElement underflowed\n");
		return 0;
	}

	else
		return a[*t-i+1];
}

int change(int a[],int *t, int i,int x){		//// With refference to TOP
	if((*t-i+1) == 0){
		printf("\nElement  underflowed\n");
		return 0;
	}

	else{
		a[*t-i+1]=x;
		return a[*t-i+1];
	}
}

void display(int a[],int lim){
	for(int i=lim;i>=1;i--){
		printf("%d\t",a[i]);	
	}
}

void main(){

int top=0,n=3,x,s[n+1];
int pushed,poped;
int choice;
	while(1){
		printf("\nEnter choice: 1 to push,2 to pop,3 to peep,4 to change,5 to display,-1 to Terminate: ");
		scanf("%d",&choice);

		if(choice ==1){	
			while(1){
				int x;
				printf("enter element to be pushed:");
				scanf("%d",&x);

				pushed=push(s,&top,x,n);
			
				if(pushed == 0)
					break;
				else
					printf("element pushed\n");
			}
			
			//for(int i=n;i>=1;i--){
			//	printf("%d",s[i]);
			//}
			
		}

		if(choice == 2){
			//for(int i=n;i>=1;i--){ //before poping
			//	printf("%d",s[i]);
			//}

			while(1){
				poped=pop(s,&top);
				if(poped == 0)
					break;
				else
					printf("\nelement popped\n");
				
			}
			//for(int i=n;i>=1;i--){
			//	printf("%d",s[i]);
			//}
		}

		if(choice == 3){
			int p;
			printf("which element:");
			scanf("%d",&p);
			printf("peeped: %d\n",peep(s,&top,p)); //peeps pth element
			//for(int i=n;i>=1;i--){
			//	printf("%d",s[i]);
			//}
		}

		if(choice ==4){
			int p;
			printf("which element:");
			scanf("%d",&p);
			int c;
			printf("To which value:");
			scanf("%d",&c);
			printf("changed: %d\n",change(s,&top,p,c));//changes pth ele to c
			//for(int i=n;i>=1;i--){
			//	printf("%d",s[i]);
			//}
		}

		if(choice == 5){
			display(s,n);
		}

		
		if(choice == -1){break;}
	}
}
