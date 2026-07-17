/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzampier <jzampier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 12:22:53 by jzampier          #+#    #+#             */
/*   Updated: 2026/07/16 17:15:31 by jzampier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// CORRIGIR:
// talvez eu precise criar um put unsigned int, pq se for unsigned int negativo e TEM QUE dar overflow
// mas o meu nao da overflow por que é long
// TEM QUE SER IGUAL AO PRINTF ORIGINAL
// Nos testes os ponteiros estao diferentes tbm
// tem algo de errado qnd tento printar o INT_MIN tbm

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
		if (*str == '\0')
			break ;
		str++;
	}
	va_end(args);
	return (count);
}
