#include "push_swap.h"

/**
 * handle_base_case - Checks if the recursion has reached a base case.
 * @push_swap: The push_swap structure containing the stacks and metadata.
 * @chunk: The current chunk being processed.
 * @len: The length of the current chunk.
 *
 * This function checks if the recursion has reached a base case for sorting,
 * such as having 1, 2, or 3 elements. It calls the appropriate base case handler
 * and returns 1 if a base case is handled, otherwise it returns 0.
 *
 * Return: 1 if a base case is handled, 0 otherwise.
 */
int	handle_base_case(t_push_swap *push_swap, int chunk, int len)
{
	if (len == 0)
		return (1);
	if (len == 1)
	{
		handle_base_case_one(push_swap, chunk);
		return (1);
	}
	if (len == 2)
	{
		handle_base_case_two(push_swap, chunk);
		return (1);
	}
	if (len == 3)
	{
		if (chunk == 4 && push_swap->len_b == 3)
			chunk = 0;
		handle_base_case_three(push_swap, chunk);
		return (1);
	}
	if (chunk == 2 && len == 5 && push_swap->len_a == 5)
	{
		sort_five(push_swap);
		return (1);
	}
	return (0);
}

/**
 * handle_base_case_one - Handles the base case where the chunk has one element.
 * @push_swap: The push_swap structure containing the stacks and metadata.
 * @chunk: The current chunk being processed.
 *
 * This function handles the base case when the chunk has exactly one element.
 * Depending on the chunk, it performs the necessary operations to handle this case.
 */
void	handle_base_case_one(t_push_swap *push_swap, int chunk)
{
	if (chunk == 1)
		reverse_rotate_a(push_swap);
	else if (chunk == 4)
	{
		reverse_rotate_b(push_swap);
		push_a(push_swap);
	}
	else if (chunk == 0)
		push_a(push_swap);
	else if (chunk == 2 && push_swap->len_a == 1)
		push_swap->start = push_swap->stack_a[0];
}

/**
 * handle_base_case_two - Handles the base case where the chunk has two elements.
 * @push_swap: The push_swap structure containing the stacks and metadata.
 * @chunk: The current chunk being processed.
 *
 * This function handles the base case when the chunk has exactly two elements.
 * It performs the necessary operations to sort or move these two elements.
 */
void	handle_base_case_two(t_push_swap *push_swap, int chunk)
{
	if (chunk == 1)
	{
		reverse_rotate_a(push_swap);
		reverse_rotate_a(push_swap);
	}
	else if (chunk == 0 || (chunk == 4 && push_swap->len_b == 2))
	{
		push_a(push_swap);
		push_a(push_swap);
	}
	else if (chunk == 4)
	{
		reverse_rotate_b(push_swap);
		push_a(push_swap);
		reverse_rotate_b(push_swap);
		push_a(push_swap);
	}
	if (push_swap->stack_a[0] > push_swap->stack_a[1])
		swap_a(push_swap);
}

/**
 * get_case - Determines the sorting case for three elements.
 * @len: The length of the stack.
 * @min: The index of the minimum value.
 * @max: The index of the maximum value.
 *
 * This helper function determines the specific case for sorting three elements
 * based on the positions of the minimum and maximum values.
 *
 * Return: An integer representing the specific case for sorting.
 */
int	get_case(int len, int min, int max)
{
	if (min == 0 && max == 2)
		return (1);
	else if (min == 0 && max == 1)
		return (2);
	else if (min == 1 && max == 2)
		return (3);
	else if (min == 2 && max == 1)
		return (4);
	else if (min == 1 && max == 0)
		return (5);
	else if (min == 2 && max == 0)
		return (6);
	else if (min == len - 3 && max == len - 1)
		return (1);
	else if (min == len - 3 && max == len - 2)
		return (2);
	else if (min == len - 2 && max == len - 1)
		return (3);
	else if (min == len - 1 && max == len - 2)
		return (4);
	else if (min == len - 2 && max == len - 3)
		return (5);
	else if (min == len - 1 && max == len - 3)
		return (6);
	return (0);
}

/**
 * get_min_max - Finds the minimum and maximum values in the stack.
 * @stack: The stack array.
 * @len: The length of the stack.
 * @min: Pointer to store the index of the minimum value.
 * @max: Pointer to store the index of the maximum value.
 *
 * This helper function finds the minimum and maximum values in the stack
 * and updates the provided pointers with their indices.
 */
void	get_min_max(int *stack, int len, int *min, int *max)
{
	int	a;
	int	b;
	int	c;

	a = 0;
	b = 1;
	c = 2;
	if (len != 0)
	{
		a = len - a - 1;
		b = len - b - 1;
		c = len - c - 1;
	}
	*min = a;
	*max = a;
	if (stack[b] < stack[*min])
		*min = b;
	if (stack[b] > stack[*max])
		*max = b;
	if (stack[c] < stack[*min])
		*min = c;
	if (stack[c] > stack[*max])
		*max = c;
}
