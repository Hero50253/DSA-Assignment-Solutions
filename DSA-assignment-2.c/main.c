#include<stdio.h>

int main() {
    int arr[50];
    int n, search, i;
    int low, high, mid;
    int flag = 0;
    
    printf("enter number of elements: ");
    scanf("%d", &n);
    
    printf("enter sorted numbers: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("enter number to search: ");
    scanf("%d", &search);
    
    // binary search starts here
    low = 0;
    high = n - 1;
    
    while(low <= high) {
        mid = (low + high) / 2;
        
        if(arr[mid] == search) {
            printf("number found at position %d\n", mid);
            flag = 1;
            break;
        }
        
        if(arr[mid] < search) {
            low = mid + 1;
        }
        else {
            high = mid - 1; 
        }
    }
    
    if(flag == 0) {
        printf("number not found\n");
    }
    
    printf("your array was: ");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    
    return 0;
}
