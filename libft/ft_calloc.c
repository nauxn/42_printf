/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nisim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 17:03:00 by nisim             #+#    #+#             */
/*   Updated: 2026/07/30 11:13:43 by nisim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void			*arr;
	size_t			num;
	unsigned char	*z_arr;

	if (nmemb != 0 && size > ((size_t) - 1 / nmemb))
		return (NULL);
	num = nmemb * size;
	if (num == 0)
		num = 1;
	arr = malloc(num);
	if (arr == NULL)
		return (NULL);
	z_arr = (unsigned char *)arr;
	while (num > 0)
	{
		*z_arr = 0;
		z_arr++;
		num--;
	}
	return (arr);
}
