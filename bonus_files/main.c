#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
	//char	*s = "Hello";
	//int		i = 42;
	//char	c = 'A';
	int		pf = 0;
	int		ftf = 0;
	char	*s = NULL;

	ftf = ft_printf("ft -> |%c|\n", 'c') - 9;
	ftf = ft_printf("ft -> |%.5s|\n", s) - 9;
	pf = printf("OG -> |%.5s|\n", s) - 9;
	pf = printf("OG -> |%2p|\n", (void *)0) - 9;
	//pf = ft_printf("|%#015x|", i);
	printf("-- printed char count --\nft -> %d\nOG -> %d\n", ftf, pf);
	return 0;
}
