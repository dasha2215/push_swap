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

void	sort_two(t_push_swap *push_swap)
{
	int	*stack;

	stack = push_swap->stack_a;
	if (stack[0] > stack[1])
		swap_a(push_swap);
}

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
