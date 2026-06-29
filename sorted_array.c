#include <stdio.h>

int main(void)
{
	int arr[5] = {2, 1, 4, 3, 8};
	int i, j, temp;

	for (i = 0; i < 4; i++)
	{
		for (j = i + 1; j < 5; j++)
		{
			if (arr[i] > arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}

	for (i = 0; i < 5; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

	return 0;
}
