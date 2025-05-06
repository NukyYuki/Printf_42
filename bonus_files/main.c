#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
	//char	*s = "Hello";
//	int		i = 42;
	//char	c = 'A';
	char		pf = 'a';
	//int		ftf = 0;
	//char	*s = NULL;

//	ftf = ft_printf("ft -> |%c|\n", '0' - 256) - 9;
//	ftf = ft_printf("ft -> |%c|\n", '0' + 256) - 9;
	//pf = printf("og -> |%c|\n", 'a' - 256) - 9;
	//pf = printf("og -> |%c|\n", '0' + 256) - 9;
//	pf = printf("og -> |%c|\n", 0) - 9;
	ft_printf("ft -> |%10c|\n", pf);
	ft_printf("\nOG -> |%10%|");
	printf("\nOG -> |%10%|");
	printf("\nOG -> |%10c|", pf);
	//ft_printf("pf -> |%.4s|\n", s);
	//printf("OG -> |%.4s|\n", s);
	//pf = printf("OG -> |%i|\n", i) - 9;
	//pf = ft_printf("|%#015x|", i);
	//printf("-- printed char count --\nft -> %d\nOG -> %d\n", ftf, pf);
	return 0;
}
