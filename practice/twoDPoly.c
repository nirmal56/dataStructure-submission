/*
3.polynomial representation using 2d array.
input:
0<x,y<3 degree//3x3 matrix

p(x)=x^2+3xy+y^2+y-x
q(x)=2x^2+5xy+y^2

output=p+q,p-q,number n*p;

   0y 1y  2y
0x 1  y   y2
1x x  xy  xy2
2x x2 x2y x2y2

*/

#include<stdio.h>
#include<string.h>



int mul;
int p[3][3]={};
int q[3][3]={};
int ans[3][3]={};


void main(){
	
	for (int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			printf("enter x^%dy^%d for P(x):",i,j);
			scanf("%d",&p[i][j]);
		}
	}

	printf("\n");
	
	printf("P(x): ");
	for (int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			if(p[i][j] != 0){
				printf("%dx^%dy^%d+",p[i][j],i,j);
			}
		}
	}
	
	printf("\n");

	for (int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			printf("enter x^%dy^%d for Q(x):",i,j);
			scanf("%d",&q[i][j]);
		}
	}

	printf("\n");

	printf("Q(x): ");
	for (int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			if(q[i][j] != 0){
				printf("%dx^%dy^%d+",q[i][j],i,j);
			}
		}
	}

	printf("\n");

	printf("sumation of poly: ");
	for (int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			ans[i][j]=p[i][j]+q[i][j];
			if(ans[i][j] != 0){
				printf("%dx^%dy^%d+",ans[i][j],i,j);
			}
		}
	}

	printf("\n");
	
	printf("sub of poly: ");
	for (int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			ans[i][j]=p[i][j]-q[i][j];
			if(ans[i][j] != 0){
				printf("%dx^%dy^%d+",ans[i][j],i,j);
			}
		}
	}

	printf("\n");
	
	printf("enter multiplier for p");
	scanf("%d",&mul);
	printf("mul of poly with %d:",mul);
	for (int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			ans[i][j]=p[i][j]*mul;
			if(ans[i][j] != 0){
				printf("%dx^%dy^%d+",ans[i][j],i,j);
			}
		}
	}

	printf("\n");


	
}
