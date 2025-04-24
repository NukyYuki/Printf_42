#include "libftprintf.h"
#include <stdio.h>

int main(void)
{
	char	*s = "Hello";
	void	*p = s;
	int		i = 8345;

//	ft_printf("%p", p);
	ft_putnbr_base_hexa(i, "0123456789abcdef");
	printf("\n%x", i);
	return 0;
}
