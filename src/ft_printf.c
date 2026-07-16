/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzampier <jzampier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 12:22:53 by jzampier          #+#    #+#             */
/*   Updated: 2026/07/16 16:49:22 by jzampier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		count;

	if (!str)
		return (-1);
	va_start(args, str);
	count = 0;
	while (*str)
	{
		if (*str == '%')
			count += do_check(*(++str), &args);
		else
			count += ft_putchar(*str);
		str++;
	}
	va_end(args);
	return (count);
}

#include <stdio.h>

int	main(void)
{
	char 			c1 = 'z';
	char 			c2 = 'Z';
	char 			*str = "Ola mundo!";
	int 			d1 = 8096;
	int 			d2 = -2147483648;
	int				d3 = 2147483647;
	// long			d4 = 3258594759;
	unsigned int	u1 = 4294967295;

	printf("Começando testagem...\n\n\n");
	printf("\nc1: \nft: %d   normal: %d\n\n", ft_printf("%c", c1), printf("%c", c1));
	printf("\nc2: \nft: %d   normal: %d\n\n", ft_printf("%c", c2), printf("%c", c2));
	printf("\nstr: \nft: %d   normal: %d\n\n", ft_printf("%s", str), printf("%s", str));
	printf("\nd1: \nft: %d   normal: %d\n\n", ft_printf("%d", d1), printf("%d", d1));
	printf("\nd2: \nft: %d   normal: %d\n\n", ft_printf("%d", d2), printf("%d", d2));
	printf("\nd3: \nft: %d   normal: %d\n\n", ft_printf("%d", d3), printf("%d", d3));
	// printf("d4: \nft: %d   normal: %d\n\n", ft_printf("%d", d4), printf("%d", d4));
	printf("\nu1: \nft: %d   normal: %d\n\n", ft_printf("%u", u1), printf("%u", u1));
	printf("\np: \nft: %d   normal: %d\n\n", ft_printf("%p", &str), printf("%p", &str));
	printf("\nd1-x: \nft: %d   normal: %d\n\n", ft_printf("%x", d1), printf("%x", d1));
	printf("\nd1-X: \nft: %d   normal: %d\n\n", ft_printf("%X", d1), printf("%X", d1));
	printf("%%: \nft: %d   normal: %d\n\n", ft_printf("%%"), printf("%%"));


	int INT_MIN = -2147483648;
	int INT_MAX = 2147483647;
	long LONG_MIN = -9223372036854775807;
	long LONG_MAX = 9223372036854775807;

	printf("normal: %p %p \n\n\n\n", &LONG_MIN, &LONG_MAX);
	printf("normal: %p %p \n\n\n\n", &INT_MIN, &INT_MAX);
	ft_printf("meu: %p %p \n\n\n\n", &LONG_MIN, &LONG_MAX);
	ft_printf("meu: %p %p \n\n\n\n", &INT_MIN, &INT_MAX);
}
