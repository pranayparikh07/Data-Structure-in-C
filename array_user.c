//C program to take input from user for array
#include<stdio.h>
int main(){
    int a[5];
    for(int i=0;i<=4;i++){
        printf("Enter element for a[%d]: ", i);
        scanf("%d",&a[i]);
    }
    for(i=0;i<=4;i++){
        printf("The values in array are: %d\n", a[i]);
    }
    return 0;
}