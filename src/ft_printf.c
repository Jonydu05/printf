/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzampier <jzampier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 12:22:53 by jzampier          #+#    #+#             */
/*   Updated: 2026/07/15 20:23:47 by jzampier         ###   ########.fr       */
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
	char	*str = "olá mundo";

	ft_printf("%p\n", &str);
	printf("%p\n", &str);
}
