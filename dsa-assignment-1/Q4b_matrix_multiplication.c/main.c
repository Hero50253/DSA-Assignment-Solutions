#include<stdio.h>

int main(){
    int mat1[10][10], mat2[10][10], result[10][10];
    int r1,c1,r2,c2,i,j,k;
    
    printf("enter rows and cols of matrix 1: ");
    scanf("%d %d",&r1,&c1);
    printf("enter rows and cols of matrix 2: ");
    scanf("%d %d",&r2,&c2);
    
    if(c1!=r2){
        printf("multiplication not possible\n");
        return 0;
    }
    
    printf("enter matrix 1:\n");
    for(i=0;i<r1;i++){
        for(j=0;j<c1;j++){
            scanf("%d",&mat1[i][j]);
        }
    }
    
    printf("enter matrix 2:\n");
    for(i=0;i<r2;i++){
        for(j=0;j<c2;j++){
            scanf("%d",&mat2[i][j]);
        }
    }
    
    // multiplication
    for(i=0;i<r1;i++){
        for(j=0;j<c2;j++){
            result[i][j]=0;
            for(k=0;k<c1;k++){
                result[i][j] = result[i][j] + mat1[i][k]*mat2[k][j];
            }
        }
    }
    
    printf("result:\n");
    for(i=0;i<r1;i++){
        for(j=0;j<c2;j++){
            printf("%d ",result[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
