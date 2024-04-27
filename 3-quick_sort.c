#include "sort.h"

/**
 * swap - function to swap two integers
 * @a: int * (pointer to the first integer)
 * @b: int * (pointer to the second integer)
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * lomuto_partition - Lomuto partition scheme for Quick sort
 * @array: int * (array to be partitioned)
 * @first: int (starting index of the partition)
 * @last: int (ending index of the partition)
 * @size: size_t (size of the array)
 * Return: int (partition index)
 */
int lomuto_partition(int *array, int first, int last, size_t size)
{
	int pivot = array[last];
	int i = first - 1;
	int j;

	for (j = first; j <= last - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			swap(&array[i], &array[j]);
			print_array(array, size);
		}
	}
	swap(&array[i + 1], &array[last]);
	print_array(array, size);
	return (i + 1);
}

/**
 * quick_sort_helper - recursive function to perform Quick sort
 * @array: int * (array to be sorted)
 * @first: int (starting index of the partition)
 * @last: int (ending index of the partition)
 * @size: size_t (size of the array)
 */
void quick_sort_helper(int *array, int first, int last, size_t size)
{
	int pi;

	if (first < last)
	{
		pi = lomuto_partition(array, first, last, size);
		quick_sort_helper(array, first, pi - 1, size);
		quick_sort_helper(array, pi + 1, last, size);
	}
}

/**
 * quick_sort - function that sorts an array of integers
 * in ascending order using the Quick sort algorithm
 * @array: int * (the array to sort)
 * @size: size_t (the size of array to sort)
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_helper(array, 0, size - 1, size);
}
