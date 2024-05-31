/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsiroten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 13:40:09 by dsiroten          #+#    #+#             */
/*   Updated: 2024/05/16 17:04:06 by dsiroten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "lib/ft_printf.h"
# include "lib/libft/libft.h"
# include <stdlib.h>
# include <limits.h>

// Data structure to store push_swap state
typedef struct s_push_swap
{
	int		*stack_a;
	int		*stack_b;
	int		len_a;
	int		len_b;
	int		start;
	t_list	*cmds;
}	t_push_swap;

// Initialization and validation
t_push_swap	*init_push_swap(char **stack);
int			check_stack(t_push_swap *push_swap, char **stack);
char		**parse_stack(char **argv);
int			count_stack_len(char **stack);
int			is_empty_string(char *str);
void		handle_error(int error, t_push_swap *push_swap);

// Memory management
void		free_all(t_push_swap *push_swap);
void		free_stack(char **stack);

// Sorting operations
void		sort_stack(t_push_swap *push_swap);
int			is_stack_sorted(t_push_swap *push_swap, int top);
int			is_top_a_sorted(t_push_swap *push_swap, int len);
void		sort_two(t_push_swap *push_swap);
void		sort_three_a(t_push_swap *push_swap);
void		sort_three_b(t_push_swap *push_swap);
void		sort_five(t_push_swap *push_swap);
void		split_chunk(t_push_swap *push_swap, int len, int chunk);
void		sort_chunk(t_push_swap *push_swap, int len, int chunk, int *chunk_len);
void		sort_chunk_top_a(t_push_swap *push_swap, int len, int *chunk_len);
void		sort_chunk_bottom_a(t_push_swap *push_swap, int len, int *chunk_len);
void		sort_chunk_top_b(t_push_swap *push_swap, int len, int *chunk_len);
void		sort_chunk_bottom_b(t_push_swap *push_swap, int len, int *chunk_len);

// Base case handlers
int			handle_base_case(t_push_swap *push_swap, int chunk, int len);
void		handle_base_case_one(t_push_swap *push_swap, int chunk);
void		handle_base_case_two(t_push_swap *push_swap, int chunk);
void		handle_base_case_three(t_push_swap *push_swap, int chunk);
void		base_case_three_top_a(t_push_swap *push_swap);
void		base_case_three_bottom_a(t_push_swap *push_swap);
void		base_case_three_top_b(t_push_swap *push_swap);
void		base_case_three_bottom_b(t_push_swap *push_swap);

// Helpers for sorting
int			get_case(int len, int min, int max);
void		get_min_max(int *stack, int len, int *min, int *max);
int			get_pivots(int *stack, int len, int *min, int *max);
void		get_pivots_for_ten(int *stack, int len, int *min, int *max);
void		sort_arr_of_ten(int *arr, int len);
void		sort_arr(int *arr, int low, int high);
int			split_arr(int *arr, int low, int high);
void		swap_pivot(int *a, int *b);

// Stack operations
int			swap(int *stack, int len);
int			swap_a(t_push_swap *push_swap);
int			swap_b(t_push_swap *push_swap);
int			swap_s(t_push_swap *push_swap);

int			push(int *stack_from, int *stack_to, int stack_from_len, int stack_to_len);
int			push_a(t_push_swap *push_swap);
int			push_b(t_push_swap *push_swap);

int			rotate(int *stack, int len);
int			rotate_a(t_push_swap *push_swap);
int			rotate_b(t_push_swap *push_swap);
int			rotate_r(t_push_swap *push_swap);

int			reverse_rotate(int *stack, int len);
int			reverse_rotate_a(t_push_swap *push_swap);
int			reverse_rotate_b(t_push_swap *push_swap);
int			reverse_rotate_r(t_push_swap *push_swap);

// Command optimization
void		optimize_commands(t_list *cmds);
void		remove_unnecessary_commands(t_list **cmds);
int			is_unnecessary_pair(char *cmd1, char *cmd2);
void		replace_commands(t_list **cmds);
void		replace_node(t_list **current, char *str);

// Utility functions
char		*join_stack(char *stack, char *str);
void		add_command(t_list **cmds, char *command);
void		print_commands(t_list *cmds);

// Additional helpers for chunk operations
void		from_bottom_a_to_bottom_b(t_push_swap *push_swap, int *chunk_len);
void		from_bottom_a_to_top_b(t_push_swap *push_swap, int *chunk_len);
void		from_bottom_b_to_bottom_a(t_push_swap *push_swap, int *chunk_len);
void		from_bottom_b_to_top_a(t_push_swap *push_swap, int *chunk_len);
void		from_top_b_to_bottom_a(t_push_swap *push_swap, int *chunk_len);

// Index helpers for sorting
int			get_index(t_push_swap *push_swap, int i, int y);
void		insert(t_push_swap *push_swap, int idx0, int idx1);
void		painful_insert(t_push_swap *push_swap, int idx0, int idx1);
void		swap_indexes(t_push_swap *push_swap, int *idx0, int *idx1);

#endif