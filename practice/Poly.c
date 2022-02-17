#include <string.h>
#include <stdio.h>

void stringToMatrixx(char a[],int ans[3][3])
{
        int multiplyer=1;
         int i=0;
    int row=0,col=0;
    while(a[i]!=NULL){
        
        if(a[i]=='-' || a[i]=='+')
        {
            multiplyer=(int)a[i]==43?1:-1;
            i++;
        }
        else{
            int num=(int)a[i] - 48;
            i++;
            if(a[i]=='x' && a[i+1] == '^')//x sq  /// 1x^2+3xy+1y^2+1y-1x
            {
                row=2;
                col=0;
                i=i+3;
            }
            else if(a[i]=='x' && a[i+1] == 'y')//xy
            {
                row=1;
                col=1;
                i=i+2;
            }
            else if(a[i] == 'y' && a[i+1]=='^')// y sq
            {
                row=0;
                col=2;
                i=i+3;
            }
            else
            {
                if(a[i]=='x') { //x
                    row=1;
                    col=0;
                    i=i+1;
                }
                else      //y
                {
                    row=0;
                    col=1;
                    i=i+1;
                }
            }
           ans[row][col]=num*multiplyer; 
        }
    }
}
void printArray(int num[3][3]){
    for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                printf("%d ",num[i][j]);
            }
            printf("\n");
        }
}
int main() {
    char a[100]="1x^2+3xy+1y^2+1y-1x";
    char b[100]="2x^2+5xy+1y^2";
    int ans[3][3],ans2[3][3],sum[3][3],sub[3][3];
    for(int i=0;i<3;i++)
    {
            for(int j=0;j<3;j++)
            {
               ans[i][j]=0;
               ans2[i][j]=0;
	       sum[i][j]=0;
	       sub[i][j]=0;
            }
    }
    stringToMatrixx(a,ans);
    stringToMatrixx(b,ans2);
    
	for (int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			sum[i][j]=ans[i][j]+ans2[i][j];
		}
	}

    	
	for (int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			sub[i][j]=ans[i][j]-ans2[i][j];
		}
	}

    	printf("a poly: \n");
    			printArray(ans);
    	printf("b poly: \n");
    			printArray(ans2);
    	printf("sumation of poly: \n");
    			printArray(sum);
	printf("sub  of poly:\n ");
    			printArray(sub);
    return 0;
}
