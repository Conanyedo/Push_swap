/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouddou <ybouddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 14:20:59 by ybouddou          #+#    #+#             */
/*   Updated: 2021/05/02 16:04:36 by ybouddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "Libft/libft.h"
#include <unistd.h>
#include <stdlib.h>

typedef struct	t_median
{
	char			*med;
	char			*max;
	struct t_median	*next;
}				s_median;

typedef struct	t_stack
{
	char			*node;
	struct t_stack	*next;
}				s_stack;

typedef struct	t_push_swap
{
	s_stack		*stack_a;
	s_stack		*stack_b;
	s_median	*median;
	char		**stack;
	char		**sorted;
	char		*instruc;
	int			len;
	int			max_len;
	int			num;
	int			v_option;
	int			s_option;
}				s_push_swap;


//Checking
void	checker(s_push_swap *ps);
int		is_digit(char *str);
int		is_dup(s_stack *stack, char *str);
void	ft_free(char ***arr);

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

//Sorting
void	sorting(s_push_swap *ps);
void	quicksort(char ***arr, int l, int r);
int		partition(char ***arr, int l, int r);
void	swaping(char ***arr, int i, int j);
int		is_sorted(char **arr);
int		is_stack_sorted(s_stack *stack);

//Cases
void	case_of_two(s_push_swap *ps);
void	case_of_three(s_stack **stack);
void	case_of_four(s_push_swap *ps);
void	case_of_five(s_push_swap *ps);
void	case_of_hundred(s_push_swap *ps);

//Utils
void	print_stacks(s_push_swap *ps, char *instruc);
void	exit_msg(s_push_swap *ps, char *str, int fd, int status);

#endif