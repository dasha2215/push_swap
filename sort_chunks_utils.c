#include "push_swap.h"

/**
 * from_bottom_a_to_bottom_b - Moves an element from the bottom of stack A to the bottom of stack B.
 * @push_swap: The push_swap structure containing the stacks and metadata.
 * @chunk_len: Array to store the lengths of the resulting sub-chunks.
 *
 * This function performs the necessary operations to move an element from the
 * bottom of stack A to the bottom of stack B and updates the chunk lengths accordingly.
 */
void	from_bottom_a_to_bottom_b(t_push_swap *push_swap, int *chunk_len)
{
	chunk_len[0]++;
	reverse_rotate_a(push_swap);
	push_b(push_swap);
	rotate_b(push_swap);
}

/**
 * from_bottom_a_to_top_b - Moves an element from the bottom of stack A to the top of stack B.
 * @push_swap: The push_swap structure containing the stacks and metadata.
 * @chunk_len: Array to store the lengths of the resulting sub-chunks.
 *
 * This function performs the necessary operations to move an element from the
 * bottom of stack A to the top of stack B and updates the chunk lengths accordingly.
 */
void	from_bottom_a_to_top_b(t_push_swap *push_swap, int *chunk_len)
{
	chunk_len[1]++;
	reverse_rotate_a(push_swap);
	push_b(push_swap);
}

/**
 * from_bottom_b_to_bottom_a - Moves an element from the bottom of stack B to the bottom of stack A.
 * @push_swap: The push_swap structure containing the stacks and metadata.
 * @chunk_len: Array to store the lengths of the resulting sub-chunks.
 *
 * This function performs the necessary operations to move an element from the
 * bottom of stack B to the bottom of stack A and updates the chunk lengths accordingly.
 */
void	from_bottom_b_to_bottom_a(t_push_swap *push_swap, int *chunk_len)
{
	chunk_len[1]++;
	reverse_rotate_b(push_swap);
	push_a(push_swap);
	rotate_a(push_swap);
}

/**
 * from_bottom_b_to_top_a - Moves an element from the bottom of stack B to the top of stack A.
 * @push_swap: The push_swap structure containing the stacks and metadata.
 * @chunk_len: Array to store the lengths of the resulting sub-chunks.
 *
 * This function performs the necessary operations to move an element from the
 * bottom of stack B to the top of stack A and updates the chunk lengths accordingly.
 */
void	from_bottom_b_to_top_a(t_push_swap *push_swap, int *chunk_len)
{
	chunk_len[2]++;
	reverse_rotate_b(push_swap);
	push_a(push_swap);
}

/**
 * from_top_b_to_bottom_a - Moves an element from the top of stack B to the bottom of stack A.
 * @push_swap: The push_swap structure containing the stacks and metadata.
 * @chunk_len: Array to store the lengths of the resulting sub-chunks.
 *
 * This function performs the necessary operations to move an element from the
 * top of stack B to the bottom of stack A and updates the chunk lengths accordingly.
 */
void	from_top_b_to_bottom_a(t_push_swap *push_swap, int *chunk_len)
{
	chunk_len[1]++;
	push_a(push_swap);
	rotate_a(push_swap);
}
