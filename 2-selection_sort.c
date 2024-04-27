#include "sort.h"

/**
 * selection_sort - function that sorts an array of integers
 *  in ascending order using the Selection sort algorithm
 * @array: int * (array to sort)
 * @size: size_t (size of the array)
*/

void selection_sort(int *array, size_t size)
{
	size_t i;
	size_t j;
	size_t min;
	int temp;

	for (i = 0; i < (size - 1); i++)
	{
		min = i;
		for (j = i + 1; j < (size); j++)
		{
			if (array[j] < array[min])
			{
				min = j;
				temp = array[min];
				array[min] = array[i];
				array[i] = temp;

				print_array(array, size);
			}
		}
	}
}