#include <stdio.h>

 
void main()
{
    int a[100], n, i, j, min, temp;
 
 
    printf("Enter number of elements: ");
    scanf("%d", &n);
 
    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
 
    // Selection Sort Logic
    for(i = 0; i < n - 1; i++)  // Passes
    {
        min = i;  // Assume current index is minimum
        for(j = i + 1; j < n; j++)  // Find smallest in remaining array
        {
            if(a[j] < a[min])
            {
                min = j;  // Update index of minimum element
            }
        }
 
        // Swap if min is not the current index
        if(min != i)
        {
            temp = a[i];
            a[i] = a[min];
            a[min] = temp;
        }
    }
 
    printf("\nSorted array in ascending order:\n");
    for(i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
 
    
}
