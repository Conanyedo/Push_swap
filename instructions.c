/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouddou <ybouddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 16:18:38 by ybouddou          #+#    #+#             */
/*   Updated: 2021/05/04 12:17:10 by ybouddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	clear(s_push_swap *ps)
{
	int		len;

	len = ps->len + 4;
	if (is_stack_sorted(ps->stack_a) && !ps->stack_b)
		return ;
	sleep(1);
	while (len--)
		ft_putstr_fd("\033[1A\r\033[K", 1);
}

void	instructions(s_push_swap *ps)
{
	if (!ft_strcmp(ps->instruc, "sa"))
		swap(&ps->stack_a, NULL);
	else if (!ft_strcmp(ps->instruc, "sb"))
		swap(&ps->stack_b, NULL);
	else if (!ft_strcmp(ps->instruc, "ss"))
		double_instruc(ps);
	else if (!ft_strcmp(ps->instruc, "pa"))
		push(&ps->stack_b, &ps->stack_a, NULL);
	else if (!ft_strcmp(ps->instruc, "pb"))
		push(&ps->stack_a, &ps->stack_b, NULL);
	else if (!ft_strcmp(ps->instruc, "ra"))
		rotate(&ps->stack_a, NULL);
	else if (!ft_strcmp(ps->instruc, "rb"))
		rotate(&ps->stack_b, NULL);
	else
		instruction(ps);
	if (ps->v_option || ps->s_option)
		print_stacks(ps, ps->instruc);
}

void	instruction(s_push_swap *ps)
{
	if (!ft_strcmp(ps->instruc, "rr"))
		double_instruc(ps);
	else if (!ft_strcmp(ps->instruc, "rra"))
		reverse_rotate(&ps->stack_a, NULL);
	else if (!ft_strcmp(ps->instruc, "rrb"))
		reverse_rotate(&ps->stack_b, NULL);
	else if (!ft_strcmp(ps->instruc, "rrr"))
		double_instruc(ps);
	else if (!*ps->instruc)
	{
		if (is_stack_sorted(ps->stack_a) && !ps->stack_b)
			exit_msg(ps, "OK\033[0m\n", 1, 0);
		else
			exit_msg(ps, "KO\033[0m\n", 1, 1);
	}
	else
		exit_msg(ps, "Error\033[0m\n", 2, 1);
}
