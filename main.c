#include "push_swap.h"

/**
 * init_push_swap - Initializes the push_swap structure.
 * @stack: The initial stack array.
 *
 * This function allocates memory for and initializes the push_swap structure.
 * It sets up the stack arrays and other necessary metadata.
 *
 * Return: A pointer to the initialized push_swap structure, or NULL on failure.
 */
t_push_swap	*init_push_swap(char **stack)
{
	t_push_swap	*push_swap;

	push_swap = malloc(sizeof(t_push_swap));
	if (!push_swap)
		return (NULL);
	push_swap->len_a = count_stack_len(stack);
	push_swap->stack_a = malloc(push_swap->len_a * sizeof(int));
	if (!push_swap->stack_a)
	{
		free(push_swap);
		return (NULL);
	}
	push_swap->stack_b = ft_calloc(push_swap->len_a, sizeof(int));
	if (!push_swap->stack_b)
	{
		free_all(push_swap);
		return (NULL);
	}
	push_swap->len_b = 0;
	push_swap->start = 0;
	push_swap->cmds = NULL;
	return (push_swap);
}

/**
 * check_stack - Validates and converts the stack input to integers.
 * @push_swap: The push_swap structure containing the stacks and metadata.
 * @stack: The stack input as an array of strings.
 *
 * This function validates the stack input, converts it to integers, and stores
 * it in the push_swap structure. It checks for duplicates and invalid values.
 *
 * Return: 1 if the stack is valid, 0 otherwise.
 */
int	check_stack(t_push_swap *push_swap, char **stack)
{
	long int	n;
	int			i;
	int			j;

	n = 0;
	i = 0;
	while (i < push_swap->len_a)
	{
		n = ft_atoi(stack[i]);
		if (ft_strncmp(stack[i], "0", ft_strlen(stack[i])) != 0 && n == 0)
			return (0);
		j = 0;
		while (j < i)
		{
			if (push_swap->stack_a[j++] == n)
				return (0);
		}
		push_swap->stack_a[i++] = n;
	}
	return (1);
}

/**
 * parse_stack - Parses the input arguments into a 2D char array.
 * @argv: The input arguments.
 *
 * This function concatenates the input arguments into a single string, splits
 * it into a 2D char array, and handles any empty string errors.
 *
 * Return: A 2D char array representing the stack, or NULL on failure.
 */
char	**parse_stack(char **argv)
{
	char	**stack;
	char	*stack_temp;

	if (is_empty_string(*argv))
		handle_error(0, NULL);
	stack_temp = ft_strdup(*(argv++));
	if (!stack_temp)
		return (0);
	while (*argv)
	{
		if (is_empty_string(*argv))
		{
			free(stack_temp);
			handle_error(0, NULL);
		}
		stack_temp = join_stack(stack_temp, *argv);
		if (!stack_temp)
			return (0);
		argv++;
	}
	stack = ft_split(stack_temp, ' ');
	free(stack_temp);
	if (!stack)
		return (0);
	return (stack);
}

/**
 * count_stack_len - Counts the number of elements in a stack.
 * @stack: The stack array.
 *
 * This function counts the number of elements in the stack array.
 *
 * Return: The number of elements in the stack.
 */
int	count_stack_len(char **stack)
{
	int	len;

	len = 0;
	while (stack[len])
		len++;
	return (len);
}

/**
 * main - The main function for the push_swap program.
 * @argc: The argument count.
 * @argv: The argument vector.
 *
 * This function initializes the program, parses the input, validates the stack,
 * and performs the sorting algorithm. It also handles errors and memory cleanup.
 *
 * Return: 0 on successful execution.
 */
int	main(int argc, char **argv)
{
	t_push_swap	*push_swap;
	char		**stack;

	if (argc < 2)
		return (0);
	stack = parse_stack(++argv);
	if (!stack)
		return (0);
	push_swap = init_push_swap(stack);
	if (!push_swap)
		return (0);
	if (!check_stack(push_swap, stack))
	{
		free_stack(stack);
		handle_error(1, push_swap);
	}
	free_stack(stack);
	sort_stack(push_swap);
	print_commands(push_swap->cmds);
	free_all(push_swap);
	return (0);
}
