/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsiroten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 13:41:23 by dsiroten          #+#    #+#             */
/*   Updated: 2024/05/16 19:54:19 by dsiroten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Checks if stack a is sorted. Receives a 'top' value so the function can also
// check if stack is sorted after a certain element
int	is_stack_sorted(t_push_swap *push_swap, int top)
{
	int	i;

	i = top;
	if (push_swap->len_a == 1)
		return (1);
	while (i + 1 < push_swap->len_a)
	{
		if (push_swap->len_b != 0 && push_swap->stack_a[i] == push_swap->start)
			break ;
		if (push_swap->stack_a[i] > push_swap->stack_a[i + 1]
			|| (i > 0 && push_swap->stack_a[i - 1] > push_swap->stack_a[i]))
			return (0);
		i++;
	}
	return (1);
}

// Core recursive function: receives a chunk, calls a sorting function on it,
// then calls itself on each of the three resulting chunks
void	split_chunk(t_push_swap *push_swap, int len, int chunk)
{
	int	chunk_len[3];

	chunk_len[0] = 0;
	chunk_len[1] = 0;
	chunk_len[2] = 0;
	if (handle_base_case(push_swap, chunk, len))
		return ;
	if (chunk == 4 && len == push_swap->len_b)
		chunk = 0;
	sort_chunk(push_swap, len, chunk, chunk_len);
	if (chunk == 2 && chunk_len[2] != push_swap->len_a)
		split_chunk(push_swap, chunk_len[2], 1);
	else
		split_chunk(push_swap, chunk_len[2], 2);
	if (chunk == 2 || chunk == 1)
		split_chunk(push_swap, chunk_len[1], 0);
	else
		split_chunk(push_swap, chunk_len[1], 1);
	if (chunk == 4)
		split_chunk(push_swap, chunk_len[0], 0);
	else
		split_chunk(push_swap, chunk_len[0], 4);
}

// Checks if the current max chunk on top_a is sorted (in case the elements
// are by chance in the correct order and don't require sorting)
int	is_top_a_sorted(t_push_swap *push_swap, int len)
{
	int	i;
	int	j;
	int	flag;
	int	*stack;

	i = len;
	stack = push_swap->stack_a;
	while (i > 0)
	{
		j = 0;
		flag = 1;
		if (!is_stack_sorted(push_swap, i))
			return (i + 1);
		while (j < i)
		{
			if (stack[j] > stack[i])
				flag = 0;
			j++;
		}
		if (flag == 0)
			return (i + 1);
		i--;
	}
	return (0);
}

// General sorting function: checks if the stack is already sorted; if not,
// starts a sorting algorithm depending on the length of the stack
void	sort_stack(t_push_swap *push_swap)
{
	if (is_stack_sorted(push_swap, 0))
		return ;
	if (push_swap->len_a == 2)
		sort_two(push_swap);
	else if (push_swap->len_a == 3)
		sort_three_a(push_swap);
	else if (push_swap->len_a == 5)
		sort_five(push_swap);
	else
	{
		split_chunk(push_swap, push_swap->len_a, 2);
		optimize_commands(push_swap->cmds);
	}
}
