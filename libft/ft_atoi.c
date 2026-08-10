/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nisim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 16:31:38 by nisim             #+#    #+#             */
/*   Updated: 2026/07/29 18:14:13 by nisim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *nptr)
{
	int		i;
	int		sign;
	long	output;

	i = 0;
	sign = 1;
	output = 0;
	while ((nptr[i] >= '\t' && nptr[i] <= '\r') || nptr[i] == ' ')
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		output = (output * 10) + (nptr[i] - '0');
		if (sign == 1 && output > 2147483647)
			return (-1);
		if (sign == -1 && output > 2147483648)
			return (0);
		i++;
	}
	return ((int)(output * sign));
}
