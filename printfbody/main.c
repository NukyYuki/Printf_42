#include "libftprintf.h"
#include <stdio.h>

int main(void)
{
	char	*s = "Hello";
	//long p = s;
	//unsigned int		i = 8345;
	char	c = 'A';

	ft_printf("1234 %s %c World %p",s, c, &s);
	printf("\n%p", &s);
//ft_putnbr_base_hexa(i, "0123456789abcdef");
	printf("\n%p", &s);
	return 0;
}
