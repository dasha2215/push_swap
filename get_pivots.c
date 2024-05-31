#include "push_swap.h"

// General function that determines the algorithm for getting pivots
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

// Insertion sort: used for chunks of 10 or less elements
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

// Quick sort: used for chunks of more than 10 elements
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
