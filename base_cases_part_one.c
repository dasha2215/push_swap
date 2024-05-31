#include "push_swap.h"

// Determine if recursion has reached base case
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

// Base case: one number
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

// Base case: two numbers
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

// Helper function for base case: three numbers; determines the
// order of values (has conditions for top and bottom chunks)
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

// Helper function for base case: three numbers; compares values to find
// min and max
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
