/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabouelw <cabouelw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 14:51:42 by ybouddou          #+#    #+#             */
/*   Updated: 2021/04/12 13:25:02 by cabouelw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	unsigned int	i;
	unsigned int	j;
	char			*copy;

	i = 0;
	j = 0;
	if (!s1)
		return (NULL);
	while (s1[i])
		i++;
	copy = (char *)malloc(sizeof(char) * i + 1);
	if (!copy)
		return (NULL);
	while (j < i)
	{
		copy[j] = s1[j];
		j++;
	}
	copy[j] = '\0';
	return (copy);
}
