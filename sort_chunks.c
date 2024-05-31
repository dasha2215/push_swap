#include "push_swap.h"

void	sort_chunk(t_push_swap *push_swap, int len, int chunk, int *chunk_len)
{
	if (chunk == 2)
		sort_chunk_top_a(push_swap, len, chunk_len);
	else if (chunk == 1)
		sort_chunk_bottom_a(push_swap, len, chunk_len);
	else if (chunk == 0)
		sort_chunk_top_b(push_swap, len, chunk_len);
	else if (chunk == 4)
		sort_chunk_bottom_b(push_swap, len, chunk_len);
}

void	sort_chunk_top_a(t_push_swap *push_swap, int len, int *chunk_len)
{
	int	min;
	int	max;

	if (!get_pivots(push_swap->stack_a, len, &min, &max))
		handle_error(2, push_swap);
	while (len > 0)
	{
		len--;
		if (push_swap->stack_a[0] < min)
		{
			chunk_len[0]++;
			push_b(push_swap);
			rotate_b(push_swap);
		}
		else if (push_swap->stack_a[0] <= max && push_swap->stack_a[0] >= min)
		{
			chunk_len[1]++;
			push_b(push_swap);
		}
		else
		{
			chunk_len[2]++;
			rotate_a(push_swap);
		}
	}
}

void	sort_chunk_bottom_a(t_push_swap *push_swap, int len, int *chunk_len)
{
	int	min;
	int	max;

	if (!get_pivots(push_swap->stack_a + (push_swap->len_a - len),
			len, &min, &max))
		handle_error(2, push_swap);
	while (len-- > 0)
	{
		if (push_swap->stack_a[push_swap->len_a - 1] < min)
			from_bottom_a_to_bottom_b(push_swap, chunk_len);
		else if (push_swap->stack_a[push_swap->len_a - 1] <= max
			&& push_swap->stack_a[push_swap->len_a - 1] >= min)
			from_bottom_a_to_top_b(push_swap, chunk_len);
		else
		{
			chunk_len[2]++;
			reverse_rotate_a(push_swap);
		}
	}
	if (is_top_a_sorted(push_swap, chunk_len[2]) != chunk_len[2] + 1)
		chunk_len[2] = is_top_a_sorted(push_swap, chunk_len[2]);
}

void	sort_chunk_top_b(t_push_swap *push_swap, int len, int *chunk_len)
{
	int	min;
	int	max;

	if (!get_pivots(push_swap->stack_b, len, &min, &max))
		handle_error(2, push_swap);
	while (len-- > 0)
	{
		if (push_swap->stack_b[0] < min)
		{
			chunk_len[0]++;
			rotate_b(push_swap);
		}
		else if (push_swap->stack_b[0] <= max && push_swap->stack_b[0] >= min)
			from_top_b_to_bottom_a(push_swap, chunk_len);
		else
		{
			chunk_len[2]++;
			push_a(push_swap);
		}
	}
	if (is_top_a_sorted(push_swap, chunk_len[2]) != chunk_len[2] + 1)
		chunk_len[2] = is_top_a_sorted(push_swap, chunk_len[2]);
}

void	sort_chunk_bottom_b(t_push_swap *push_swap, int len, int *chunk_len)
{
	int	min;
	int	max;

	if (!get_pivots(push_swap->stack_b + (push_swap->len_b - len),
			len, &min, &max))
		handle_error(2, push_swap);
	while (len-- > 0)
	{
		if (push_swap->stack_b[push_swap->len_b - 1] < min)
		{
			chunk_len[0]++;
			reverse_rotate_b(push_swap);
		}
		else if (push_swap->stack_b[push_swap->len_b - 1] <= max
			&& push_swap->stack_b[push_swap->len_b - 1] >= min)
			from_bottom_b_to_bottom_a(push_swap, chunk_len);
		else
			from_bottom_b_to_top_a(push_swap, chunk_len);
	}
	if (is_top_a_sorted(push_swap, chunk_len[2]) != chunk_len[2] + 1)
		chunk_len[2] = is_top_a_sorted(push_swap, chunk_len[2]);
}
