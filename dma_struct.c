//create a structure with integer and pointer which points to data and in main function ask how many elements to enter from user, using for loop take elements to enter and use malloc to give memory in for loop and store elements in the structure and point to next data using pointer and print the elements using for loop.
#include <stdio.h>
#include <stdlib.h>
struct data {
    int d;
    struct data *next;
}*start = NULL, *tmp = NULL;

void main(){
    struct data *ptr;
    
    int n, i;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    for(i=0;i<n;i++){
       ptr = (struct data*)malloc(sizeof(struct data));
        if(start == NULL){
            start = ptr;
        }
        printf("Enter integer: ");
        scanf("%d", &ptr->d);
        ptr->next = NULL;
        if(tmp != NULL){
            tmp -> next = ptr;
        }
        tmp = ptr;

    }
   tmp = start;     

while(tmp != NULL){
    printf("%d ", tmp->d);
    tmp = tmp->next;
}

}