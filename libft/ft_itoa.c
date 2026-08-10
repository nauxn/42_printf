/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nisim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 12:09:06 by nisim             #+#    #+#             */
/*   Updated: 2026/07/31 15:02:06 by nisim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_lencount(long n)
{
	int	count;

	count = 1;
	if (n < 0)
	{
		count++;
		n = -n;
	}
	if (n >= 10)
		count += ft_lencount(n / 10);
	return (count);
}

static int	ft_nbrstr(long nbr, int i, char *str)
{
	if (nbr >= 10)
		i = ft_nbrstr((nbr / 10), i, str);
	str[i] = (nbr % 10) + '0';
	return (i + 1);
}

char	*ft_itoa(int n)
{
	int		i;
	long	nbr;
	char	*str;

	i = 0;
	nbr = n;
	str = malloc(sizeof(char) * (ft_lencount(nbr) + 1));
	if (!str)
		return (NULL);
	if (nbr < 0)
	{
		str[i] = '-';
		i++;
		nbr = -nbr;
	}
	i = ft_nbrstr(nbr, i, str);
	str[i] = '\0';
	return (str);
}
