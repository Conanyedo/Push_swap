/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouddou <ybouddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 17:45:37 by ybouddou          #+#    #+#             */
/*   Updated: 2021/05/04 12:41:33 by ybouddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_msg(s_push_swap *ps, char *str, int fd, int status)
{
	if (ps->c_option && *str == 'O')
		ft_putstr_fd("\033[1;32m", fd);
	else if (ps->c_option)
		ft_putstr_fd("\033[1;31m", fd);
	ft_putstr_fd(str, fd);
	free_stack(&ps->stack_a);
	free_stack(&ps->stack_b);
	exit (status);
}

void	print_instruc(s_push_swap *ps, char *instruc)
{
	int		max;

	max = ps->max_len;
	while (max--)
		ft_putstr_fd("\033[1;36m-", 1);
	ft_putstr_fd("\033[1;32m", 1);
	ft_putstr_fd(instruc, 1);
	if (ft_strlen(instruc) == 2)
		ft_putstr_fd(" ", 1);
	max = ps->max_len;
	while (max--)
		ft_putstr_fd("\033[1;36m-", 1);
	ft_putstr_fd("\033[0m\n", 1);
}

void	print_separation(s_push_swap *ps, int max)
{
	max = ps->max_len;
	while (max--)
		ft_putstr_fd("\033[1;36m-", 1);
	ft_putstr_fd(" | ", 1);
	max = ps->max_len;
	while (max--)
		ft_putstr_fd("-", 1);
	ft_putstr_fd("\033[0m\n", 1);
	ft_putstr_fd("\033[1;32mA", 1);
	max = ps->max_len - 1;
	while (max--)
		ft_putstr_fd(" ", 1);
	ft_putstr_fd("\033[1;36m | ", 1);
	ft_putstr_fd("\033[1;32mB\n", 1);
	max = (ps->max_len * 2) + 3;
	while (max--)
		ft_putstr_fd("\033[1;36m-", 1);
	ft_putstr_fd("\033[0m\n", 1);
}

void	print_stack_b(s_push_swap *ps, s_stack **stack_b, int len, int max)
{
	while (max--)
		ft_putstr_fd(" ", 1);
	ft_putstr_fd(" | ", 1);
	if ((*stack_b) && len <= stacksize(ps->stack_b))
	{
		ft_putstr_fd((*stack_b)->node, 1);
		(*stack_b) = (*stack_b)->next;
	}
	ft_putstr_fd("\n", 1);
}

void	print_stacks(s_push_swap *ps, char *instruc)
{
	s_stack		*stack_a;
	s_stack		*stack_b;
	int			len;
	int			max;

	len = ps->len + 1;
	stack_a = ps->stack_a;
	stack_b = ps->stack_b;
	print_instruc(ps, instruc);
	while (--len)
	{
		max = ps->max_len;
		if (stack_a && len <= stacksize(ps->stack_a))
		{
			max = ps->max_len - ft_strlen(stack_a->node);
			ft_putstr_fd(stack_a->node, 1);
			stack_a = stack_a->next;
		}
		print_stack_b(ps, &stack_b, len, max);
	}
	print_separation(ps, max);
	if (ps->s_option)
		clear(ps);
}
