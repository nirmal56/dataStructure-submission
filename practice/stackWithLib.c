#include<stdio.h>
#include"stackFun.h"

void main(){

int top=0,n=3,x,s[n+1];
int pushed,poped;
int choice;
char s1[n+1];
	while(1){
		printf("\nEnter choice: 1 to push,2 to pop,3 to peep,4 to change,5 to display\n6 to pushc,7 to popc,8 to to peepc,9 to changec,10 to displayc,-1 to Terminate: ");
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
		}

		if(choice == 2){
			while(1){
				poped=pop(s,&top);

				if(poped == 0)
					break;
				else
					printf("\nelement popped\n");
				
			}
		}

		if(choice == 3){
			int p;
			printf("which element:");
			scanf("%d",&p);
			printf("peeped: %d\n",peep(s,&top,p)); //peeps pth element
		}

		if(choice ==4){
			int p;
			printf("which element:");
			scanf("%d",&p);
			int c;
			printf("To which value:");
			scanf("%d",&c);
			printf("changed: %d\n",change(s,&top,p,c));//changes pth ele to c
		}

		if(choice == 5){
			display(s,n);
		}

		if(choice ==6){	
			while(1){
				char x;
				printf("enter element to be pushed:");
				scanf("%c",&x);
				if(x!=10)
				pushed=pushc(s1,&top,x,n);
			
				if(pushed == 0)
					break;
				else
					printf("element pushed\n");
			}			
		}

		if(choice == 7){
			char popped;
			while(1){
				popped=popc(s1,&top);
				if(popped == '0')
					break;
				else
					printf("\nelement popped\n");
				
			}
		}

		if(choice == 8){
			int p;char peepd;
			printf("which element:");
			scanf("\n%d",&p);
			peepd=peepc(s1,&top,p);
			printf("peeped: %c",peepd); //peeps pth element
		}

		if(choice ==9){
			int p;
			printf("which element:");
			scanf("%d",&p);
			char c;
			printf("To which value:");
			scanf("%c",&c);
			while(c==10)
				scanf("%c",&c);
			printf("changed: %c\n",changec(s1,&top,p,c));//changes pth ele to c
		}

		if(choice == 10){
			displayc(s1,n);
		}

		
		if(choice == -1){
			break;
		}
	}
	
}
