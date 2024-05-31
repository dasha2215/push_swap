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

/**
 * is_stack_sorted - Checks if stack A is sorted.
 * @push_swap: The push_swap structure containing the stacks and metadata.
 * @top: The starting index to check from.
 *
 * This function checks if stack A is sorted from the given starting index.
 *
 * Return: 1 if the stack is sorted, 0 otherwise.
 */
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

/**
 * split_chunk - Recursively sorts chunks of the stack.
 * @push_swap: The push_swap structure containing the stacks and metadata.
 * @len: The length of the current chunk.
 * @chunk: The current chunk being processed.
 *
 * This function recursively sorts chunks of the stack by dividing them into
 * smaller chunks and sorting each chunk.
 */
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

/**
 * is_top_a_sorted - Checks if the top chunk of stack A is sorted.
 * @push_swap: The push_swap structure containing the stacks and metadata.
 * @len: The length of the chunk to check.
 *
 * This function checks if the top chunk of stack A is sorted.
 *
 * Return: The index up to which the stack is sorted.
 */
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

/**
 * sort_stack - Sorts the entire stack using the appropriate algorithm.
 * @push_swap: The push_swap structure containing the stacks and metadata.
 *
 * This function sorts the entire stack using the appropriate sorting algorithm
 * based on the length of the stack.
 */
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
