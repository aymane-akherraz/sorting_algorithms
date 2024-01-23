#include "sort.h"
void sort(int *array, int start, int end, size_t size);
unsigned int get_part(int *array, int start, int end, size_t size);

/**
 * quick_sort - Sorts an array of integers in ascending order
 * using the quick sort algorithm
 * @array: The array to sort
 * @size: the size of the array
 * Return: Nothing
*/

void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	sort(array, 0, (size - 1), size);
}
/**
 * sort - Sorts the array by recursive calls
 * @array: The array to sort
 * @start: An integer representing the start of the array
 * @end: An integer representing the end of the array
 * @size: the size of the array
*/
void sort(int *array, int start, int end, size_t size)
{
	unsigned int p_idx;

	if (start < end)
	{
		p_idx = get_part(array, start, end, size);
		sort(array, start, (p_idx - 1), size);
		sort(array, (p_idx + 1), end, size);
	}
}
/**
 * get_part - Makes partitions and sets the pivot in its sorted position
 * @array: The array to sort
 * @start: An integer representing the start of the partition
 * @end: An integer representing the end of the partition
 * @size: the size of the array
 * Return: the index of the pivot
*/
unsigned int get_part(int *array, int start, int end, size_t size)
{
	int i, p_idx = start, p = array[end], tmp;

	for (i = start; i < end; i++)
	{
		if (array[i] <= p)
		{
			if (array[i] != array[p_idx])
			{
				tmp = array[i];
				array[i] = array[p_idx];
				array[p_idx] = tmp;
				print_array(array, size);
			}
			p_idx++;
		}
	}

	if (array[end] != array[p_idx])
	{
		array[end] = array[p_idx];
		array[p_idx] = p;
		print_array(array, size);
	}

	return (p_idx);
}
