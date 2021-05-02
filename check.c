/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouddou <ybouddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 12:00:41 by ybouddou          #+#    #+#             */
/*   Updated: 2021/05/02 14:32:30 by ybouddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(char **arr)
{
	int		i;

	i = 0;
	while (arr[i])
	{
		if (!arr[i + 1])
			return (1);
		if (ft_atoi(arr[i]) > ft_atoi(arr[i + 1]))
			return (0);
		i++;
	}
	return (1);
}

int	is_stack_sorted(s_stack *stack)
{
	s_stack		*list;

	list = stack;
	if (!stack)
		return (0);
	while (stack)
	{
		if (!stack->next)
			return (1);
		if (ft_atoi(stack->node) > ft_atoi(stack->next->node))
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	is_dup(s_stack *stack, char *str)
{
	s_stack		*list;
	int			c;

	c = 0;
	list = stack;
	while (list)
	{
		if (!ft_strcmp(list->node, str) && !c)
			c++;
		else if (!ft_strcmp(list->node, str) && c)
			return (0);
		list = list->next;
	}
	return (1);
}

int	is_digit(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

void	checker(s_push_swap *ps)
{
	s_stack		*list;

	list = ps->stack_a;
	while (list)
	{
		if (!is_digit(list->node) || !is_dup(ps->stack_a, list->node))
		{
			ft_putstr_fd("\033[1;31mError\033[0m\n", 2);
			free_stack(&ps->stack_a);
			exit (1);
		}
		if ((ft_atoi(list->node) < 0 && *list->node != '-') || \
			((ft_atoi(list->node) > 0 && *list->node == '-')))
		{
			ft_putstr_fd("\033[1;31mError\033[0m\n", 2);
			free_stack(&ps->stack_a);
			exit (1);
		}
		list = list->next;
	}
}
