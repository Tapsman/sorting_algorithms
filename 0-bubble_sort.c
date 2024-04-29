#include "sort.h"
/**
 * bubble_sort - Function that sorts an array of integers
 * in ascending order
 * @array: Is the array of the integers
 * @size: Size of the array
 */
void bubble_sort(int *array, size_t size)
{
	int temp;
	size_t i, k;

	if (!array || !size)
		return;

	i = 0;
	while (i < size)
	{
		for (k = 0 ; k < size - 1 ; k++)
		{
			if (array[k] > array[k + 1])
			{
				temp = array[k];
				array[k] = array[k + 1];
				array[k + 1] = temp;
				print_array(array, size);
			}
		}
		i++;
	}
}
