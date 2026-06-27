//C program for addtion of numbers 1 to 30 only even
#include <stdio.h>
int main()
{
    int i, sum = 0;
    for (i=1; i<=30; i++)
    {
        if(i%2==0)
        {
            sum += i;
        }

    }
    printf("Sum of even numbers from 1 to 30 is: %d", sum);
    return 0;
}