/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nisim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 15:03:35 by nisim             #+#    #+#             */
/*   Updated: 2026/08/20 16:48:40 by nisim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct s_flags
{
	int	minus;
	int	zero;
	int	dot;
	int	hashtag;
	int	space;
	int	plus;
	int	width;
	int	precision;
	int	asterisk;
}		t_flags;

int		ft_printf(const char *str, ...);
int		ft_isin_spec(char c);
int		ft_isin_flag(char c);
t_flags	ft_init_flag(void);
int		ft_pad(char c, int count);
long	ft_prefix(long nbr, t_flags flags, char *prefix);
int		ft_parse_number(const char **str);
void	ft_toggle_flag(char c, t_flags *flags, va_list args);
void	ft_parse_flags(const char **str, t_flags *flags, va_list args);
int		ft_parse_spec(const char **str, va_list args, t_flags flags);
int		ft_putchar_f(va_list args, t_flags flags);
int		ft_putstr_f(va_list args, t_flags flags);
int		ft_putnbr_f(va_list args, t_flags flags);
int		ft_put_u_nbr_f(va_list args, t_flags flags);
int		ft_putsign_f(va_list args, t_flags flags);
int		ft_putnbr_base_f(unsigned long long n, char *base);
int		ft_put_up_hex_f(va_list args, t_flags flags);
int		ft_put_low_hex_f(va_list args, t_flags flags);
int		ft_putptr_f(va_list args, t_flags flags);
int		ft_nbrlen(unsigned long long nb, char *base, t_flags flags);
int		ft_pad_flag(t_flags flags, int pad, int zeros, char *prefix);
int		ft_putptr_nil(t_flags flags);

#endif
