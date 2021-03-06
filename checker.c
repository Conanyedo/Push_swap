/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouddou <ybouddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 14:25:02 by ybouddou          #+#    #+#             */
/*   Updated: 2021/05/05 13:23:28 by ybouddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	options(t_push_swap *ps, char ***av)
{
	(*av)++;
	if (!ft_strcmp((*av)[0], "-c"))
	{
		ps->c_option = 1;
		(*av)++;
	}
	if (!ft_strcmp((*av)[0], "-v"))
	{
		ps->v_option = 1;
		(*av)++;
	}
	else if (!ft_strcmp((*av)[0], "-s"))
	{
		ps->s_option = 1;
		(*av)++;
	}
	if (!ft_strcmp((*av)[0], "-c") && !ps->c_option)
	{
		ps->c_option = 1;
		(*av)++;
	}
}

int	main(int ac, char **av)
{
	t_push_swap	ps;

	if (ac == 1)
		return (0);
	ps.stack_a = (t_stack *){0};
	ps.stack_b = (t_stack *){0};
	ps = (t_push_swap){0};
	options(&ps, &av);
	if (!av[0])
		return (0);
	create_stack(&ps, av);
	checker(&ps);
	if (ps.v_option || ps.s_option)
		print_stacks(&ps, "Args");
	while (1)
	{
		get_next_line(0, &ps.instruc);
		instructions(&ps);
		free(ps.instruc);
		ps.instruc = NULL;
	}
	return (0);
}
