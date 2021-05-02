/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouddou <ybouddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 10:30:50 by ybouddou          #+#    #+#             */
/*   Updated: 2021/04/14 16:27:58 by ybouddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	count_words(t_var *var)
{
	while (var->s[var->i])
	{
		if (var->skip == 0)
		{
			while (var->s[var->i] && !exist(var))
				var->i++;
			var->words++;
			while (var->s[var->i] && exist(var))
				var->i++;
		}
		else
			skipping(var);
	}
}

static int	words_len(t_var *var, int len)
{
	while (var->s[var->i])
	{
		if (var->s[var->i] < 0 && var->s[var->i] != -92 && var->skip)
		{
			var->q = var->s[var->i];
			var->dq = 1 ^ var->dq;
		}
		if (exist(var) && !var->dq)
			return (len);
		else if (var->s[var->i] && var->s[var->i] != var->q
			&& var->dq && var->skip)
		{
			var->i++;
			len++;
			while (var->s[var->i] && var->s[var->i] != var->q)
			{
				len++;
				var->i++;
			}
			var->dq = 0;
		}
		var->i++;
		len++;
	}
	return (len);
}

static void	*leak(t_var *var)
{
	int	i;

	i = 0;
	while (i < var->words)
	{
		free(var->splt[i]);
		i++;
	}
	free(var->splt);
	return (NULL);
}

static char	**fill(t_var *var, int len, int j)
{
	int	i;
	int	old_i;

	i = -1;
	old_i = 0;
	var->splt = (char **)malloc(sizeof(char *) * (var->words + 1));
	if (!var->splt)
		return (NULL);
	while (++i < var->words)
	{
		var->i = old_i;
		while (exist(var))
			var->i++;
		old_i = var->i;
		len = words_len(var, 0);
		var->splt[i] = (char *)malloc(sizeof(char) * (len + 1));
		if (!var->splt[i])
			return (leak(var));
		j = 0;
		while (j < len)
			var->splt[i][j++] = var->s[old_i++];
		var->splt[i][j] = '\0';
	}
	var->splt[i] = NULL;
	return (var->splt);
}

char	**ft_strsplit(char *s, char *c, int skip)
{
	t_var	var;

	if (!s)
		return (NULL);
	var = (t_var){0};
	var.s = s;
	var.token = c;
	var.skip = skip;
	count_words(&var);
	var.i = 0;
	fill(&var, 0, 0);
	return (var.splt);
}
