#include "ft_printf.h"

int	do_check(char c, va_list *args)
{
	if (c == 'c')
		return (ft_putchar(va_arg(*args, int)));
	if (c == 's')
		return (ft_putstr(va_arg(*args, char *)));
	if (c == 'p')
		return (ft_putptr(va_arg(*args, unsigned long))); // pq unsigend long?
	if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(*args, int)));
	if (c == 'u')
		return (ft_putnbr(va_arg(*args, unsigned int)));
	if (c == 'x')
		return (ft_puthex(va_arg(*args, unsigned int), '123456789abcdef'));
	if (c == 'X')
		return (ft_puthex(va_arg(*args, unsigned int), '123456789ABCDEF'));
	if (c == '%')
		return (ft_putchar('%'));
	return (-1);
}
