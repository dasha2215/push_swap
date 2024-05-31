/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_cases.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsiroten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 12:46:51 by dsiroten          #+#    #+#             */
/*   Updated: 2024/05/16 13:01:07 by dsiroten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * sort_two - Sorts two elements in stack A.
 * @push_swap: The push_swap structure containing the stacks and metadata.
 *
 * This function sorts two elements in stack A.
 */
void	sort_two(t_push_swap *push_swap)
{
	int	*stack;

	stack = push_swap->stack_a;
	if (stack[0] > stack[1])
		swap_a(push_swap);
}

/**
 * sort_three_a - Sorts three elements in stack A.
 * @push_swap: The push_swap structure containing the stacks and metadata.
 *
 * This function sorts three elements in stack A based on specific cases.
 */
void	sort_three_a(t_push_swap *push_swap)
{
	int	*stack;

	stack = push_swap->stack_a;
	if (stack[1] > stack[0] && stack[1] > stack[2] && stack[0] < stack[2])
		swap_a(push_swap);
	else if (stack[0] > stack[1] && stack[0] > stack[2] && stack[1] > stack[2])
		rotate_a(push_swap);
	if (stack[0] > stack[1] && stack[1] < stack[2] && stack[0] < stack[2])
		swap_a(push_swap);
	else if (stack[0] < stack[1] && stack[1] > stack[2] && stack[0] > stack[2])
		reverse_rotate_a(push_swap);
	else if (stack[0] > stack[1] && stack[0] > stack[2] && stack[1] < stack[2])
		rotate_a(push_swap);
}

/**
 * sort_three_b - Sorts three elements in stack B and pushes them to stack A.
 * @push_swap: The push_swap structure containing the stacks and metadata.
 *
 * This function sorts three elements in stack B and then pushes them to stack A.
 * It handles various cases based on the positions of the elements to ensure they are sorted.
 */
void	sort_three_b(t_push_swap *push_swap)
{
	int	*stack;

	stack = push_swap->stack_b;
	if (stack[1] > stack[0] && stack[1] < stack[2] && stack[0] < stack[2])
		swap_b(push_swap);
	else if (stack[0] > stack[1] && stack[0] > stack[2] && stack[1] < stack[2])
		swap_b(push_swap);
	if (stack[0] > stack[1] && stack[1] < stack[2] && stack[0] < stack[2])
		reverse_rotate_b(push_swap);
	else if (stack[0] < stack[1] && stack[1] > stack[2] && stack[0] > stack[2])
		swap_b(push_swap);
	else if (stack[0] < stack[1] && stack[0] < stack[2] && stack[1] > stack[2])
		rotate_b(push_swap);
	push_a(push_swap);
	push_a(push_swap);
	push_a(push_swap);
}
