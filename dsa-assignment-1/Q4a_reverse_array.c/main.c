#include<stdio.h>

int main(){
    int arr[20];
    int size,i,temp;
    
    printf("enter size: ");
    scanf("%d",&size);
    
    printf("enter elements: ");
    for(i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }
    
    // reverse logic
    int start=0, end=size-1;
    while(start<end){
        temp=arr[start];
        arr[start]=arr[end];
        arr[end]=temp;
        start++;
        end--;
    }
    
    printf("reversed array: ");
    for(i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    
    return 0;
}
