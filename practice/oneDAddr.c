/*
1.calculation of address of element in 1d array 
input:bas e address and index of i
output:address of elemnt
*/


#include<stdio.h>


void main(){
	int baseAdd,ind;
	int ans;
	printf("enter base addr and index of which you want to addr:");
	scanf("%d %d",&baseAdd,&ind);
	
	ans=baseAdd+sizeof(int)*(ind-1);
	printf("ans=%d",ans);
	}

