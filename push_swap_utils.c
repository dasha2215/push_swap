#include "push_swap.h"

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

void	add_command(t_list **cmds, char *command)
{
	if (*cmds == NULL)
		*cmds = ft_lstnew(command);
	else
		ft_lstadd_back(cmds, ft_lstnew(command));
}

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

void	swap_pivot(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
