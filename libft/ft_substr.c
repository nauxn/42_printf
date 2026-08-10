/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nisim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 12:07:41 by nisim             #+#    #+#             */
/*   Updated: 2026/07/31 13:20:21 by nisim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strldup(const char *s, size_t len)
{
	size_t	i;
	char	*str;

	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	sub;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
		i++;
	if (start >= i)
		return (ft_strldup("", 0));
	sub = i - (size_t)start;
	if (sub > len)
		sub = len;
	return (ft_strldup(&s[start], sub));
}
