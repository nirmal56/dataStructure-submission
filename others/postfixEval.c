#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include"stackFun.h"

char s[100];
char ep[20];
char *p,x;
char ans[20];

int n2,n1,n3;
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
	int top=0,top1=0,n;
	printf("enter expression:");
	scanf("%s",ep);
	n=strlen(ep);
	p=ep;
	while(*p != '\0'){
		if(isalnum(*p)){
			*p=*p-'0';	
			pushc(s,&top,*p,n);
		}
		else if(*p == '/'||*p == '*'||*p == '+'||*p == '-'||*p == '^'){
			n1=popc(s,&top);
			n1-='0';
			n2=popc(s,&top);
			n2-='0';
			switch(*p){
				case '+':{
                			n3 = n1 + n2;
                			break;
            			}
            			case '-':{
               				n3 = n2 - n1;
                			break;
            			}
            			case '*':{
               			 	n3 = n1 * n2;
            			        break;
           			}
				case '/':{
					n3 = n2 / n1;
					break;
				}
			}
			
			n3+='0';
			pushc(s,&top,n3,n);
		}
		p++;
	}
	printf("\nThe result of expression =  %d",popc(s,&top));
}
