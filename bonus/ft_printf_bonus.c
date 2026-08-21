/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nisim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 15:03:51 by nisim             #+#    #+#             */
/*   Updated: 2026/08/20 20:18:25 by nisim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_parse_number(const char **str)
{
	int	num;

	num = 0;
	while (**str >= '0' && **str <= '9')
	{
		num = (num * 10) + (**str - '0');
		(*str)++;
	}
	return (num);
}

void	ft_toggle_flag(char c, t_flags *flags, va_list args)
{
	if (c == '-')
		flags->minus = 1;
	else if (c == '#')
		flags->hashtag = 1;
	else if (c == ' ')
		flags->space = 1;
	else if (c == '+')
		flags->plus = 1;
	else if (c == '*')
		flags->width = va_arg(args, int);
}

void	ft_parse_flags(const char **str, t_flags *flags, va_list args)
{
	while (**str && ft_isin_flag(**str))
	{
		if (**str == '.')
		{
			flags->dot = 1;
			(*str)++;
			flags->precision = ft_parse_number(str);
			continue ;
		}
		else if (**str >= '0' && **str <= '9')
		{
			if (**str == '0')
			{
				flags->zero = 1;
				(*str)++;
			}
			flags->width = ft_parse_number(str);
			continue ;
		}
		else
			ft_toggle_flag(**str, flags, args);
		(*str)++;
	}
}

int	ft_parse_spec(const char **str, va_list args, t_flags flags)
{
	int	(*table[256])(va_list, t_flags);
	int	count;
	int	i;

	i = 0;
	while (i < 256)
		table[i++] = NULL;
	table[(unsigned char) 'c'] = ft_putchar_f;
	table[(unsigned char) 's'] = ft_putstr_f;
	table[(unsigned char) 'p'] = ft_putptr_f;
	table[(unsigned char) 'd'] = ft_putnbr_f;
	table[(unsigned char) 'i'] = ft_putnbr_f;
	table[(unsigned char) 'u'] = ft_put_u_nbr_f;
	table[(unsigned char) 'x'] = ft_put_low_hex_f;
	table[(unsigned char) 'X'] = ft_put_up_hex_f;
	table[(unsigned char) '%'] = ft_putsign_f;
	count = 0;
	if (table[(unsigned char)(**str)] != NULL)
		count = table[(unsigned char)(**str)](args, flags);
	(*str)++;
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	t_flags	flags;
	int		total_len;

	va_start(args, str);
	total_len = 0;
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			flags = ft_init_flag();
			ft_parse_flags(&str, &flags, args);
			total_len += ft_parse_spec(&str, args, flags);
		}
		else
		{
			write(1, str, 1);
			total_len++;
			str++;
		}
	}
	va_end(args);
	return (total_len);
}
