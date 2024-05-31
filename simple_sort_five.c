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

void	swap_indexes(t_push_swap *push_swap, int *idx0, int *idx1)
{
	int	temp;

	swap_b(push_swap);
	temp = *idx0;
	*idx0 = *idx1;
	*idx1 = temp;
}