*This project has been created as part of the 42 curriculum by jzampier*


```
#include <stdio.h>

#define INT_MAX   __INT_MAX__
#define LONG_MAX  __LONG_MAX__
#define INT_MIN   (-__INT_MAX__  -1)
#define LONG_MIN  (-__LONG_MAX__ -1L)

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
}

```