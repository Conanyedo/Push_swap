/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouddou <ybouddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 14:20:59 by ybouddou          #+#    #+#             */
/*   Updated: 2021/05/04 12:19:29 by ybouddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "Libft/libft.h"
#include <unistd.h>
#include <stdlib.h>
#include<stdio.h>

typedef struct	t_stack
{
	char			*node;
	struct t_stack	*next;
}				s_stack;

typedef struct	t_push_swap
{
	s_stack		*stack_a;
	s_stack		*stack_b;
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
}				s_push_swap;


//Checking
void	checker(s_push_swap *ps);
int		is_digit(char *str);
int		is_dup(s_stack *stack, char *str);
void	ft_free(char ***arr);
void	options(s_push_swap *ps, char ***av);
void	c_options(s_push_swap *ps, char ***av);

//Stack
void	listtoarray(char ***arr, s_stack *stack);
void	create_stack(s_push_swap *ps, char **av);
void	split_arg(s_push_swap *ps, s_stack **list, char *arr);
int		stacksize(s_stack *stack);
void	free_stack(s_stack **stack);

//Instructions
void	instructions(s_push_swap *ps);
void	instruction(s_push_swap *ps);
void	swap(s_stack **stack, char *output);
void	push(s_stack **pop, s_stack **push, char *output);
void	rotate(s_stack **stack, char *output);
void	reverse_rotate(s_stack **stack, char *output);
void	double_instruc(s_push_swap *ps);

//Sorting
void	sorting(s_push_swap *ps);
void	quicksort(char ***arr, int l, int r);
int		partition(char ***arr, int l, int r);
void	swaping(char ***arr, int i, int j);
int		is_sorted(char **arr);
int		is_stack_sorted(s_stack *stack);

//Cases
void	case_of_three(s_stack **stack);
void	case_of_five(s_push_swap *ps);
void	more_than_five(s_push_swap *ps);

//Cases_tools
void	get_max(s_stack *stack, char **max);
int		which_half_equals(s_stack *stack, char *max);
int		which_half_smaller(s_stack *stack, char *median);
int		smaller_than(s_stack *stack, char *median);


//Utils
void	print_stacks(s_push_swap *ps, char *instruc);
void	exit_msg(s_push_swap *ps, char *str, int fd, int status);
void	clear(s_push_swap *ps);

#endif