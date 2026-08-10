/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nisim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 11:10:06 by nisim             #+#    #+#             */
/*   Updated: 2026/07/29 11:39:20 by nisim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*dst;
	const unsigned char	*str;

	if (!dest && !src)
		return (0);
	dst = (unsigned char *)dest;
	str = (const unsigned char *)src;
	while (n--)
	{
		*dst = *str;
		dst++;
		str++;
	}
	return (dest);
}
