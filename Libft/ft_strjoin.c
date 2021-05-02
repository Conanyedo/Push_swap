/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabouelw <cabouelw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 15:16:28 by ybouddou          #+#    #+#             */
/*   Updated: 2021/04/12 13:25:51 by cabouelw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*join;
	int		len1;
	int		len2;

	if (s1 && s2)
	{
		i = 0;
		j = 0;
		len1 = ft_strlen(s1);
		len2 = ft_strlen(s2);
		join = (char *)malloc((len1 + len2 + 1) * sizeof(char));
		if (!join)
			return (NULL);
		while (s1[i])
			join[j++] = s1[i++];
		i = 0;
		while (s2[i])
			join[j++] = s2[i++];
		join[j] = '\0';
		return (join);
	}
	return (NULL);
}
