#include "push_swap.h"

/**
 * free_all - Frees all allocated memory in the push_swap structure.
 * @push_swap: The push_swap structure to be freed.
 *
 * This function frees all dynamically allocated memory within the push_swap
 * structure, including the stacks and command list.
 */
void	free_all(t_push_swap *push_swap)
{
	free(push_swap->stack_a);
	free(push_swap->stack_b);
	if (push_swap->cmds)
		ft_lstclear(&push_swap->cmds, free);
	free(push_swap);
}

/**
 * free_stack - Frees a dynamically allocated stack array.
 * @stack: The stack array to be freed.
 *
 * This function frees each element of the stack array and then frees the array itself.
 */
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

/**
 * handle_error - Handles errors by displaying an error message and freeing resources.
 * @error: The error code indicating the type of error.
 * @push_swap: The push_swap structure to be freed if necessary.
 *
 * This function handles errors by displaying an error message, freeing resources,
 * and exiting the program with an error code.
 */
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