/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigomes- <vigomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 15:31:03 by vigomes-          #+#    #+#             */
/*   Updated: 2026/06/14 15:25:32 by vigomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>
#include <stdio.h>

typedef unsigned int	t_ui;

void	test_chars(char c, char c2, char c3)
{
	int	size_o;
	int	size_m;
 
	size_o = 0;
	size_m = 0;
	printf("CHARS\n");
	size_o = printf("printf: |%c|\n", c);
	size_m = ft_printf("ft_printf: |%c|\n", c) - 3;
	printf("printf returned: %d, ft_printf returned: %d\n\n", size_o, size_m);
	size_o = printf("printf: |%c|\n", c2);
	size_m = ft_printf("ft_printf: |%c|\n", c2) - 3;
	printf("printf returned: %d, ft_printf returned: %d\n\n", size_o, size_m);
	size_o = printf("printf: |%c|\n", c3);
	size_m = ft_printf("ft_printf: |%c|\n", c3) - 3;
	printf("printf returned: %d, ft_printf returned: %d\n\n", size_o, size_m);
}
 
void	test_strings(char *str, char *str2, char *str3)
{
	int	size_o;
	int	size_m;
 
	size_o = 0;
	size_m = 0;
	printf("STRINGS\n");
	size_o = printf("printf: |%s|\n", str);
	size_m = ft_printf("ft_printf: |%s|\n", str) - 3;
	printf("printf returned: %d, ft_printf returned: %d\n\n", size_o, size_m);
	size_o = printf("printf: |%s|\n", str2);
	size_m = ft_printf("ft_printf: |%s|\n", str2) - 3;
	printf("printf returned: %d, ft_printf returned: %d\n\n", size_o, size_m);
	size_o = printf("printf: |%s|\n", str3);
	size_m = ft_printf("ft_printf: |%s|\n", str3) - 3;
	printf("printf returned: %d, ft_printf returned: %d\n\n", size_o, size_m);
}
 
void	test_ints(int i, int i2, int i3)
{
	int	size_o;
	int	size_m;
 
	size_o = 0;
	size_m = 0;
	printf("INTS\n");
	size_o = printf("printf: |%d|\n", i);
	size_m = ft_printf("ft_printf: |%d|\n", i) - 3;
	printf("printf returned: %d, ft_printf returned: %d\n\n", size_o, size_m);
	size_o = printf("printf: |%d|\n", i2);
	size_m = ft_printf("ft_printf: |%d|\n", i2) - 3;
	printf("printf returned: %d, ft_printf returned: %d\n\n", size_o, size_m);
	size_o = printf("printf: |%i|\n", i3);
	size_m = ft_printf("ft_printf: |%i|\n", i3) - 3;
	printf("printf returned: %d, ft_printf returned: %d\n\n", size_o, size_m);
}
 
void	test_unsigned(unsigned int ui, unsigned int ui2, unsigned int ui3)
{
	int	size_o;
	int	size_m;
 
	size_o = 0;
	size_m = 0;
	printf("UNSIGNED\n");
	size_o = printf("printf: |%u|\n", ui);
	size_m = ft_printf("ft_printf: |%u|\n", ui) - 3;
	printf("printf returned: %d, ft_printf returned: %d\n\n", size_o, size_m);
	size_o = printf("printf: |%u|\n", ui2);
	size_m = ft_printf("ft_printf: |%u|\n", ui2) - 3;
	printf("printf returned: %d, ft_printf returned: %d\n\n", size_o, size_m);
	size_o = printf("printf: |%u|\n", ui3);
	size_m = ft_printf("ft_printf: |%u|\n", ui3) - 3;
	printf("printf returned: %d, ft_printf returned: %d\n\n", size_o, size_m);
}
 
void	test_pointers(void *ptr)
{
	int	size_o;
	int	size_m;
 
	size_o = 0;
	size_m = 0;
	printf("POINTERS\n");
	size_o = printf("printf: |%p|\n", ptr);
	size_m = ft_printf("ft_printf: |%p|\n", ptr) - 3;
	printf("printf returned: %d, ft_printf returned: %d\n\n", size_o, size_m);
	size_o = printf("printf: |%p|\n", NULL);
	size_m = ft_printf("ft_printf: |%p|\n", NULL) - 3;
	printf("printf returned: %d, ft_printf returned: %d\n\n", size_o, size_m);
}
 
void	test_upperhex(int hex, int hex2, int hex3)
{
	int	size_o;
	int	size_m;
 
	size_o = 0;
	size_m = 0;
	printf("UPPER HEX\n");
	size_o = printf("printf: |%X|\n", hex);
	size_m = ft_printf("ft_printf: |%X|\n", hex) - 3;
	printf("printf returned: %d, ft_printf returned: %d\n\n", size_o, size_m);
	size_o = printf("printf: |%X|\n", hex2);
	size_m = ft_printf("ft_printf: |%X|\n", hex2) - 3;
	printf("printf returned: %d, ft_printf returned: %d\n\n", size_o, size_m);
	size_o = printf("printf: |%X|\n", hex3);
	size_m = ft_printf("ft_printf: |%X|\n", hex3) - 3;
	printf("printf returned: %d, ft_printf returned: %d\n\n", size_o, size_m);
}
 
void	test_lowerhex(int hex, int hex2, int hex3)
{
	int	size_o;
	int	size_m;
 
	size_o = 0;
	size_m = 0;
	printf("LOWER HEX\n");
	size_o = printf("printf: |%x|\n", hex);
	size_m = ft_printf("ft_printf: |%x|\n", hex) - 3;
	printf("printf returned: %d, ft_printf returned: %d\n\n", size_o, size_m);
	size_o = printf("printf: |%x|\n", hex2);
	size_m = ft_printf("ft_printf: |%x|\n", hex2) - 3;
	printf("printf returned: %d, ft_printf returned: %d\n\n", size_o, size_m);
	size_o = printf("printf: |%x|\n", hex3);
	size_m = ft_printf("ft_printf: |%x|\n", hex3) - 3;
	printf("printf returned: %d, ft_printf returned: %d\n\n", size_o, size_m);
}
 
void	test_percents(void)
{
	int	size_o;
	int	size_m;
 
	size_o = 0;
	size_m = 0;
	printf("PERCENTS\n");
	size_o = printf("printf: |%%|\n");
	size_m = ft_printf("ft_printf: |%%|\n") - 3;
	printf("printf returned: %d, ft_printf returned: %d\n\n", size_o, size_m);
}
 
void	test_errors(void)
{
	int	ret;

	ret = 0;
	printf("ERRORS\n");
	printf("ft_printf(NULL): ");
	ret = ft_printf(NULL);
	if (ret < 0)
		printf("done\n");
	else
		printf("failed\n");
	printf("invalid specifier (%%g): ");
	ret = ft_printf("%g\n");
	if (ret < 0)
		printf("done\n");
	else
		printf("failed\n");
	printf("eol (%%\\n): ");
	ret = ft_printf("%\n");
	if (ret < 0)
		printf("done\n");
	else
		printf("failed\n");
	printf("eos (%%): ");
	ret = ft_printf("%");
	if (ret < 0)
		printf("done\n");
	else
		printf("failed\n");
}
 
void	test_edges(void)
{
	int				size_o;
	int				size_m;
	unsigned int	umax;
 
	umax = UINT_MAX;
	size_o = 0;
	size_m = 0;
	printf("EDGES\n");
	size_o = printf("printf: |%d| |%d|\n", INT_MIN, INT_MAX);
	size_m = ft_printf("ft_printf: |%d| |%d|\n", INT_MIN, INT_MAX) - 3;
	printf("printf returned: %d, ft_printf returned: %d\n\n", size_o, size_m);
	size_o = printf("printf: |%u|\n", umax);
	size_m = ft_printf("ft_printf: |%u|\n", umax) - 3;
	printf("printf returned: %d, ft_printf returned: %d\n\n", size_o, size_m);
	size_o = printf("printf: |%s| |%p|\n", (char *)NULL, NULL);
	size_m = ft_printf("ft_printf: |%s| |%p|\n", (char *)NULL, NULL) - 3;
	printf("printf returned: %d, ft_printf returned: %d\n\n", size_o, size_m);
}
 
void	adv_test(void)
{
	char			*str = "Teste";
	char			*str2 = "dell";
	char			*str3 = NULL;
	void			*ptr = str;
	int				d = -42;
	int				i = 123;
	int				n = 42;
	unsigned int	u = (unsigned int)-42;
	unsigned int	un = 0;
	unsigned int	tes = 43;
 
	test_chars('l', 'A', '\0');
	test_strings(str, str2, str3);
	test_ints(d, i, n);
	test_unsigned(u, un, tes);
	test_pointers(ptr);
	test_lowerhex(255, 0, 2147483647);
	test_upperhex(255, 0, 2147483647);
	test_percents();
	test_errors();
	test_edges();
}

void	ga_test(void)
{
	char	c = 'g';
	char	*str = "dell";
	char	*ptr = &c;
	int		num = 6010;
	t_ui	unbr = -6010;
	int	i, j;

	printf("\n---string---\n");
	i = ft_printf("[%s]\t", str);
	printf("my: %d\n", i);
	j = printf("[%s]\t", str);
	printf("or: %d\n", j);

	printf("\n---pointer---\n");
	i = ft_printf("[%p]\t", ptr);
	printf("my: %d\n", i);
	j = printf("[%p]\t", ptr);
	printf("or: %d\n", j);

	i = ft_printf("[%p]\t", NULL);
	printf("my: %d\n", i);
	j = printf("[%p]\t", NULL);
	printf("or: %d\n", j);

	printf("\n---decimal---\n");
	i = ft_printf("[%d]\t", num);
	printf("my: %d\n", i);
	j = printf("[%d]\t", num);
	printf("or: %d\n", j);

	printf("\n---unsigned---\n");
	i = ft_printf("[%u]\t", unbr);
	printf("my: %d\n", i);
	j = printf("[%u]\t", unbr);
	printf("or: %d\n", j);

	printf("\n---hexadecimals---\n");
	i = ft_printf("[%X][%x]\t", num, num);
	printf("my: %d\n", i);
	j = printf("[%X][%x]\t", num, num);
	printf("or: %d\n", j);

	printf("\n---hexadecimal lower---\n");
	i = ft_printf("[%x]\t", num);
	printf("my: %d\n", i);
	j = printf("[%x]\t", num);
	printf("or: %d\n", j);

	printf("\n---hexadecimal upper---\n");
	i = ft_printf("[%X]\t", num);
	printf("my: %d\n", i);
	j = printf("[%X]\t", num);
	printf("or: %d\n", j);

	printf("\n---percent---\n");
	i = ft_printf("[%%]\t");
	printf("my: %d\n", i);
	j = printf("[%%]\t");
	printf("or: %d\n", j);
}

void	basic_test(void)
{
	ft_printf(NULL);
	int		n;
	char	*str;

	n = 42;
	str = "hello";
	ft_printf("---- BASIC TESTS ----\n");
	ft_printf("char      : %c\n", 'A');
	ft_printf("string    : %s\n", str);
	ft_printf("signed d  : %d\n", 42);
	ft_printf("signed i  : %i\n", -42);
	ft_printf("unsigned  : %u\n", 42);
	ft_printf("lower hex : %x\n", 255);
	ft_printf("upper hex : %X\n", 255);
	ft_printf("pointer   : %p\n", &n);
	ft_printf("percent   : %%\n");
	ft_printf("\n---- EDGE TESTS ----\n");
	ft_printf("zero d    : %d\n", 0);
	ft_printf("zero x    : %x\n", 0);
	ft_printf("big hex   : %x\n", 2147483647);
	ft_printf("unsigned  : %u\n", 4294967295U);
	ft_printf("NULL str  : %s\n", NULL);
	ft_printf("NULL ptr  : %p\n", NULL);
	ft_printf("\n---- INVALID FORMAT TESTS ----\n");
	ft_printf("invalid   : %g\n");
	ft_printf("eol       : %\n");
	ft_printf("eos       : %");
}

void	tha_test(void)
{
	int				c = 'l';
	char			*str = "Teste";
	char			*str2 = NULL;
	void			*pointer = str;
	int				d = -42;
	int				i = 123;
	int				hex = 255;
	int				hexz = 8096;
	unsigned int	u = -42;
	unsigned int	un = 0;
	unsigned int	tes = 43;
	int				size_o; // Retorno printf original
	int				size_m; // Retorno minha printf

	printf("=== Original printf ===\n");
    size_o = printf("char: %c, string: %s, ponteiro: %p, decimal: %d, inteiro: %i, unsigned: %u, hex: %x, HEX: %X, porcento: %%\n", c, str, pointer, d, i, u, hex, hex);
    printf("Retorno printf: %d\n\n", size_o);

    printf("=== Minha ft_printf ===\n");
    size_m = ft_printf("char: %c, string: %s, ponteiro: %p, decimal: %d, inteiro: %i, unsigned: %u, hex: %x, HEX: %X, porcento: %%\n", c, str, pointer, d, i, u, hex, hex);
    printf("Retorno ft_printf: %d\n\n", size_m);

	printf("\n==== TESTES ft_printf vs printf ====\n\n");

    // 1. Unsigned
    printf("1. UNSIGNED\n");
    size_o = printf("O: |%u|\n", u);
    size_m = ft_printf("M: |%u|\n", u);
    printf("Retorno O: %d, Retorno M: %d\n\n", size_o, size_m);

    // 2. Ponteiros
    printf("2. PONTEIROS\n");
    size_o = printf("O: |%p|\n", pointer);
    size_m = ft_printf("M: |%p|\n", pointer);
    printf("Retorno O: %d, Retorno M: %d\n\n", size_o, size_m);

    // 3. Caracteres e strings
    printf("3. CHARS e STRINGS\n");
    size_o = printf("O: |%c| |%s|\n", c, str);
    size_m = ft_printf("M: |%c| |%s|\n", c, str);
    printf("Retorno O: %d, Retorno M: %d\n\n", size_o, size_m);
	size_o = printf("O: |%s|\n", str2);
    size_m = ft_printf("M: |%s|\n", str2);
    printf("Retorno O: %d, Retorno M: %d\n\n", size_o, size_m);

    // 4. Porcento
    printf("4. PORCENTO\n");
    size_o = printf("O: |%%|\n");
    size_m = ft_printf("M: |%%|\n");
    printf("Retorno O: %d, Retorno M: %d\n\n", size_o, size_m);

	 // 5. Valores extremos
    printf("5. VALORES EXTREMOS\n");
    size_o = printf("O: |%d| |%d|\n", INT_MIN, INT_MAX);
    size_m = ft_printf("M: |%d| |%d|\n", INT_MIN, INT_MAX);
    printf("Retorno O: %d, Retorno M: %d\n\n", size_o, size_m);

	printf("x = 0\n");
	size_o = printf("O: |%x| |%x| |%x|\n", hexz, hexz, hexz);
    size_m = ft_printf("M: |%x| |%x| |%x|\n", hexz, hexz, hexz);
	printf("Retorno O: %d, Retorno M: %d\n\n", size_o, size_m);

	printf("X = 0\n");
	size_o = printf("O: |%X| |%X| |%X|\n", hexz, hexz, hexz);
    size_m = ft_printf("M: |%X| |%X| |%X|\n", hexz, hexz, hexz);
    printf("Retorno O: %d, Retorno M: %d\n\n", size_o, size_m);

	size_o = printf("O: |%u| |%u| |%u| |%u|\n", tes, un, 1024, -1024);
    size_m = ft_printf("M: |%u| |%u| |%u| |%u|\n", tes, un, 1024, -1024);
    printf("Retorno O: %d, Retorno M: %d\n\n", size_o, size_m);
}

int	ft_strcmp(const char *st1, const char *st2)
{
	size_t	i;

	i = 0;
	while (st1[i] && (st1[i] == st2[i]))
		i++;
	return ((unsigned char)st1[i] - (unsigned char)st2[i]);
}

int main(int ac, char **av)
{
	if (ac > 1)
	{
		if (ft_strcmp(av[1], "--b") == 0)
			basic_test();
		else if (ft_strcmp(av[1], "--t") == 0)
			tha_test();
		else if (ft_strcmp(av[1], "--g") == 0)
			ga_test();
		else if (ft_strcmp(av[1], "--a") == 0)
			adv_test();
		else
			printf("flag not found, valids flags are --b, --t, --g, --a\n");
	}
	else
		basic_test();
	return (0);
}
