/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouddou <ybouddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 12:55:52 by ybouddou          #+#    #+#             */
/*   Updated: 2021/05/04 11:36:42 by ybouddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(s_stack **stack)
{
	s_stack	*prev;

	if (!(*stack))
		return ;
	while ((*stack))
	{
		prev = (*stack);
		(*stack) = (*stack)->next;
		free(prev->node);
		free(prev);
	}
}

void	listtoarray(char ***arr, s_stack *stack)
{
	s_stack		*list;
	int			i;

	i = 0;
	(*arr) = (char **)malloc(sizeof(char *) * (stacksize(stack) + 1));
	list = stack;
	while (list)
	{
		(*arr)[i] = ft_strdup(list->node);
		i++;
		list = list->next;
	}
	(*arr)[i] = NULL;
}

int	stacksize(s_stack *stack)
{
	s_stack	*list;
	int		i;

	i = 0;
	list = NULL;
	list = stack;
	while (list)
	{
		i++;
		list = list->next;
	}
	return (i);
}

void	split_arg(s_push_swap *ps, s_stack **list, char *arr)
{
	char	**split;
	int		i;

	i = 0;
	split = ft_strsplit(arr, " ", 0);
	while (split[i])
	{
		if (ps->max_len < (int)ft_strlen(split[i]))
			ps->max_len = (int)ft_strlen(split[i]);
		(*list)->node = ft_strdup(split[i]);
		i++;
		if (!split[i])
			break ;
		(*list)->next = (s_stack *)malloc(sizeof(s_stack));
		(*list) = (*list)->next;
	}
	ft_free(&split);
}

void	create_stack(s_push_swap *ps, char **av)
{
	s_stack		*list;
	int			i;

	i = 0;
	ps->stack_a = (s_stack *)malloc(sizeof(s_stack));
	ps->stack_a->next = NULL;
	list = ps->stack_a;
	while (av[i])
	{
		split_arg(ps, &list, av[i]);
		i++;
		if (!av[i])
			break ;
		list->next = (s_stack *)malloc(sizeof(s_stack));
		list = list->next;
	}
	list->next = NULL;
	ps->len = stacksize(ps->stack_a);
}
