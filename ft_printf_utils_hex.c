/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_hex.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nisim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 13:48:04 by nisim             #+#    #+#             */
/*   Updated: 2026/08/20 19:46:20 by nisim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base_f(unsigned long long n, char *base)
{
	unsigned int	len;
	int				count;

	len = 0;
	count = 0;
	while (base[len] != '\0')
		len++;
	if (n >= len)
		count += ft_putnbr_base_f((n / len), base);
	count += write(1, &base[n % len], 1);
	return (count);
}

int	ft_put_up_hex_f(va_list args)
{
	unsigned int	nb;

	nb = va_arg(args, unsigned int);
	return (ft_putnbr_base_f(nb, "0123456789ABCDEF"));
}

int	ft_put_low_hex_f(va_list args)
{
	unsigned int	nb;

	nb = va_arg(args, unsigned int);
	return (ft_putnbr_base_f(nb, "0123456789abcdef"));
}

int	ft_putptr_f(va_list args)
{
	void				*ptr;
	unsigned long long	address;
	int					count;

	ptr = va_arg(args, void *);
	if (!ptr)
		return (write(1, "(nil)", 5));
	address = (unsigned long long)ptr;
	count = 0;
	count += write(1, "0x", 2);
	count += ft_putnbr_base_f(address, "0123456789abcdef");
	return (count);
}

int	ft_nbrlen(unsigned long long nb, char *base)
{
	int	base_len;
	int	len;

	if (nb == 0)
		return (0);
	base_len = 0;
	while (base[base_len])
		base_len++;
	len = 0;
	while (nb != 0)
	{
		nb /= base_len;
		len++;
	}
	return (len);
}
