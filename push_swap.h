/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouddou <ybouddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 14:20:59 by ybouddou          #+#    #+#             */
/*   Updated: 2021/05/05 13:25:50 by ybouddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "Libft/libft.h"

typedef struct s_stack
{
	char			*node;
	struct s_stack	*next;
}				t_stack;

typedef struct s_push_swap
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	char		**medians;
	int			median;
	char		**stack;
	char		**sorted;
	char		*instruc;
	int			len;
	int			max_len;
	int			add;
	int			div;
	char		*max;
	int			v_option;
	int			s_option;
	int			c_option;
}				t_push_swap;

//Checking
void	checker(t_push_swap *ps);
int		is_digit(char *str);
int		is_dup(t_stack *stack, char *str);
void	ft_free(char ***arr);
void	options(t_push_swap *ps, char ***av);
void	c_options(t_push_swap *ps, char ***av);

//Stack
void	listtoarray(char ***arr, t_stack *stack);
void	create_stack(t_push_swap *ps, char **av);
void	split_arg(t_push_swap *ps, t_stack **list, char *arr);
int		stacksize(t_stack *stack);
void	free_stack(t_stack **stack);

//Instructions
void	instructions(t_push_swap *ps);
void	instruction(t_push_swap *ps);
void	swap(t_stack **stack, char *output);
void	push(t_stack **pop, t_stack **push, char *output);
void	rotate(t_stack **stack, char *output);
void	reverse_rotate(t_stack **stack, char *output);
void	double_instruc(t_push_swap *ps);

//Sorting
void	sorting(t_push_swap *ps);
void	quicksort(char ***arr, int l, int r);
int		partition(char ***arr, int l, int r);
void	swaping(char ***arr, int i, int j);
int		is_sorted(char **arr);
int		it_stack_sorted(t_stack *stack);

//Cases
void	case_of_three(t_stack **stack);
void	case_of_five(t_push_swap *ps);
void	more_than_five(t_push_swap *ps);

//Cases_tools
void	get_max(t_stack *stack, char **max);
int		which_half_equals(t_stack *stack, char *max);
int		which_half_smaller(t_stack *stack, char *median);
int		smaller_than(t_stack *stack, char *median);

//Utils
void	print_stacks(t_push_swap *ps, char *instruc);
void	exit_msg(t_push_swap *ps, char *str, int fd, int status);
void	clear(t_push_swap *ps);

#endif