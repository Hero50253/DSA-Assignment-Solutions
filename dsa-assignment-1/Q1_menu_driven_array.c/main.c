#include<stdio.h>

int a[100];  // simple array name
int n=0;     // size variable

void create(){
    printf("enter size: ");
    scanf("%d",&n);
    printf("enter elements: ");
    int i;
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("array created\n");
}

void show(){
    if(n==0){
        printf("empty array\n");
        return;
    }
    printf("elements are: ");
    int i;
    for(i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
}

void add(){
    int pos,val,i;
    printf("enter position: ");
    scanf("%d",&pos);
    printf("enter value: ");
    scanf("%d",&val);
    
    // shift elements
    for(i=n;i>pos;i--){
        a[i]=a[i-1];
    }
    a[pos]=val;
    n++;
    printf("inserted\n");
}

void del(){
    int pos,i;
    printf("enter position: ");
    scanf("%d",&pos);
    
    // move elements left
    for(i=pos;i<n-1;i++){
        a[i]=a[i+1];
    }
    n--;
    printf("deleted\n");
}

void search(){
    int x,i,flag=0;
    printf("enter element to search: ");
    scanf("%d",&x);
    
    for(i=0;i<n;i++){
        if(a[i]==x){
            printf("found at position %d\n",i);
            flag=1;
            break;
        }
    }
    if(flag==0){
        printf("not found\n");
    }
}

int main(){
    int choice;
    
    while(1){
        printf("\n1.CREATE\n2.DISPLAY\n3.INSERT\n4.DELETE\n5.LINEAR SEARCH\n6.EXIT\n");
        printf("enter choice: ");
        scanf("%d",&choice);
        
        if(choice==1) create();
        else if(choice==2) show();
        else if(choice==3) add();
        else if(choice==4) del();
        else if(choice==5) search();
        else if(choice==6) break;
        else printf("wrong choice\n");
    }
    return 0;
}
