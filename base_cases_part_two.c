#include "push_swap.h"

// Base case: three numbers
void	handle_base_case_three(t_push_swap *push_swap, int chunk)
{
	if (chunk == 2 && push_swap->len_a == 3)
		sort_three_a(push_swap);
	else if (chunk == 0 && push_swap->len_b == 3)
		sort_three_b(push_swap);
	else if (chunk == 2)
		base_case_three_top_a(push_swap);
	else if (chunk == 1)
		base_case_three_bottom_a(push_swap);
	else if (chunk == 0)
		base_case_three_top_b(push_swap);
	else if (chunk == 4)
		base_case_three_bottom_b(push_swap);
}

// Sort three numbers at the top of a
void	base_case_three_top_a(t_push_swap *push_swap)
{
	int	min;
	int	max;
	int	n;

	get_min_max(push_swap->stack_a, 0, &min, &max);
	n = get_case(push_swap->len_a, min, max);
	if (n == 1)
		return ;
	if (n == 2 || n == 4)
		rotate_a(push_swap);
	swap_a(push_swap);
	if (n == 5 || n == 6)
	{
		rotate_a(push_swap);
		swap_a(push_swap);
	}
	if (n != 3)
		reverse_rotate_a(push_swap);
	if (n == 4 || n == 6)
		swap_a(push_swap);
}

// Sort three numbers at the bottom of stack a and push them to top
void	base_case_three_bottom_a(t_push_swap *push_swap)
{
	int	min;
	int	max;
	int	n;

	get_min_max(push_swap->stack_a, push_swap->len_a, &min, &max);
	n = get_case(push_swap->len_a, min, max);
	reverse_rotate_a(push_swap);
	reverse_rotate_a(push_swap);
	if (n == 1 || n == 3)
		reverse_rotate_a(push_swap);
	if (n != 1 && n != 5)
		swap_a(push_swap);
	if (n == 5 || n == 6)
		push_b(push_swap);
	if (n != 1 && n != 3)
		reverse_rotate_a(push_swap);
	if (n == 4 || n == 5 || n == 6)
		swap_a(push_swap);
	if (n == 5 || n == 6)
		push_a(push_swap);
}

// Sort three numbers at the top of stack b and push them
// on top of stack a
void	base_case_three_top_b(t_push_swap *push_swap)
{
	int	min;
	int	max;
	int	n;

	get_min_max(push_swap->stack_b, 0, &min, &max);
	n = get_case(push_swap->len_b, min, max);
	if (n == 1 || n == 2)
		swap_b(push_swap);
	push_a(push_swap);
	if (n != 4 && n != 6)
		swap_b(push_swap);
	push_a(push_swap);
	if (n == 1 || n == 3 || n == 4)
		swap_a(push_swap);
	push_a(push_swap);
}

// Sort three numbers at the bottom of stack b and push them
// on top of stack a
void	base_case_three_bottom_b(t_push_swap *push_swap)
{
	int	min;
	int	max;
	int	n;

	get_min_max(push_swap->stack_b, push_swap->len_b, &min, &max);
	n = get_case(push_swap->len_b, min, max);
	reverse_rotate_b(push_swap);
	if (n != 1 && n != 3)
		reverse_rotate_b(push_swap);
	if (n != 5 && n != 6)
		push_a(push_swap);
	if (n != 2)
		reverse_rotate_b(push_swap);
	if (n != 3 && n != 4)
		push_a(push_swap);
	if (n == 1 || n == 2 || n == 3)
		reverse_rotate_b(push_swap);
	if (n == 5)
		swap_b(push_swap);
	push_a(push_swap);
	if (n != 1 && n != 2)
		push_a(push_swap);
}
