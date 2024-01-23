#include "sort.h"
/**
 * bubble_sort - Sorts an array of integers in ascending order
 * using the Bubble sort algorithm
 * @array: The array to sort
 * @size: the size of the array
 * Return: Nothing
*/

void bubble_sort(int *array, size_t size)
{
	unsigned int b;
	size_t i;
	int tmp;

	if (!array || size < 2)
		return;

	do {
		b = 1;
		for (i = 0; i < (size - 1); i++)
		{
			if (array[i] > array[i + 1])
			{
				tmp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = tmp;
				b = 0;
				print_array(array, size);
			}
		}
	} while (b == 0);
}
