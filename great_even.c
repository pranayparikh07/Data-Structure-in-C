#include<stdio.h>
int even(int a, int b){
    int i;
    printf("Even numbers between %d and %d are: ", a, b);
    for(i=a; i<=b; i++){
        if(i%2==0){
            printf("%d ", i);
        }
    }
}
int great(int a, int b){
    if(a>b){
        printf("\n%d is greater than %d\n", a, b);
    }
    else if(b>a){
        printf("\n%d is greater than %d\n", b, a);
    }
    else{
        printf("\nBoth numbers are equal\n");
    }
}
int main(){
    int a, b, choice;
    printf(" 1. Even Check\n 2. Greatest of Two\n Select Choice:");
    scanf("%d", &choice);
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);
    switch(choice){
        case 1: 
            even(a, b);
            break;
        case 2:
            great(a, b);
            break;
    }
    return 0;
}