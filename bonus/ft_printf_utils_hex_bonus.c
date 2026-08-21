/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_hex.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nisim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 13:48:04 by nisim             #+#    #+#             */
/*   Updated: 2026/08/20 17:03:15 by nisim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

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

int	ft_put_up_hex_f(va_list args, t_flags flags)
{
	unsigned int	nb;
	int				prefix;
	int				pad;
	int				count;
	int				zeros;

	nb = va_arg(args, unsigned int);
	prefix = flags.hashtag * 2;
	count = ft_nbrlen(nb, "0123456789ABCDEF", flags);
	if (flags.dot)
		flags.zero = 0;
	zeros = (flags.dot && flags.precision > (count + prefix))
		* (flags.precision - count - prefix);
	pad = flags.width - (count + zeros + prefix);
	if (prefix && nb != 0)
		count += ft_pad_flag(flags, pad, zeros, "0X");
	else
		count += ft_pad_flag(flags, pad, zeros, NULL);
	if (ft_nbrlen(nb, "0123456789ABCDEF", flags) > 0)
		ft_putnbr_base_f(nb, "0123456789ABCDEF");
	if (flags.minus && pad > 0)
		count += ft_pad(' ', pad);
	return (count);
}

int	ft_put_low_hex_f(va_list args, t_flags flags)
{
	unsigned int	nb;
	int				prefix;
	int				pad;
	int				count;
	int				zeros;

	nb = va_arg(args, unsigned int);
	prefix = flags.hashtag * 2;
	count = ft_nbrlen(nb, "0123456789abcdef", flags);
	if (flags.dot)
		flags.zero = 0;
	zeros = 0;
	zeros = (flags.dot && flags.precision > (count + prefix))
		* (flags.precision - count - prefix);
	pad = flags.width - (count + zeros + prefix);
	if (prefix && nb != 0)
		count += ft_pad_flag(flags, pad, zeros, "0x");
	else
		count += ft_pad_flag(flags, pad, zeros, NULL);
	if (ft_nbrlen(nb, "0123456789abcdef", flags) > 0)
		ft_putnbr_base_f(nb, "0123456789abcdef");
	if (flags.minus && pad > 0)
		count += ft_pad(' ', pad);
	return (count);
}

int	ft_putptr_f(va_list args, t_flags flags)
{
	int					len;
	int					count;
	void				*ptr;
	unsigned long long	address;

	ptr = va_arg(args, void *);
	if (!ptr)
		return (ft_putptr_nil(flags));
	address = (unsigned long long)ptr;
	len = ft_nbrlen(address, "0123456789abcdef", flags) + 2;
	count = 0;
	if (!flags.minus)
		count += ft_pad(' ', flags.width - len);
	count += write(1, "0x", 2);
	count += ft_putnbr_base_f(address, "0123456789abcdef");
	if (flags.minus)
		count += ft_pad(' ', flags.width - len);
	return (count);
}

int	ft_nbrlen(unsigned long long nb, char *base, t_flags flags)
{
	int	base_len;
	int	len;

	if (nb == 0)
	{
		if (flags.dot && flags.precision == 0)
			return (0);
		return (1);
	}
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
