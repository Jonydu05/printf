/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_put.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzampier <jzampier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 12:22:50 by jzampier          #+#    #+#             */
/*   Updated: 2026/07/16 17:01:37 by jzampier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i += ft_putchar(str[i]);
	return (i);
}

int	ft_putnbr(long n)
{
	long	n1;
	int		count;

	n1 = n;
	count = 0;
	if (n1 < 0)
	{
		count += ft_putchar('-');
		n1 *= -1;
	}
	if (n1 > 9)
		count += ft_putnbr(n1 / 10);
	count += ft_putchar((n1 % 10) + '0');
	return (count);
}

int	ft_puthex(unsigned long n, char *base)
{
	int	count;

	count = 0;
	if (n >= 16)
		count += ft_puthex(n / 16, base);
	count += ft_putchar(base[n % 16]);
	return (count);
}

int	ft_putptr(unsigned long ptr)
{
	int	count;

	if (!ptr)
		return (ft_putstr("(nil)"));
	count = 0;
	count += ft_putstr("0x");
	count += ft_puthex(ptr, "0123456789abcdef");
	return (count);
}
