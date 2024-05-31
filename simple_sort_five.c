/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_case_sort_five.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsiroten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 12:47:22 by dsiroten          #+#    #+#             */
/*   Updated: 2024/05/16 12:48:36 by dsiroten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * sort_five - Sorts five elements in stack A.
 * @push_swap: The push_swap structure containing the stacks and metadata.
 *
 * This function sorts five elements in stack A. It uses push operations to move
 * elements to stack B, sorts the remaining elements in stack A, and then inserts
 * the elements from stack B back into stack A in the correct positions.
 */
void	sort_five(t_push_swap *push_swap)
{
	int	idx0;
	int	idx1;

	push_b(push_swap);
	push_b(push_swap);
	sort_three_a(push_swap);
	idx0 = get_index(push_swap, 0, 1);
	idx1 = get_index(push_swap, 1, 0);
	if (idx0 == 2 || idx1 == 2)
		painful_insert(push_swap, idx0, idx1);
	else
		insert(push_swap, idx0, idx1);
}

/**
 * get_index - Determines the index for insertion in stack A.
 * @push_swap: The push_swap structure containing the stacks and metadata.
 * @i: Index of the element in stack B to be inserted.
 * @y: Index of the other element in stack B to compare.
 *
 * This function determines the appropriate index in stack A to insert an element
 * from stack B. It considers the relative positions of the elements in both stacks.
 *
 * Return: The index in stack A where the element should be inserted.
 */
int	get_index(t_push_swap *push_swap, int i, int y)
{
	int	*stack_a;
	int	*stack_b;

	stack_a = push_swap->stack_a;
	stack_b = push_swap->stack_b;
	if (stack_b[i] < stack_a[0] && stack_b[i] < stack_b[y])
		return (0);
	else if (stack_b[i] < stack_a[0] || (stack_b[i] > stack_a[0]
			&& stack_b[i] < stack_a[1] && stack_b[i] < stack_b[y]))
		return (1);
	else if (stack_b[i] > stack_a[2] && stack_b[i] > stack_b[y])
		return (4);
	else if (stack_b[i] > stack_a[2] || (stack_b[i] < stack_a[2]
			&& stack_b[i] > stack_a[1] && stack_b[i] > stack_b[y]))
		return (3);
	else
		return (2);
}

/**
 * insert - Inserts elements from stack B into stack A in the correct positions.
 * @push_swap: The push_swap structure containing the stacks and metadata.
 * @idx0: Index for the first element to be inserted.
 * @idx1: Index for the second element to be inserted.
 *
 * This function inserts elements from stack B into stack A at the correct positions
 * to maintain the sorted order in stack A. It handles different cases based on the
 * calculated indices.
 */
void	insert(t_push_swap *push_swap, int idx0, int idx1)
{
	if (idx0 < idx1)
		swap_indexes(push_swap, &idx0, &idx1);
	if (idx0 != 3)
		push_a(push_swap);
	if (idx0 == 3)
		reverse_rotate_a(push_swap);
	if (idx0 != 4 || idx1 == 3)
		push_a(push_swap);
	if (idx0 != 1)
		rotate_a(push_swap);
	if (idx0 == 3 || (idx0 == 4 && idx1 == 3))
		rotate_a(push_swap);
	if (idx0 == 3 || (idx0 == 4 && idx1 != 3))
		push_a(push_swap);
	if (idx1 == 1)
		swap_a(push_swap);
}

/**
 * painful_insert - Handles complex insertions of elements from stack B to stack A.
 * @push_swap: The push_swap structure containing the stacks and metadata.
 * @idx0: Index for the first element to be inserted.
 * @idx1: Index for the second element to be inserted.
 *
 * This function handles more complex cases for inserting elements from stack B
 * into stack A. It manages scenarios where the indices require multiple rotations
 * or swaps to maintain the sorted order.
 */
void	painful_insert(t_push_swap *push_swap, int idx0, int idx1)
{
	if ((idx0 == 2 && (idx1 == 3 || idx1 == 4))
		|| (idx1 == 2 && (idx0 == 0 || idx0 == 1)))
		swap_indexes(push_swap, &idx0, &idx1);
	if (idx0 != 3)
		push_a(push_swap);
	if (idx0 != 2)
		reverse_rotate_a(push_swap);
	if (idx1 != 2)
		swap_a(push_swap);
	push_a(push_swap);
	if (idx0 == 3)
		push_a(push_swap);
	if (idx1 == 1)
		swap_a(push_swap);
	if (idx1 == 2)
	{
		reverse_rotate_a(push_swap);
		reverse_rotate_a(push_swap);
	}
}

/**
 * swap_indexes - Swaps two indices and performs the necessary operations.
 * @push_swap: The push_swap structure containing the stacks and metadata.
 * @idx0: Pointer to the first index.
 * @idx1: Pointer to the second index.
 *
 * This function swaps the values of two indices and performs a swap operation
 * on stack B to reflect this change. It helps in managing the order of elements
 * during insertion.
 */
void	swap_indexes(t_push_swap *push_swap, int *idx0, int *idx1)
{
	int	temp;

	swap_b(push_swap);
	temp = *idx0;
	*idx0 = *idx1;
	*idx1 = temp;
}