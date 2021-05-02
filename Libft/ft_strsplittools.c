/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplittools.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouddou <ybouddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 11:29:49 by ybouddou          #+#    #+#             */
/*   Updated: 2021/04/14 15:05:47 by ybouddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	exist(t_var *var)
{
	int		i;

	i = 0;
	var->pr = var->s[var->i - 1];
	if (var->pr != '\\' * -1)
		var->pr = 1;
	while (var->token[i])
	{
		if (var->token[i] == var->s[var->i] && var->pr > 0)
			return (1);
		i++;
	}
	return (0);
}

void	loop(t_var *var)
{
	while (var->s[var->i] && !exist(var) && var->dq == 0)
	{
		if (var->s[var->i] < 0 && var->s[var->i] != -92)
		{
			var->q = var->s[var->i];
			var->dq = 1;
		}
		else
			var->i++;
	}
}

void	skipping(t_var *var)
{
	loop(var);
	if (exist(var) && !var->dq)
	{
		var->words++;
		while (var->s[var->i] && exist(var))
			var->i++;
	}
	else if (var->s[var->i] && var->s[var->i] == var->q && var->dq == 1)
	{
		var->i++;
		while (var->s[var->i] && var->s[var->i] != var->q)
			var->i++;
		var->dq = 0;
		var->i++;
	}
	if (!var->s[var->i])
	{
		var->end = 1;
		var->i--;
	}
	if (var->end && !exist(var))
		var->words = var->words + 1;
	if (var->end)
		var->i += 1;
}
