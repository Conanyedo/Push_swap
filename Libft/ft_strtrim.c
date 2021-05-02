/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouddou <ybouddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 23:09:09 by ybouddou          #+#    #+#             */
/*   Updated: 2021/04/18 12:22:08 by ybouddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_start(char const *s1, int start, char const *set)
{
	int		i;
	int		s;

	i = 0;
	while (s1[start])
	{
		i = 0;
		s = start;
		while (set[i])
		{
			while (set[i] == s1[start])
				start++;
			i++;
		}
		if (s == start)
			return (start);
	}
	return (start);
}

static	int	ft_end(char const *s1, int end, int start, char const *set)
{
	int		i;
	int		e;

	i = 0;
	e = end;
	while (end > start)
	{
		i = 0;
		e = end;
		while (set[i])
		{
			while (set[i] == s1[end] && s1[end - 1] != -92)
				end--;
			i++;
		}
		if (e == end)
			return (end);
	}
	return (end);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*ptr;
	int		i;

	if (!s1)
		return (NULL);
	start = 0;
	start = ft_start(s1, start, set);
	if (!s1[start])
		return (ft_strdup(""));
	end = ft_strlen(s1) - 1;
	end = ft_end(s1, end, start, set);
	i = end - start + 1;
	ptr = (char *)malloc(sizeof(char) * i + 1);
	if (!ptr)
		return (NULL);
	i = 0;
	while (start <= end)
		ptr[i++] = s1[start++];
	ptr[i] = '\0';
	return (ptr);
}
