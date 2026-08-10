/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nisim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 15:11:59 by nisim             #+#    #+#             */
/*   Updated: 2026/08/01 14:41:07 by nisim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isin_set(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	stop;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && ft_isin_set(s1[start], set))
		start++;
	stop = ft_strlen(s1);
	while (stop > start && ft_isin_set(s1[stop - 1], set))
		stop--;
	return (ft_substr(s1, start, (stop - start)));
}
