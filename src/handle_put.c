int ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int ft_putstr(char *str)
{
	int i;

	i = 0;
	while(str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i + 1); // ja q começa no zero e eu preciso da qtd escrita;
}

// como vou fazer a contagem desse?
int	ft_putnbr(int n)
{
	long	n1;

	n1 = n;
	if (n1 < 0)
	{
		ft_putchar('-');
		n1 *= -1;
	}
	if (n1 > 9)
		ft_putnbr(n1 / 10);
	ft_putchar((n1 % 10) + '0');
}

int ft_putptr(unsigned long ptr)
{

}

int ft_puthex(unsigned int n, char *base)
{

}
