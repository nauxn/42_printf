#include "ft_printf.h"

static void	ft_putnbr_base(int nbr, char *base)
{
	int		len;
	long	n;

	len = 0;
	while (base[len] != '\0')
		len++;
	n = nbr;
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	if (n >= len)
		ft_putnbr_base((int)(n / len), base);
	write(1, &base[n % len], 1);
}

int	ft_putuhex(va_list args)
{
	int		nb;
	char	*up_hex;
	char	*low_hex;

	nb = va_arg(args, int);
	up_hex = "0123456789ABCDEF";
	low_hex = "0123456789abcdef";

}

int	ft_putlhex(va_list args)
{
	int		nb;
	char	*low_hex;

	low_hex = "0123456789abcdef";

}

int	ft_putptr_f(va_list args)
{
    void *ptr = va_arg(args, void *);

    unsigned long long address = (unsigned long long)ptr;

}
