#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
	//char	*s = "Hello";
//	int		i = 42;
	//char	c = 'A';
	int		pf = 42;
	//int		ftf = 0;
	//char	*s = NULL;

//	ftf = ft_printf("ft -> |%c|\n", '0' - 256) - 9;
//	ftf = ft_printf("ft -> |%c|\n", '0' + 256) - 9;
//	pf = printf("og -> |%c|\n", '0' - 256) - 9;
//	pf = printf("og -> |%c|\n", '0' + 256) - 9;
//	pf = printf("og -> |%c|\n", 0) - 9;
	ft_printf("hello %#10x", pf);
	//pf = printf("OG -> |%s|\n", s) - 9;
	//pf = printf("OG -> |%i|\n", i) - 9;
	//pf = ft_printf("|%#015x|", i);
	//printf("-- printed char count --\nft -> %d\nOG -> %d\n", ftf, pf);
	return 0;
}
