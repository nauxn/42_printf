/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nisim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 16:08:08 by nisim             #+#    #+#             */
/*   Updated: 2026/08/20 15:43:41 by nisim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_isin_spec(char c)
{
	char	*specifier;
	int		i;

	specifier = "cspdiuxX%";
	i = 0;
	while (specifier[i])
	{
		if (specifier[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_isin_flag(char c)
{
	char	*flag;
	int		i;

	flag = "-+ 0#.*";
	i = 0;
	while (flag[i])
	{
		if (flag[i] == c)
			return (1);
		if (c >= '1' && c <= '9')
			return (1);
		i++;
	}
	return (0);
}

t_flags	ft_init_flag(void)
{
	t_flags	flag;

	flag.minus = 0;
	flag.zero = 0;
	flag.dot = 0;
	flag.hashtag = 0;
	flag.space = 0;
	flag.plus = 0;
	flag.width = 0;
	flag.precision = 0;
	return (flag);
}

int	ft_pad(char c, int count)
{
	int	i;

	if (count <= 0)
		return (0);
	i = count;
	while (i--)
		write(1, &c, 1);
	return (count);
}

long	ft_prefix(long nbr, t_flags flags, char *prefix)
{
	prefix[0] = 0;
	if (nbr < 0)
	{
		prefix[0] = '-';
		return (-nbr);
	}
	if (flags.plus)
		prefix[0] = '+';
	else if (flags.space)
		prefix[0] = ' ';
	return (nbr);
}
