#include "sort.h"
/**
 * swap - Swaps 2 integer values
 * @array: The integer of the array to be sorted
 * @size: Is the size of the array
 * @a: The first address of the value
 * @b: The second address of the value
 * Return: void
 */
void swap(int *array, size_t size, int *a, int *b)
{
	if (*a != *b)
	{
		*a = *a + *b;
		*b = *a - *b;
		*a = *a - *b;
		print_array((const int *)array, size);
	}
}
/**
 * lomuto_partition - The function will the partition the array
 * @array: The integer of the array to be sorted
 * @size: Is the size of the array
 * @lo: Is low index of sort range
 * @hi: Is high index of sort range
 * Return: size_t
 */
size_t lomuto_partition(int *array, size_t size, ssize_t lo, ssize_t hi)
{
	int i, j, pivot = array[hi];

	for (i = j = lo ; j < hi ; j++)
		if (array[j] < pivot)
			swap(array, size, &array[j], &array[i++]);
	swap(array, size, &array[i], &array[hi]);

	return (i);
}

/**
 * quicksort - quicksorts through lomuto partition
 * @array: The integer of the array to be sorted
 * @size: Is the size of the array
 * @lo: Is low index of sort range
 * @hi: Is high index of sort range
 * Return: void
 */
void quicksort(int *array, size_t size, ssize_t lo, ssize_t hi)
{
	if (lo < hi)
	{
		size_t p = lomuto_partition(array, size, lo, hi);

		quicksort(array, size, lo, p - 1);
		quicksort(array, size, p + 1, hi);
	}
}

/**
 * quick_sort - The function that will call the quicksort
 * @array: The integer of the array to be sorted
 * @size: Is the size of the array
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (!array || !size)
		return;
	quicksort(array, size, 0, size - 1);
}
