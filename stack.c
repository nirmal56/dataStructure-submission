#include<stdio.h>

int s[11],top=0,n=11;
int pushed;
int isFull(){

	if (top==n){
		return 1;
	}
	
	else {
		return 0;
	}
}

int push(int x){
	if(isFull() == 0){
		top= top+1;
		s[top]=x;
		return 1;
	}
	else{
		printf("overflowed");
		return 0;
	}
}

void display(){
	for(int i=10;i>=1;i--){
		printf("%d\t",s[i]);	
	}
}

void main(){
	while(1){
		int x;
		printf("enter element to be pushed:");
		scanf("%d",&x);

		pushed=push(x);
		display();
		
		if(pushed == 0)
			break;
		else
			printf("element pushed\n");
	
	}
}
