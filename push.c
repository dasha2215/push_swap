#include "push_swap.h"

int	push(int *stack_from, int *stack_to, int stack_from_len, int stack_to_len)
{
	int	tmp;
	int	ttmp;
	int	i;

	i = 1;
	if (stack_from_len == 0)
		return (0);
	if (stack_to_len > 0)
		tmp = stack_to[0];
	stack_to[0] = stack_from[0];
	while (stack_to_len > 0 && i < stack_to_len + 1)
	{
		ttmp = stack_to[i];
		stack_to[i++] = tmp;
		tmp = ttmp;
	}
	i = 0;
	while (i < stack_from_len - 1)
	{
		stack_from[i] = stack_from[i + 1];
		i++;
	}
	return (1);
}

int	push_a(t_push_swap *push_swap)
{
	if (!push(push_swap->stack_b, push_swap->stack_a,
			push_swap->len_b, push_swap->len_a))
		return (0);
	push_swap->len_a++;
	push_swap->len_b--;
	if (push_swap->cmds == NULL)
		push_swap->cmds = ft_lstnew(ft_strdup("pa"));
	else
		ft_lstadd_back(&push_swap->cmds, ft_lstnew(ft_strdup("pa")));
	return (1);
}

int	push_b(t_push_swap *push_swap)
{
	if (!push(push_swap->stack_a, push_swap->stack_b,
			push_swap->len_a, push_swap->len_b))
		return (0);
	push_swap->len_a--;
	push_swap->len_b++;
	if (push_swap->cmds == NULL)
		push_swap->cmds = ft_lstnew(ft_strdup("pb"));
	else
		ft_lstadd_back(&push_swap->cmds, ft_lstnew(ft_strdup("pb")));
	return (1);
}
