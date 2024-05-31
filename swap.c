#include "push_swap.h"

/**
 * swap - Swaps the first two elements of a stack.
 * @stack: The stack array.
 * @len: The length of the stack.
 *
 * This function swaps the first two elements of a stack if the stack has more than one element.
 *
 * Return: 1 if the swap is successful, 0 otherwise.
 */
int	swap(int *stack, int len)
{
	int	tmp;

	if (len <= 1)
		return (0);
	tmp = stack[0];
	stack[0] = stack[1];
	stack[1] = tmp;
	return (1);
}

int	swap_a(t_push_swap *push_swap)
{
	if (!swap(push_swap->stack_a, push_swap->len_a))
		return (0);
	if (push_swap->cmds == NULL)
		push_swap->cmds = ft_lstnew(ft_strdup("sa"));
	else
		ft_lstadd_back(&push_swap->cmds, ft_lstnew(ft_strdup("sa")));
	return (1);
}

int	swap_b(t_push_swap *push_swap)
{
	if (!swap(push_swap->stack_b, push_swap->len_b))
		return (0);
	if (push_swap->cmds == NULL)
		push_swap->cmds = ft_lstnew(ft_strdup("sb"));
	else
		ft_lstadd_back(&push_swap->cmds, ft_lstnew(ft_strdup("sb")));
	return (1);
}

int	swap_s(t_push_swap *push_swap)
{
	if (push_swap->len_a <= 1 || push_swap->len_b <= 1)
		return (0);
	swap(push_swap->stack_b, push_swap->len_b);
	swap(push_swap->stack_a, push_swap->len_a);
	if (push_swap->cmds == NULL)
		push_swap->cmds = ft_lstnew(ft_strdup("ss"));
	else
		ft_lstadd_back(&push_swap->cmds, ft_lstnew(ft_strdup("ss")));
	return (1);
}
