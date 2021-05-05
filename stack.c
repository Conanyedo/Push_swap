/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouddou <ybouddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 12:55:52 by ybouddou          #+#    #+#             */
/*   Updated: 2021/05/05 13:23:35 by ybouddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack **stack)
{
	t_stack	*prev;

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

void	listtoarray(char ***arr, t_stack *stack)
{
	t_stack		*list;
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

int	stacksize(t_stack *stack)
{
	t_stack	*list;
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

void	split_arg(t_push_swap *ps, t_stack **list, char *arr)
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
		(*list)->next = (t_stack *)malloc(sizeof(t_stack));
		(*list) = (*list)->next;
	}
	ft_free(&split);
}

void	create_stack(t_push_swap *ps, char **av)
{
	t_stack		*list;
	int			i;

	i = 0;
	ps->stack_a = (t_stack *)malloc(sizeof(t_stack));
	ps->stack_a->next = NULL;
	list = ps->stack_a;
	while (av[i])
	{
		split_arg(ps, &list, av[i]);
		i++;
		if (!av[i])
			break ;
		list->next = (t_stack *)malloc(sizeof(t_stack));
		list = list->next;
	}
	list->next = NULL;
	ps->len = stacksize(ps->stack_a);
}
