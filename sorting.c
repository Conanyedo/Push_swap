/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouddou <ybouddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 11:59:35 by ybouddou          #+#    #+#             */
/*   Updated: 2021/05/05 13:23:34 by ybouddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free(char ***arr)
{
	int		i;

	i = 0;
	while ((*arr) && (*arr)[i])
	{
		if ((*arr)[i])
			free((*arr)[i]);
		(*arr)[i] = NULL;
		i++;
	}
	if ((*arr))
		free((*arr));
	(*arr) = NULL;
}

void	swaping(char ***arr, int i, int j)
{
	char	*tmp;

	tmp = ft_strdup((*arr)[i]);
	free((*arr)[i]);
	(*arr)[i] = ft_strdup((*arr)[j]);
	free((*arr)[j]);
	(*arr)[j] = ft_strdup(tmp);
	free(tmp);
}

int	partition(char ***arr, int l, int r)
{
	char	*pivot;
	int		i;
	int		j;

	pivot = ft_strdup((*arr)[r]);
	i = l - 1;
	j = i;
	while ((*arr)[++j])
	{
		if (ft_atoi((*arr)[j]) < ft_atoi(pivot))
		{
			i++;
			swaping(arr, i, j);
		}
	}
	swaping(arr, i + 1, r);
	free(pivot);
	return (i + 1);
}

void	quicksort(char ***arr, int l, int r)
{
	int		pivot;

	if (l >= r)
		return ;
	pivot = partition(arr, l, r);
	quicksort(arr, l, pivot - 1);
	quicksort(arr, pivot + 1, r);
}

void	sorting(t_push_swap *ps)
{
	t_stack		*list;
	int			len;

	if (ps->len == 1 || it_stack_sorted(ps->stack_a))
	{
		free_stack(&ps->stack_a);
		exit (0);
	}
	len = 0;
	ps->sorted = (char **)malloc(sizeof(char *) * (ps->len + 1));
	list = ps->stack_a;
	while (list)
	{
		ps->sorted[len] = ft_strdup(list->node);
		len++;
		list = list->next;
	}
	ps->sorted[len] = NULL;
	quicksort(&ps->sorted, 0, len - 1);
}
