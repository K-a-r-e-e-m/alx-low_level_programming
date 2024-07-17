#include "search_algos.h"
#include <math.h>

/**
 * binary_search - Search for value in list of numbers
 * @array: pointer to the first element of the array
 * @size: number of elements in array
 * @value: value to search for
 * Return: Index of value or -1 when not founc or array is NULL
 */
int binary_search(int *array, size_t size, int value)
{
	size_t l, r;
	int m;

	if (!array)
		return (-1);

	/* l ==> left  ...  r ==> right ...  m ==> middle */
	l = 0;
	r = size - 1;
	print_array(array, l, r);
	while (l <= r)
	{
		/*Floor used to convert the floating point number
		  to smaller integar eg: 3.6 ==> 3 */
		m = floor((l + r) / 2);
		if (array[m] < value)
		{
			l = m + 1;
			print_array(array, l, r);
		}
		else if (array[m] > value)
		{
			r = m  - 1;
			print_array(array, l, r);
		}
		else
			return (m);
	}
	return (-1);
}

/**
 * print_array - print array every time it changes
 * @array: pointer to the first element of the array
 * @start: start index of array or subarray = l
 * @end: last index of array or subarray = r
 */
void print_array(int *array, size_t start, size_t end)
{
	size_t i;

	printf("Searching in array: ");
	for (i = start; i <= end; i++)
	{
		if (i < end)
			printf("%d, ", array[i]);
		else
			printf("%d", array[i]);
	}
	printf("\n");
}
