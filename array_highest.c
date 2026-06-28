//A program to display greatest number in an array
#include<stdio.h>
int main(){
    int a[5], max;
    for(int i=0;i<5;i++){
        printf("Enter element for a[%d]: ", i);
        scanf("%d",&a[i]);
    }
    max = a[0];
    for(int i=1;i<5;i++){
        if(a[i] > max){
            max = a[i];
            
        }
    }
    printf("The highest number in the array is: %d\n", max);
    return 0;   
}