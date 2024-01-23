#include "sort.h"
/**
 * selection_sort - Sorts  an array of integers in ascending order
 * using the Selection sort algorithm
 * @array: The array to sort
 * @size: the size of the array
 * Return: Nothing
*/

void selection_sort(int *array, size_t size)
{
	unsigned int i, j, pos, b = 0;
	int min;

	if (!array || size < 2)
		return;

	for (i = 0; i < (size - 1); i++)
	{
		min = array[i];
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < min)
			{
				min = array[j];
				pos = j;
				b = 1;
			}
		}
		if (b)
		{
			array[pos] = array[i];
			array[i] = min;
			print_array(array, size);
			b = 0;
		}
	}
}
