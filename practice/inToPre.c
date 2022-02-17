#include<stdio.h>
#include<ctype.h>
#include<string.h>
//A+B-C*D+E-F/G
char s[100];
char ep[20];
char *p,x;
char ans[20];
char temp[20];
int n;

int pushc(char a[],int *t, char e,int n){
	if(*t <n){
		*t=*t+1;
		a[*t]=e;
		return 1;
	}
	else if(*t==n || *t>n){
		printf("overflow");
		return 0;
	}
}

char popc(char a[],int *t){
	if(*t == 0){
		printf("underflowed");
		return '0';
	}
	else{
		*t=*t-1;
		return a[*t+1];
	}
}
void displayc(char a[],int lim){
	for(int i=lim;i>=1;i--){
		printf("%c",a[i]);	
	}
}

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
	int j=n-1;
	for(int i=0;i<n;i++){
		temp[i]=ep[n-i-1];
	}
	for(int i=0;i<n;i++){
		if(temp[i] == ')'){
			temp[i]='(';
		}
		else if(temp[i] == '('){
			temp[i]=')';
		}		
	}
	printf("%s\n",temp);
	p=temp;
	while(*p != '\0'){
		if(isalpha(*p)){
			ans[j]=*p;
			j--;
			//pushc(ans,&top1,*p,n);
		}

		else if(*p == '('){
		    pushc(s,&top,*p,n);
		}

		else if(*p == ')'){
		    while((x = popc(s,&top)) != '('){
		        //printf("%c ", x);
		        ans[j]=x;
		        j--;
		        //pushc(ans,&top1,x,n);
		     }
		}

		else{
		    while(priority(s[top]) >= priority(*p)){
		        //printf("%c ",popc(s,&top));
		        ans[j]=popc(s,&top);
		        j--;
		        //pushc(ans,&top1,popc(s,&top),n);
		    }
		    pushc(s,&top,*p,n);
		}
		p++;
	}
    
	while(top > 0)
	{
		//printf("%c ",popc(s,&top));
		ans[j]=popc(s,&top);
		j--;
		//pushc(ans,&top1,popc(s,&top),n);
	}		
	for(int i=0;i<n;i++){
	printf("%c",ans[i]);
	}
}
