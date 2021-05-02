/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cases.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouddou <ybouddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 15:00:59 by ybouddou          #+#    #+#             */
/*   Updated: 2021/05/02 16:10:46 by ybouddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	case_of_two(s_push_swap *ps)
{
	ps->num = 0;
	if (ft_atoi(ps->stack_a->node) > ft_atoi(ps->stack_a->next->node))
		swap(&ps->stack_a, "sa\n");
}

void	case_of_three(s_stack **stack)
{
	if ((ft_atoi((*stack)->node) < ft_atoi((*stack)->next->node) && \
		(ft_atoi((*stack)->next->node) > ft_atoi((*stack)->next->next->node))) && \
		(ft_atoi((*stack)->next->next->node) > ft_atoi((*stack)->node)))
	{
		reverse_rotate(stack, "rra\n");
		swap(stack, "sa\n");
	}
	else if ((ft_atoi((*stack)->node) > ft_atoi((*stack)->next->node) && \
		(ft_atoi((*stack)->next->node) < ft_atoi((*stack)->next->next->node))) && \
		(ft_atoi((*stack)->next->next->node) > ft_atoi((*stack)->node)))
		swap(stack, "sa\n");
	else if ((ft_atoi((*stack)->node) < ft_atoi((*stack)->next->node) && \
		(ft_atoi((*stack)->next->node) > ft_atoi((*stack)->next->next->node))))
		reverse_rotate(stack, "rra\n");
	else if ((ft_atoi((*stack)->node) > ft_atoi((*stack)->next->node) && \
		(ft_atoi((*stack)->next->node) < ft_atoi((*stack)->next->next->node))))
		rotate(stack, "ra\n");
	else if ((ft_atoi((*stack)->node) > ft_atoi((*stack)->next->node) && \
		(ft_atoi((*stack)->next->node) > ft_atoi((*stack)->next->next->node))))
	{
		rotate(stack, "ra\n");
		swap(stack, "sa\n");
	}
}

void	case_of_four(s_push_swap *ps)
{
	char	*pivot;
	int		i;

	i = -1;
	pivot = ft_strdup(ps->sorted[(ps->len / 2) - 1]);
	listtoarray(&ps->stack, ps->stack_a);
	while (ps->stack[++i])
	{
		if (ft_atoi(ps->stack[i]) < ft_atoi(pivot))
		{
			push(&ps->stack_a, &ps->stack_b, "pb\n");
			break ;
		}
		else
			rotate(&ps->stack_a, "ra\n");
	}
	free(pivot);
	ft_free(&ps->stack);
	case_of_three(&ps->stack_a);
	push(&ps->stack_b, &ps->stack_a, "pa\n");
}

void	loop_stack(s_push_swap *ps, char *pivot, int len)
{
	int		i;

	i = -1;
	while (ps->stack[++i])
	{
		if (ft_atoi(ps->stack[i]) < ft_atoi(pivot))
		{
			len--;
			push(&ps->stack_a, &ps->stack_b, "pb\n");
			if (!len)
				break ;
		}
		else
			rotate(&ps->stack_a, "ra\n");
	}
}

void	case_of_five(s_push_swap *ps)
{
	char	*pivot;
	int		len;

	len = 1;
	if (ps->len == 5)
		len = 2;
	pivot = ft_strdup(ps->sorted[len]);
	listtoarray(&ps->stack, ps->stack_a);
	loop_stack(ps, pivot, len);
	free(pivot);
	ft_free(&ps->stack);
	case_of_three(&ps->stack_a);
	while (len--)
		push(&ps->stack_b, &ps->stack_a, "pa\n");
	case_of_two(ps);
}

void	case_of_hundred(s_push_swap *ps)
{
	int			chunks;
	int			i;
	s_median	*list;

	chunks = ps->len / 5;
	ps->median = (s_median *)malloc(sizeof(s_median));
	ps->median->next = NULL;
	list = ps->median;
	i = 0;
	while (i < ps->len)
	{
		i += 5;
		list->med = ft_strdup(ps->sorted[i - 3]);
		list->max = ft_strdup(ps->sorted[i - 1]);
		if (i > ps->len)
			break ;
		list->next = (s_median *)malloc(sizeof(s_median));
		list = list->next;
	}
	list->next = NULL;
}