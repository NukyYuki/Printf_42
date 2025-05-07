#include "ft_printf.h"
#include <stdio.h>

int main(void)
{

	printf("OG -> ||%.1i||\n", -3);
	ft_printf("ft -> %.6i\n", -3);
	printf("OG -> %.6i\n", -3);
	ft_printf("ft -> %07i\n", -54);
	printf("OG -> %07i\n", -54);
	ft_printf("ft -> %10.5i\n", -216);
	printf("OG -> %10.5i\n", -216);
	ft_printf("ft -> %3.7i\n", -2375);
	printf("OG -> %3.7i\n", -2375);
	//printf("OG -> |%k%j|\n");
	//printf("-- printed char count --\nft -> %d\nOG -> %d\n", ftf, pf);
	return 0;
}
