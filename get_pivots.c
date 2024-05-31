#include "push_swap.h"

/**
 * get_pivots - Determines pivot values for dividing a stack into chunks.
 * @stack: The stack array.
 * @len: The length of the chunk.
 * @min: Pointer to store the lower pivot value.
 * @max: Pointer to store the upper pivot value.
 *
 * This function calculates pivot values for dividing the stack into chunks.
 * It uses quick sort for larger chunks and insertion sort for smaller chunks.
 *
 * Return: 1 on success, 0 on failure.
 */
int	get_pivots(int *stack, int len, int *min, int *max)
{
	int	*arr;
	int	i;

	arr = malloc(len * sizeof(int));
	if (!arr)
		return (0);
	i = 0;
	while (i < len)
	{
		arr[i] = stack[i];
		i++;
	}
	if (len <= 10)
	{
		get_pivots_for_ten(arr, len, min, max);
		free(arr);
		return (1);
	}
	sort_arr(arr, 0, len - 1);
	*min = arr[len / 3];
	*max = arr[(len / 3) * 2];
	free(arr);
	return (1);
}

/**
 * get_pivots_for_ten - Determines pivot values for chunks of ten or fewer elements.
 * @stack: The stack array.
 * @len: The length of the chunk.
 * @min: Pointer to store the lower pivot value.
 * @max: Pointer to store the upper pivot value.
 *
 * This function calculates pivot values for smaller chunks using insertion sort.
 */
void	get_pivots_for_ten(int *stack, int len, int *min, int *max)
{
	sort_arr_of_ten(stack, len);
	if (len <= 5)
	{
		*min = stack[0];
		*max = stack[len / 2];
	}
	else
	{
		*min = stack[len / 3];
		*max = stack[(len / 3) * 2];
	}
}

/**
 * sort_arr_of_ten - Sorts an array of ten or fewer elements using insertion sort.
 * @arr: The array to be sorted.
 * @len: The length of the array.
 *
 * This function sorts an array of ten or fewer elements using the insertion sort algorithm.
 */
void	sort_arr_of_ten(int *arr, int len)
{
	int	i;
	int	j;
	int	n;

	i = 1;
	while (i < len)
	{
		n = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > n)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = n;
		i++;
	}
}

/**
 * sort_arr - Sorts an array using the quick sort algorithm.
 * @arr: The array to be sorted.
 * @low: The starting index of the array to be sorted.
 * @high: The ending index of the array to be sorted.
 *
 * This function sorts an array using the quick sort algorithm.
 */
void	sort_arr(int *arr, int low, int high)
{
	int	mid;

	if (low < high)
	{
		mid = split_arr(arr, low, high);
		sort_arr(arr, low, mid - 1);
		sort_arr(arr, mid + 1, high);
	}
}

/**
 * split_arr - Splits an array for the quick sort algorithm.
 * @arr: The array to be split.
 * @low: The starting index of the array to be split.
 * @high: The ending index of the array to be split.
 *
 * This function splits an array into two parts for the quick sort algorithm.
 *
 * Return: The partition index.
 */
int	split_arr(int *arr, int low, int high)
{
	int	pivot;
	int	i;
	int	j;

	pivot = arr[high];
	i = (low - 1);
	j = low;
	while (j <= high - 1)
	{
		if (arr[j] < pivot)
		{
			i++;
			swap_pivot(&arr[i], &arr[j]);
		}
		j++;
	}
	swap_pivot(&arr[i + 1], &arr[high]);
	return (i + 1);
}
