/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzampier <jzampier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 12:22:45 by jzampier          #+#    #+#             */
/*   Updated: 2026/07/16 16:02:26 by jzampier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *str, ...);
int	do_check(char c, va_list *args);
int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_putnbr(long n);
int	ft_putptr(unsigned long ptr);
int	ft_puthex(unsigned long n, char *base);

#endif