#include "push_swap.h"

/**
 * handle_base_case_three - Handles the base case where the chunk has three elements.
 * @push_swap: The push_swap structure containing the stacks and metadata.
 * @chunk: The current chunk being processed.
 *
 * This function handles the base case when the chunk has exactly three elements.
 * It performs the necessary operations to sort these three elements.
 */
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

/**
 * base_case_three_top_a - Sorts three elements at the top of stack A.
 * @push_swap: The push_swap structure containing the stacks and metadata.
 *
 * This function sorts three elements at the top of stack A based on specific
 * sorting cases determined by the positions of the minimum and maximum values.
 */
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

/**
 * base_case_three_bottom_a - Sorts three elements at the bottom of stack A and pushes them to the top.
 * @push_swap: The push_swap structure containing the stacks and metadata.
 *
 * This function sorts three elements at the bottom of stack A and moves them
 * to the top of stack A.
 */
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

/**
 * base_case_three_top_b - Sorts three elements at the top of stack B and pushes them to stack A.
 * @push_swap: The push_swap structure containing the stacks and metadata.
 *
 * This function sorts three elements at the top of stack B and moves them to the top of stack A.
 */
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

/**
 * base_case_three_bottom_b - Sorts three elements at the bottom of stack B and pushes them to stack A.
 * @push_swap: The push_swap structure containing the stacks and metadata.
 *
 * This function sorts three elements at the bottom of stack B and moves them to the top of stack A.
 */
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
