/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nisim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 15:03:35 by nisim             #+#    #+#             */
/*   Updated: 2026/08/20 19:44:01 by nisim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *str, ...);
int		ft_parse_spec(const char **str, va_list args);
int		ft_putchar_f(va_list args);
int		ft_putstr_f(va_list args);
int		ft_putnbr_f(va_list args);
int		ft_put_u_nbr_f(va_list args);
int		ft_putsign_f(va_list args);
int		ft_putnbr_base_f(unsigned long long n, char *base);
int		ft_put_up_hex_f(va_list args);
int		ft_put_low_hex_f(va_list args);
int		ft_putptr_f(va_list args);

#endif
