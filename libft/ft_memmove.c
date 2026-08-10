/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nisim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 11:39:26 by nisim             #+#    #+#             */
/*   Updated: 2026/07/29 18:21:13 by nisim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*dst;
	const unsigned char	*str;

	if (!dest && !src)
		return (0);
	dst = (unsigned char *)dest;
	str = (const unsigned char *)src;
	if (dst > str)
	{
		while (n > 0)
		{
			n--;
			dst[n] = str[n];
		}
	}
	else
	{
		while (n--)
		{
			*dst = *str;
			dst++;
			str++;
		}
	}
	return (dest);
}
