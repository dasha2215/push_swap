#include "push_swap.h"

void	free_all(t_push_swap *push_swap)
{
	free(push_swap->stack_a);
	free(push_swap->stack_b);
	if (push_swap->cmds)
		ft_lstclear(&push_swap->cmds, free);
	free(push_swap);
}

void	free_stack(char **stack)
{
	int	i;

	i = 0;
	if (!stack)
		return ;
	while (stack[i])
	{
		free(stack[i]);
		i++;
	}
	free(stack);
}

void	handle_error(int error, t_push_swap *push_swap)
{
	if (error == 0)
		write(2, "Error\n", 6);
	if (error == 1)
	{
		write(2, "Error\n", 6);
		free_all(push_swap);
	}
	if (error == 2)
		free_all(push_swap);
	exit(1);
}
