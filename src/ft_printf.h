#ifndef FT_PRINTF_H
# define FT_PRINTF_H


# include <stdarg.h>
# include <unistd.h>
// REMOVER
# include <stdio.h>

int	ft_printf(const char *, ...);
int	do_check(char c, va_list *args);

int ft_putchar(char c);
int ft_putstr(char *str);
int	ft_putnbr(int n);
int ft_putptr(unsigned long ptr);
int ft_puthex(unsigned int n, char *base);

#endif