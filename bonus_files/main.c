#include "libftprintf.h"
#include <stdio.h>

int main(void)
{
	//char	*s = "Hello";
	int		i = 42;
	//char	c = 'A';
	int		pf = 0;

	pf = ft_printf("|%#015x|", i);
	printf("\n|%#015x|", i);
	//printf("\n%d\n", pf);
	return 0;
}
