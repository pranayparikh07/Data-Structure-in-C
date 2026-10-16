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
 
    // Bubble Sort Logic
    for(i = 0; i < n - 1; i++)  // Number of passes
    {
        for(j = 0; j < n - i - 1; j++)  // Compare adjacent elements
        {
            if(a[j] > a[j + 1])  // If in wrong order
            {
                temp = a[j];          // Swap a[j] and a[j+1]
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
 
    printf("Sorted array in ascending order:\n");
    for(i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
 

}
