/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nisim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 13:47:54 by nisim             #+#    #+#             */
/*   Updated: 2026/08/20 20:08:09 by nisim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_putchar_f(va_list args, t_flags flags)
{
	int	c;
	int	count;

	c = va_arg(args, int);
	count = 0;
	if (!flags.minus)
		count += ft_pad(' ', flags.width - 1);
	count += write(1, &c, 1);
	if (flags.minus)
		count += ft_pad(' ', flags.width - 1);
	return (count);
}

int	ft_putstr_f(va_list args, t_flags flags)
{
	char	*str;
	int		str_len;
	int		count;

	str = va_arg(args, char *);
	if (!str)
	{
		if (flags.dot && flags.precision < 6)
			return (0);
		else
			str = "(null)";
	}
	str_len = 0;
	while (str[str_len])
		str_len++;
	if (flags.dot && flags.precision < str_len)
		str_len = flags.precision;
	count = 0;
	if (!flags.minus)
		count += ft_pad(' ', flags.width - str_len);
	count += write(1, str, str_len);
	if (flags.minus)
		count += ft_pad(' ', flags.width - str_len);
	return (count);
}

int	ft_putnbr_f(va_list args, t_flags flags)
{
	unsigned long long	nb;
	char				prefix[2];
	int					count;
	int					pad;
	int					zeros;

	prefix[0] = 0;
	prefix[1] = 0;
	nb = ft_prefix((unsigned long long)va_arg(args, int), flags, prefix);
	count = ft_nbrlen(nb, "0123456789", flags);
	if (flags.dot)
		flags.zero = 0;
	zeros = 0;
	if (flags.dot && flags.precision > count)
		zeros = flags.precision - count;
	pad = flags.width - (count + zeros + (prefix[0] != 0));
	count += ft_pad_flag(flags, pad, zeros, prefix);
	if (ft_nbrlen(nb, "0123456789", flags) > 0)
		ft_putnbr_base_f(nb, "0123456789");
	if (flags.minus && pad > 0)
		count += ft_pad(' ', pad);
	return (count);
}

int	ft_put_u_nbr_f(va_list args, t_flags flags)
{
	unsigned int	nb;
	int				len;
	int				count;
	int				pad;
	int				zeros;

	nb = va_arg(args, unsigned int);
	len = ft_nbrlen(nb, "0123456789", flags);
	if (flags.dot)
		flags.zero = 0;
	zeros = (flags.dot && flags.precision > len) * (flags.precision - len);
	pad = flags.width - (len + zeros);
	count = ft_pad_flag(flags, pad, zeros, NULL);
	if (len > 0)
		count += ft_putnbr_base_f(nb, "0123456789");
	if (flags.minus && pad > 0)
		count += ft_pad(' ', pad);
	return (count);
}

int	ft_putsign_f(va_list args, t_flags flags)
{
	char	p;

	(void)args;
	(void)flags;
	p = '%';
	write(1, &p, 1);
	return (1);
}
