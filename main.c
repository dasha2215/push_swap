#include "push_swap.h"

// Initializes the push_swap structure
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

// Checks if stack is valid and saves it into an integer array
// within push_swap structure
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

// Parses input into a 2D char array
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

// Returns the length of stack
int	count_stack_len(char **stack)
{
	int	len;

	len = 0;
	while (stack[len])
		len++;
	return (len);
}

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
