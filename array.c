//C program to display elements of array
#include<stdio.h>
int main(){
    int a[5] = {6, 12, 7, 1, 9};
    printf("The numbers in array are: ");
    for(int i=0;i<=4;i++){
    printf( " %d", a[i]);
    }
    return 0;
}