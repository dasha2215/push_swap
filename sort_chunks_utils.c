#include "push_swap.h"

void	from_bottom_a_to_bottom_b(t_push_swap *push_swap, int *chunk_len)
{
	chunk_len[0]++;
	reverse_rotate_a(push_swap);
	push_b(push_swap);
	rotate_b(push_swap);
}

void	from_bottom_a_to_top_b(t_push_swap *push_swap, int *chunk_len)
{
	chunk_len[1]++;
	reverse_rotate_a(push_swap);
	push_b(push_swap);
}

void	from_bottom_b_to_bottom_a(t_push_swap *push_swap, int *chunk_len)
{
	chunk_len[1]++;
	reverse_rotate_b(push_swap);
	push_a(push_swap);
	rotate_a(push_swap);
}

void	from_bottom_b_to_top_a(t_push_swap *push_swap, int *chunk_len)
{
	chunk_len[2]++;
	reverse_rotate_b(push_swap);
	push_a(push_swap);
}

void	from_top_b_to_bottom_a(t_push_swap *push_swap, int *chunk_len)
{
	chunk_len[1]++;
	push_a(push_swap);
	rotate_a(push_swap);
}
