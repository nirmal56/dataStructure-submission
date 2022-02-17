#include<stdio.h>
#include<string.h>
#include"stackFun.h"

int main(){
	int flag=0;
	int top=0,n=10;
	int len,j=0;
	int cha=0,chb=0;

	char *e;
	char a[n];
	char s[n];
	char popped;

	printf("Enter String:");
	scanf("%s",a);

	len=strlen(a);
	e=a;
	
	for(int i=0;i<len;i++){
		if(a[i] != 'b'){
			pushc(s,&top,a[i],n);
			j++;
			printf("%c %d",a[i],j);	
		}
	}

	for(int i=j;i<len;i++){
		if(a[i] != 'b'){
			flag=1;
			break;
		}
		//else if(len-j+1 < j){
		//	flag=1;
		//	break;
		//}
		else{
			flag=0;
		}
	}
	
	if(flag == 0){
		printf(" Valid");
	}

	
	else if(flag == 1){
		printf(" NOT Valid");
	}
	return 0;
}
