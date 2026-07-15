
#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list args;
	int count;

	if (!str)											// Se não houver argumentos,
		return (-1);									// Retorna (-1), codigo de saida para erro;
	va_start(args, str);								// Comeca a leitura dos argumentos recebidos
	count = 0;											// Setando para zero o contador de bytes escritos
	while (*str)										// Começa loop do argumento
	{
		if (*str == '%')								// Se o caractere atual for um %
			count = do_check(*(++str), *args);			// Passo para o prox caracter e o args atual
		else
			count = do_print(*str);						// Se não for %, só printa na tela;
		str++;											// Passo para o proximo caractere;
	}
	va_end(args);										// Finalizo a leitura dos argumentos
	return (count);										// Retorno a contagem de bytes impressos;
}


// Falta implementação: do_check() + do_print()
// Falta entender como funciona exatamente o va_list, etc.

