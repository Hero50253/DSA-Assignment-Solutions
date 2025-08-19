#include<stdio.h>

int main(){
    int matrix[10][10];
    int rows,cols,i,j,sum;
    
    printf("enter number of rows and columns: ");
    scanf("%d %d",&rows,&cols);
    
    printf("enter matrix elements:\n");
    for(i=0;i<rows;i++){
        for(j=0;j<cols;j++){
            scanf("%d",&matrix[i][j]);
        }
    }
    
    printf("matrix is:\n");
    for(i=0;i<rows;i++){
        for(j=0;j<cols;j++){
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }
    
    // row sum
    printf("\nrow sums:\n");
    for(i=0;i<rows;i++){
        sum=0;
        for(j=0;j<cols;j++){
            sum = sum + matrix[i][j];
        }
        printf("row %d sum = %d\n",i+1,sum);
    }
    
    // column sum  
    printf("\ncolumn sums:\n");
    for(j=0;j<cols;j++){
        sum=0;
        for(i=0;i<rows;i++){
            sum = sum + matrix[i][j];
        }
        printf("column %d sum = %d\n",j+1,sum);
    }
    
    return 0;
}
