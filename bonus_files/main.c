#include "ft_printf.h"
#include <stdio.h>

int main(void)
{

	char *s = NULL;

	ft_printf("ft -> |%-10.5s|\n", s);
	printf("OG -> |%-10.5s|\n", s);
//	ft_printf("ft -> |%c|\n", 'a' - 256);
	ft_printf("ft -> |%c|\n", 'a' + 256);
//	printf("og -> |%c|\n", 'a' - 256);
	printf("og -> |%c|\n", 'a' + 256);
//	ft_printf("ft -> |%s| %% %#06x", "ola", 42);

	ft_printf("ft -> |%10.c|\n", 'a');
	printf("OG -> |%10.c|\n", 'a');
	ft_printf("ft -> |%-10%|\n");
	printf("OG -> |%-10%|\n");
	ft_printf("ft -> |%#015x|\n", 42);
	printf("OG -> |%#015x|\n", 42);
	//printf("-- printed char count --\nft -> %d\nOG -> %d\n", ftf, pf);
	return 0;
}
