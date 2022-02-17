/*
2.calculation of address of elements in 2d array 
input:bas e address total row cols ,index i/j, roq/col/major
output:address of elemnt

*/
#include<stdio.h>


void main(){
	int baseAdd,i,j,m,n,specifier;
	int ans;
	printf("Enter rows and cols of matrix:");
	scanf("%d %d",&m,&n);
	printf("enter 1 for row major,2 for col major:");
	scanf("%d",&specifier);
	printf("enter row and column of address to found:");
	scanf("%d %d",&i,&j);
	printf("enter baseaddres:");
	scanf("%d",&baseAdd);

	if(specifier == 1){
		ans=baseAdd+(((i-1)*m)+(j-1))*sizeof(int);
		printf("ans=%d",ans);
	}
	else if(specifier == 2){
		ans=baseAdd+(((j-1)*n)+(i-1))*sizeof(int);
		printf("ans=%d",ans);
	}
}

