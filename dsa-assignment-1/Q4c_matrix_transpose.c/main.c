#include<stdio.h>

int main(){
    int mat[10], result;
    int row,col,i,j;
    
    printf("enter rows and columns: ");
    scanf("%d %d",&row,&col);
    
    printf("enter matrix elements:\n");
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            scanf("%d",&mat[i][j]);
        }
    }
    
    // transpose logic
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            result[j][i] = mat[i][j];
        }
    }
    
    printf("original matrix:\n");
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            printf("%d ",mat[i][j]);
        }
        printf("\n");
    }
    
    printf("transpose matrix:\n");
    for(i=0;i<col;i++){
        for(j=0;j<row;j++){
            printf("%d ",result[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
