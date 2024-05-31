#include "push_swap.h"

/**
 * rotate - Performs a rotation on a stack.
 * @stack: The stack array.
 * @len: The length of the stack.
 *
 * This function performs a rotation on the stack, moving the top element to
 * the bottom.
 *
 * Return: 1 if the rotation is successful, 0 otherwise.
 */
int	rotate(int *stack, int len)
{
	int	tmp;
	int	i;

	i = 0;
	tmp = stack[0];
	if (len < 2)
		return (0);
	while (i < len - 1)
	{
		stack[i] = stack[i + 1];
		i++;
	}
	stack[i] = tmp;
	return (1);
}

int	rotate_a(t_push_swap *push_swap)
{
	if (!rotate(push_swap->stack_a, push_swap->len_a))
		return (0);
	if (push_swap->cmds == NULL)
		push_swap->cmds = ft_lstnew(ft_strdup("ra"));
	else
		ft_lstadd_back(&push_swap->cmds, ft_lstnew(ft_strdup("ra")));
	return (1);
}

int	rotate_b(t_push_swap *push_swap)
{
	if (!rotate(push_swap->stack_b, push_swap->len_b))
		return (0);
	if (push_swap->cmds == NULL)
		push_swap->cmds = ft_lstnew(ft_strdup("rb"));
	else
		ft_lstadd_back(&push_swap->cmds, ft_lstnew(ft_strdup("rb")));
	return (1);
}

int	rotate_r(t_push_swap *push_swap)
{
	if (push_swap->len_a <= 1 || push_swap->len_b <= 1)
		return (0);
	rotate(push_swap->stack_b, push_swap->len_b);
	rotate(push_swap->stack_a, push_swap->len_a);
	if (push_swap->cmds == NULL)
		push_swap->cmds = ft_lstnew(ft_strdup("rr"));
	else
		ft_lstadd_back(&push_swap->cmds, ft_lstnew(ft_strdup("rr")));
	return (1);
}
