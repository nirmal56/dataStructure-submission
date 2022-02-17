#include<stdio.h>
#include<string.h>
#include"stackFun.h"

int main(){
	int flag=0,pushed=1;
	int top=0,x,n=10;
	//int j;
	int len;
 
	char a[n];
	char s[n];
	char popped;

	//pushc(s,&top, 'e' ,n);
        //displayc(s,n);
	//printf("%d",top);

	printf("Enter String:");
	scanf("%s",a);

	len=strlen(a);
	
	for(int i=0;i<len;i++){
		/*if(a[i] != 'c' && pushed != 0){
			pushed=pushc(s,&top,a[i],n);
			j++;
		}*/

		pushc(s,&top,a[i],n);
	}
	//displayc(s,n);
	//printf("\n");
	//popc(s,&top);
	//printf("%d",top);
	//j=5;
	for(int i = 0; i < len; i++){
		//printf("arr:%c %d\t",a[i],i+1);
		//if(j>=1){

			popped=popc(s,&top);

			//j--;
			//printf("j=%d",j);
		//}
		//printf("popped:%c",popped);
		//printf("%d",top);

        	if(popped != a[i]) {
          	  printf("Not a Palindrome String\n");
           	  return 0;
       		 }
   	 }
 
    printf("Palindrome String\n");
	return 0;
}	
