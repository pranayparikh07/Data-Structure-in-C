#include<stdio.h>
int main(){
    int a[10], sum=0;
    for(int i=0;i<=10;i++){
        printf("Enter element for a[%d]: ", i);
        scanf("%d",&a[i]);
        sum += a[i];
    }
    printf("The sum of all 10 values is: %d\n", sum);
    return 0;
}