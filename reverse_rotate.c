/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsiroten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 13:35:04 by dsiroten          #+#    #+#             */
/*   Updated: 2024/05/14 13:38:30 by dsiroten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * reverse_rotate - Performs a reverse rotation on a stack.
 * @stack: The stack array.
 * @len: The length of the stack.
 *
 * This function performs a reverse rotation on the stack, moving the bottom
 * element to the top.
 *
 * Return: 1 if the rotation is successful, 0 otherwise.
 */
int	reverse_rotate(int *stack, int len)
{
	int	tmp;
	int	i;

	i = len - 1;
	if (len < 2)
		return (0);
	tmp = stack[i];
	while (i > 0)
	{
		stack[i] = stack[i - 1];
		i--;
	}
	stack[i] = tmp;
	return (1);
}

int	reverse_rotate_a(t_push_swap *push_swap)
{
	if (!reverse_rotate(push_swap->stack_a, push_swap->len_a))
		return (0);
	if (push_swap->cmds == NULL)
		push_swap->cmds = ft_lstnew(ft_strdup("rra"));
	else
		ft_lstadd_back(&push_swap->cmds, ft_lstnew(ft_strdup("rra")));
	return (1);
}

int	reverse_rotate_b(t_push_swap *push_swap)
{
	if (!reverse_rotate(push_swap->stack_b, push_swap->len_b))
		return (0);
	if (push_swap->cmds == NULL)
		push_swap->cmds = ft_lstnew(ft_strdup("rrb"));
	else
		ft_lstadd_back(&push_swap->cmds, ft_lstnew(ft_strdup("rrb")));
	return (1);
}

int	reverse_rotate_r(t_push_swap *push_swap)
{
	if (push_swap->len_a <= 1 || push_swap->len_b <= 1)
		return (0);
	reverse_rotate(push_swap->stack_b, push_swap->len_b);
	reverse_rotate(push_swap->stack_a, push_swap->len_a);
	if (push_swap->cmds == NULL)
		push_swap->cmds = ft_lstnew(ft_strdup("rrr"));
	else
		ft_lstadd_back(&push_swap->cmds, ft_lstnew(ft_strdup("rrr")));
	return (1);
}
