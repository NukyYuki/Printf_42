#include "libftprintf.h"
#include <stdio.h>

int main(void)
{
	char	*s = "Hello";
	//long p = s;
	void	*p;
	p = s;
	int		i = 8345;
	char	c = 'A';

	ft_printf("1234 %s %c World %p %p",s, c, &s, p);
	printf("\n%p", p);
//ft_putnbr_base_hexa(i, "0123456789abcdef");
	printf("\n%p", &s);
	return 0;
}
