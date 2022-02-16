/*
 sperse matrix and vice versa
*/

#include<stdio.h>
 
int main(){
int m,n;
int size = 0;

	/*int sparseMatrix[5][5] ={	{0 , 0 , 3 , 0 , 4 },
					{0 , 0 , 5 , 7 , 0 },
					{0 , 0 , 0 , 0 , 0 },
					{0 , 2 , 6 , 0 , 0 },
				};
 	*/

	int sparseMatrix[5][5]={};

	printf("enter rows and cols:");
	scanf("%d %d",&m,&n);

	for (int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			scanf("%d",&sparseMatrix[i][j]);
		}
	}

	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
			if (sparseMatrix[i][j] != 0){
				size++;
 			}
		}
	}

	int compactMatrix[3][size];
 

	int k = 0;
	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
			if (sparseMatrix[i][j] != 0){
				compactMatrix[0][k] = i;
				compactMatrix[1][k] = j;
				compactMatrix[2][k] = sparseMatrix[i][j];
				k++;
			}
		}
	}
 
	for (int i=0; i<3; i++){
		for (int j=0; j<size; j++){
			printf("%d ", compactMatrix[i][j]);
		}
		printf("\n");
	}
	return 0;
}

/*

001
200
220

enter rows and cols:3 3
0
0
1
2
0
0
2 
2
0

0 1 2 2 
2 0 0 1 
1 2 2 2 

*/
