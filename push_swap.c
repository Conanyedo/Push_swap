/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouddou <ybouddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 14:25:05 by ybouddou          #+#    #+#             */
/*   Updated: 2021/05/02 15:42:18 by ybouddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	s_push_swap		ps;

	if (ac == 1)
		return (0);
	ps.stack_a = (s_stack *){0};
	ps.stack_b = (s_stack *){0};
	ps = (s_push_swap){0};
	av++;
	create_stack(&ps, av);
	checker(&ps);
	sorting(&ps);
	if (ps.len == 2)
		case_of_two(&ps);
	else if (ps.len == 3)
		case_of_three(&ps.stack_a);
	else if (ps.len <= 5)
		case_of_five(&ps);
	else if (ps.len == 100)
		case_of_hundred(&ps);
	free_stack(&ps.stack_a);
	ft_free(&ps.sorted);
}
