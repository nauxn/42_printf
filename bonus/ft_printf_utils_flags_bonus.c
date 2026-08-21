/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_flags.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nisim <nisim@student.42penang.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 16:42:22 by nisim             #+#    #+#             */
/*   Updated: 2026/08/20 17:02:12 by nisim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_pad_flag(t_flags flags, int pad, int zeros, char *prefix)
{
	int	prefix_len;
	int	count;

	count = 0;
	if (!flags.minus && !flags.zero && pad > 0)
		count += ft_pad(' ', pad);
	if (prefix)
	{
		prefix_len = 0;
		while (prefix[prefix_len])
			prefix_len++;
		if (prefix_len > 0)
			count += write(1, prefix, prefix_len);
	}
	if (!flags.minus && flags.zero && pad > 0)
		count += ft_pad('0', pad);
	if (zeros > 0)
		count += ft_pad('0', zeros);
	return (count);
}

int	ft_putptr_nil(t_flags flags)
{
	char	*str;
	int		count;
	int		i;

	if (flags.dot && flags.precision < 5)
		return (0);
	str = "(nil)";
	i = 0;
	count = 0;
	if (!flags.minus)
		count += ft_pad(' ', flags.width - 5);
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
		count++;
	}
	if (flags.minus)
		count += ft_pad(' ', flags.width - 5);
	return (count);
}
