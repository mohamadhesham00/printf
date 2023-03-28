#include "main.h"
/**
 * turn_to_bin - to turn an int number to binary
 * @n - number to be turned into
 * Return - void
 */
void turn_to_bin(int n)
{
	int i, j;
	int arr[33];

	i=0;
	while (n > 0)
	{
		arr[i] = (n % 2);
		n /= 2;
		i++;
	}
	for (j = i - 1; j >= 0; j--)
		printf("%d", arr[j]);
}

