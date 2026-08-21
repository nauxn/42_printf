/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nisim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 13:47:54 by nisim             #+#    #+#             */
/*   Updated: 2026/08/20 19:44:27 by nisim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_f(va_list args)
{
	int	c;

	c = va_arg(args, int);
	write(1, &c, 1);
	return (1);
}

int	ft_putstr_f(va_list args)
{
	char	*str;
	int		str_len;

	str = va_arg(args, char *);
	if (!str)
		str = "(null)";
	str_len = 0;
	while (str[str_len])
		str_len++;
	write(1, str, str_len);
	return (str_len);
}

int	ft_putnbr_f(va_list args)
{
	long	nb;
	int		count;

	nb = va_arg(args, int);
	count = 0;
	if (nb < 0)
	{
		count += write (1, "-", 1);
		nb = -nb;
	}
	count += ft_putnbr_base_f((unsigned long)nb, "0123456789");
	return (count);
}

int	ft_put_u_nbr_f(va_list args)
{
	unsigned int	nb;

	nb = va_arg(args, unsigned int);
	return (ft_putnbr_base_f(nb, "0123456789"));
}

int	ft_putsign_f(va_list args)
{
	char	p;

	(void)args;
	p = '%';
	write(1, &p, 1);
	return (1);
}
