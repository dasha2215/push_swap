#include "push_swap.h"

void	replace_node(t_list **current, char *str)
{
	t_list	*temp;
	char	*tmp;

	tmp = (*current)->content;
	(*current)->content = ft_strdup(str);
	free(tmp);
	temp = (*current)->next;
	(*current)->next = temp->next;
	free(temp->content);
	free(temp);
}

void	replace_commands(t_list **cmds)
{
	t_list	*current;

	current = *cmds;
	while (current && current->next)
	{
		if ((ft_strncmp(current->content, "ra", 2) == 0
				&& ft_strncmp(current->next->content, "rb", 2) == 0)
			|| (ft_strncmp(current->content, "rb", 2) == 0
				&& ft_strncmp(current->next->content, "ra", 2) == 0))
			replace_node(&current, "rr");
		else if ((ft_strncmp(current->content, "sa", 2) == 0
				&& ft_strncmp(current->next->content, "sb", 2) == 0)
			|| (ft_strncmp(current->content, "sb", 2) == 0
				&& ft_strncmp(current->next->content, "sa", 2) == 0))
			replace_node(&current, "ss");
		else if ((ft_strncmp(current->content, "rra", 3) == 0
				&& ft_strncmp(current->next->content, "rrb", 3) == 0)
			|| (ft_strncmp(current->content, "rrb", 3) == 0
				&& ft_strncmp(current->next->content, "rra", 3) == 0))
			replace_node(&current, "rrr");
		else
			current = current->next;
	}
}

int	is_unnecessary_pair(char *cmd1, char *cmd2)
{
	if (ft_strncmp(cmd1, "pa", 2) == 0 && ft_strncmp(cmd2, "pb", 2) == 0)
		return (1);
	else if (ft_strncmp(cmd1, "pb", 2) == 0 && ft_strncmp(cmd2, "pa", 2) == 0)
		return (1);
	else if (ft_strncmp(cmd1, "sa", 2) == 0 && ft_strncmp(cmd2, "sa", 2) == 0)
		return (1);
	else if (ft_strncmp(cmd1, "sb", 2) == 0 && ft_strncmp(cmd2, "sb", 2) == 0)
		return (1);
	else if (ft_strncmp(cmd1, "ra", 2) == 0 && ft_strncmp(cmd2, "rra", 3) == 0)
		return (1);
	else if (ft_strncmp(cmd1, "rra", 3) == 0 && ft_strncmp(cmd2, "ra", 2) == 0)
		return (1);
	else if (ft_strncmp(cmd1, "rb", 2) == 0 && ft_strncmp(cmd2, "rrb", 3) == 0)
		return (1);
	else if (ft_strncmp(cmd1, "rrb", 3) == 0 && ft_strncmp(cmd2, "rb", 2) == 0)
		return (1);
	return (0);
}

void	remove_unnecessary_commands(t_list **cmds)
{
	t_list	*current;
	t_list	*temp1;
	t_list	*temp2;

	current = *cmds;
	while (current && current->next)
	{
		if (is_unnecessary_pair(current->content, current->next->content))
		{
			temp1 = current->next;
			temp2 = temp1->next;
			free(current->content);
			if (temp2)
			{
				current->content = ft_strdup(temp2->content);
				current->next = temp2->next;
				ft_lstdelone(temp2, free);
			}
			else
				current->next = NULL;
			free(temp1->content);
			free(temp1);
		}
		current = current->next;
	}
}

void	optimize_commands(t_list *cmds)
{
	replace_commands(&cmds);
	remove_unnecessary_commands(&cmds);
}
