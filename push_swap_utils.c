#include "push_swap.h"

/**
 * is_empty_string - Checks if a string is empty or contains only spaces.
 * @str: The string to check.
 *
 * This function checks if a string is empty or contains only spaces.
 *
 * Return: 1 if the string is empty or contains only spaces, 0 otherwise.
 */
int	is_empty_string(char *str)
{
	while (*str)
	{
		if (*str != ' ')
			return (0);
		str++;
	}
	return (1);
}

/**
 * join_stack - Joins a new string to an existing stack string with a space separator.
 * @stack: The existing stack string.
 * @str: The new string to add to the stack.
 *
 * This function takes an existing stack string and a new string, joins them
 * with a space separator, and returns the newly allocated combined string.
 * It handles memory allocation and ensures proper freeing of the previous
 * stack string to prevent memory leaks. If any memory allocation fails, it
 * frees the allocated memory and returns NULL.
 *
 * Return: The newly allocated combined stack string, or NULL if memory allocation fails.
 */
char	*join_stack(char *stack, char *str)
{
	char	*temp_stack;
	char	*temp;

	temp_stack = stack;
	temp = ft_strjoin(" ", str);
	if (!temp)
	{
		free(stack);
		return (0);
	}
	stack = ft_strjoin(temp_stack, temp);
	free(temp_stack);
	free(temp);
	if (!stack)
		return (0);
	return (stack);
}

/**
 * add_command - Adds a new command to the command list.
 * @cmds: The list of commands.
 * @command: The command to add.
 *
 * This function adds a new command to the end of the command list.
 */
void	add_command(t_list **cmds, char *command)
{
	if (*cmds == NULL)
		*cmds = ft_lstnew(command);
	else
		ft_lstadd_back(cmds, ft_lstnew(command));
}

/**
 * print_commands - Prints the list of commands.
 * @cmds: The list of commands.
 *
 * This function iterates through the list of commands and prints each command.
 */
void	print_commands(t_list *cmds)
{
	t_list	*ptr;

	ptr = cmds;
	while (ptr)
	{
		ft_printf("%s\n", ptr->content);
		ptr = ptr->next;
	}
}

/**
 * swap_pivot - Swaps two integer values.
 * @a: Pointer to the first integer.
 * @b: Pointer to the second integer.
 *
 * This helper function swaps the values of two integers.
 */
void	swap_pivot(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
