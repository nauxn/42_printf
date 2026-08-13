/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nisim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 15:03:51 by nisim             #+#    #+#             */
/*   Updated: 2026/08/10 18:09:53 by nisim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_func_table	jump_table[256] = {NULL};

void	init_jump_table(void)
{
	jump_table['c'] = ft_putchar_f;
	jump_table['s'] = ft_putstr_f;
	jump_table['p'] = ft_puthex_p;
	jump_table['d'] = ft_putnbr_f;
	jump_table['i'] = ft_putnbr_f;
	jump_table['u'] = ft_putunbr_f;
	jump_table['x'] = ft_puthex_f;
	jump_table['X'] = ft_puthex_f;
	jump_table['%'] = ft_putsign_f;
}


int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		total_len;

	va_start(args, str);
	
}
