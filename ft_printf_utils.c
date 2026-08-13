#include "ft_printf.h"

int	ft_putchar_f(va_list args)
{
	int	c;

	c = va_arg(argc, int);
	write(1, &c, 1);
	return (1);
}

int	ft_putstr_f(va_list args)
{
	char	*str;
	int		i;

	*str = va_arg(args, char *);
	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_putnbr_f(va_list args)
{
	long	nb;
	int		count;

	nb = va_arg(args, long);
	count = 0;
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
		count++;
	}
	if (nb >= 10)
		ft_putnbr_f(nb / 10);
	ft_putchar_f((nb % 10) + '0');
	return (count + 1);
}

int	ft_putunbr(va_list args)
{
	unsigned int	nb;
	int				count;

	count = 0;
	nb = va_arg(args, unsigned int);
	if (nb >= 10)
		ft_putunbr(nb / 10);
	ft_putchar_f((nb % 10) + '0');
	return (count + 1);
}

int	ft_putsign_f(va_list args) 
{
	char	p;

    (void)args;
	p = '%';
    write(1, &p, 1);
    return (1);
}

