#include "libftprintf.h"
#include <stdio.h>

int main(void)
{
	char	*s = "Hello";
	void	*p = s;
	unsigned int		i = 8345;

	ft_printf("%u", i);
	//ft_putnbr_base_hexa(i, "0123456789abcdef");
	printf("\n%u", i);
	return 0;
}
