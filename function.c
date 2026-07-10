//addition of two number using function in c
#include<stdio.h>
void sum(int a, int b){
    int total;
    total = a + b;
    printf("\nThe sum is: %d", total);
}
void sub(int a, int b){
    int dif;
    dif = a - b;
    printf("\nThe difference is: %d", dif);
}
int mul(int a, int b){
    int pro;
    pro = a * b;
    printf("\nThe product is: %d", pro);
}
void main(){
    int a, b;
    printf("Enter a and b: ");
    scanf("%d %d", &a, &b);
    sum(a,b);
    sub(a,b);
    mul(a,b);
}
