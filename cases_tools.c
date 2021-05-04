/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cases_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouddou <ybouddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 10:53:22 by ybouddou          #+#    #+#             */
/*   Updated: 2021/05/04 11:55:38 by ybouddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_max(s_stack *stack, char **max)
{
	if (!stack)
		return ;
	(*max) = ft_strdup(stack->node);
	while (stack)
	{
		if (ft_atoi((*max)) < ft_atoi(stack->node))
		{
			free(*max);
			(*max) = ft_strdup(stack->node);
		}
		stack = stack->next;
	}
}

int	which_half_equals(s_stack *stack, char *max)
{
	int		len;
	int		i;

	len = stacksize(stack);
	i = 0;
	while (stack)
	{
		if (!ft_strcmp(stack->node, max))
			break ;
		i++;
		stack = stack->next;
	}
	if (i <= (len / 2))
		return (1);
	return (0);
}

int	which_half_smaller(s_stack *stack, char *median)
{
	int		len;
	int		i;

	len = stacksize(stack);
	i = 0;
	while (stack)
	{
		if (ft_atoi(stack->node) < ft_atoi(median))
			break ;
		i++;
		stack = stack->next;
	}
	if (i <= (len / 2))
		return (1);
	return (0);
}

int	smaller_than(s_stack *stack, char *median)
{
	while (stack)
	{
		if (ft_atoi(stack->node) < ft_atoi(median))
			return (1);
		stack = stack->next;
	}
	return (0);
}
