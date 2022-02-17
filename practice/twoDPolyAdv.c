/*

3.polynomial representation using 2d array.
input:
0<x,y<3 degree//3x3 matrix

p(x)=1x^2+3xy+1y^2+1y-1x
q(x)=2x^2+5xy+1y^2

output=p+q,p-q,number n*p;

   0y 1y  2y
0x 1  y   y2
1x x  xy  xy2
2x x2 x2y x2y2

*/

#include<stdio.h>
#include<string.h>
#include<ctype.h>


int mul;
int p[3][3]={};
int q[3][3]={};
int ans[3][3]={};
int len=0;

char px[100]={};
char qx[100]={};

void main(){
	printf("Enter polynomial:");
	scanf("%s",px);
	len=strlen(px);
	for(int i=0;i<len;i++){
		if(isdigit(px[i])){
			if(px[i+1] == 'x'){
				if(px[i+2] == '^'){
					if(px[i+3] == '2'){
						p[2][0]=px[i]-48;
						if(px[i-1] == '-'){
							p[2][0] *= (-1);						
						}
					}			
				}	
			}
		}	
		
		if(isdigit(px[i])){
			if(px[i+1] == 'y'){
				if(px[i+2] == '^'){
					if(px[i+3] == '2'){
						p[0][2]=px[i]-48;
						if(px[i-1] == '-'){
							p[0][2] *= (-1);						
						}
					}			
				}	
			}
		}

		if(isdigit(px[i])){
			if(px[i+1] == 'x'){
				if(px[i+2] =='y'){
					p[1][1]=px[i]-48;
					if(px[i-1] == '-'){
						p[1][1] *= (-1);						
					}
				}	
			}
		}	
		
		if(isdigit(px[i])){
			if(px[i+1] == 'x'){
				if(px[i+2] == '+'){
					p[1][0]=px[i]-48;
					if(px[i-1] == '-'){
						p[1][0] *= (-1);						
					}		
				}	
			}
		}

		
		if(isdigit(px[i])){
			if(px[i+1] == 'y'){
				if(px[i+2] == '+'){
					p[0][1]=px[i]-48;
					if(px[i-1] == '-'){
						p[0][2] *= (-1);						
					}		
				}	
			}
		}
	}
	for(int i=0; i<3; i++){
		for(int j=0;j<3;j++){
			printf("%d\t",p[i][j]);
		}
		printf("\n");
	}
}
