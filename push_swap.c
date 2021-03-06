/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouddou <ybouddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 14:25:05 by ybouddou          #+#    #+#             */
/*   Updated: 2021/05/05 13:23:30 by ybouddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	c_options(t_push_swap *ps, char ***av)
{
	(*av)++;
	if (!ft_strcmp((*av)[0], "-c"))
	{
		ps->c_option = 1;
		(*av)++;
	}
}

int	main(int ac, char **av)
{
	t_push_swap		ps;

	if (ac == 1)
		return (0);
	ps.stack_a = (t_stack *){0};
	ps.stack_b = (t_stack *){0};
	ps = (t_push_swap){0};
	c_options(&ps, &av);
	create_stack(&ps, av);
	checker(&ps);
	sorting(&ps);
	if (ps.len == 3)
		case_of_three(&ps.stack_a);
	else if (ps.len <= 5)
		case_of_five(&ps);
	else if (ps.len > 5)
		more_than_five(&ps);
	free_stack(&ps.stack_a);
	ft_free(&ps.sorted);
}
