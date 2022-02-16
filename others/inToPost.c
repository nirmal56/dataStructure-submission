#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include"stackFun.h"
//A+B-C*D+E-F/G
char s[100];
char ep[20];
char *p,x;
char ans[20];
int n;

int priority(char x){
    if( x == '(' )
        return 0;
    if( x == '+' || x == '-' )
        return 1;
    if( x == '*' || x == '/' )
        return 2;
    return 0;
}


void main(){
	int top=0;
	printf("enter expression:");
	scanf("%s",ep);
	n=strlen(ep);
	p=ep;
	while(*p != '\0'){
		if(isalpha(*p)){
			printf("%c",*p);
		}

		else if(*p == '('){
		    pushc(s,&top,*p,n);
		}

		else if(*p == ')'){
		    while((x = popc(s,&top)) != '(')
		        printf("%c ", x);
		}

		else{
		    while(priority(s[top]) >= priority(*p))
		        printf("%c ",popc(s,&top));
		    pushc(s,&top,*p,n);
		}
		p++;
	}
    
	while(top > 0)
	{
	printf("%c ",popc(s,&top));
	}		
}
