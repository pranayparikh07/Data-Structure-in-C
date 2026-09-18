//in one function read and write in array
#include <stdio.h>
void read_write_array(int arr[], int size) {

    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    
    printf("You entered:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void main(){
    int arr[5];

    read_write_array(arr, 5); 
}