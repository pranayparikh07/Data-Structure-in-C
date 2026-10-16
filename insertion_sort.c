#include <stdio.h>

void main()
{
    int a[100], n, i, j, temp;


    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    // Insertion Sort Logic
    for(i = 1; i < n; i++)  // Start from the second element
    {
        temp = a[i];  // Element to be inserted
        j = i - 1;

        // Shift elements of a[0..i-1] that are greater than temp
        while(j >= 0 && a[j] > temp)
        {
            a[j + 1] = a[j];
            j--;
        }
        
        // Insert temp at its correct position
        a[j + 1] = temp;
    }

    printf("\nSorted array in ascending order:\n");
    for(i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    
}
