#include <stdio.h>
int main() {
    int size=4;
    int maxRow=0,maxCol=0;
    int disp[3][4] = {{0, 1, 2, 2},{2, 0, 0,1},{1,2,2,2}};
    
    for(int j=0;j<size;j++){
            if(maxRow<disp[0][j]){
                maxRow=disp[0][j];
            }
            if(maxCol < disp[1][j])
            {
                maxCol=disp[1][j];
            }
    }
    int ans[maxRow+1][maxCol+1];
    
    for(int i=0;i<maxRow+1;i++)
    {
        for(int j=0;j<maxCol+1;j++)
        {
            ans[i][j]=0;
        }
    }
    
    for(int j=0;j<size;j++)
    {
        ans[ disp[0][j] ][ disp[1][j] ]= disp[2][j];
    }
    
    for(int i=0;i<maxRow+1;i++)
        {
            for(int j=0;j<maxCol+1;j++)
            {
                printf("%d ",ans[i][j]);
            }
            printf("\n");
        }
    return 0;
}

/*
001
200
220



0 1 2 2 
2 0 0 1 
1 2 2 2 */
