/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouddou <ybouddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 11:25:37 by ybouddou          #+#    #+#             */
/*   Updated: 2021/05/04 11:41:54 by ybouddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	double_instruc(s_push_swap *ps)
{
	if (!ft_strcmp(ps->instruc, "ss"))
	{
		swap(&ps->stack_a, NULL);
		swap(&ps->stack_b, NULL);
	}
	else if (!ft_strcmp(ps->instruc, "rr"))
	{
		rotate(&ps->stack_a, NULL);
		rotate(&ps->stack_b, NULL);
	}
	else if (!ft_strcmp(ps->instruc, "rrr"))
	{
		reverse_rotate(&ps->stack_a, NULL);
		reverse_rotate(&ps->stack_b, NULL);
	}
}

void	swap(s_stack **stack, char *output)
{
	s_stack	*list;
	char	*tmp;

	if (!(*stack) || !(*stack)->next)
		return ;
	list = *stack;
	tmp = ft_strdup(list->node);
	free(list->node);
	list->node = ft_strdup(list->next->node);
	free(list->next->node);
	list->next->node = ft_strdup(tmp);
	free(tmp);
	if (output)
		ft_putstr_fd(output, 1);
}

void	push(s_stack **pop, s_stack **push, char *output)
{
	s_stack		*tmp;
	s_stack		*node;

	if (!*pop)
		return ;
	tmp = (*pop);
	(*pop) = (*pop)->next;
	node = (s_stack *)malloc(sizeof(s_stack));
	node->node = ft_strdup(tmp->node);
	node->next = (*push);
	(*push) = node;
	free(tmp->node);
	free(tmp);
	if (output)
		ft_putstr_fd(output, 1);
}

void	rotate(s_stack **stack, char *output)
{
	s_stack		*node;
	s_stack		*last;
	s_stack		*tmp;

	if (!*stack || !(*stack)->next)
		return ;
	tmp = (*stack);
	(*stack) = (*stack)->next;
	node = (s_stack *)malloc(sizeof(s_stack));
	node->node = ft_strdup(tmp->node);
	node->next = NULL;
	last = (*stack);
	while (last->next)
		last = last->next;
	last->next = node;
	free(tmp->node);
	free(tmp);
	if (output)
		ft_putstr_fd(output, 1);
}

void	reverse_rotate(s_stack **stack, char *output)
{
	s_stack		*node;
	s_stack		*last;
	s_stack		*prev;

	if (!*stack || !(*stack)->next)
		return ;
	last = (*stack);
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	node = (s_stack *)malloc(sizeof(s_stack));
	node->node = ft_strdup(last->node);
	node->next = (*stack);
	(*stack) = node;
	free(last->node);
	free(last);
	if (output)
		ft_putstr_fd(output, 1);
}
