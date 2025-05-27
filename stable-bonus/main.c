#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int main(void)
{

	//const char *s = NULL;
	// 00000000000000000002
	// 0000000000000000002
	// "42% 32.44d42", 0)
	//+42.54d
	
	printf("ft: [%d]\n", ft_printf("ft {% 4.10d} ", 0));
	printf("Og: [%d]\n\n",  printf("Og {% 4.10d} ", 0));
	printf("ft: [%d]\n", ft_printf("ft {% -6.10d} ", 0));
	printf("Og: [%d]\n\n",  printf("Og {% -8.10d} ", 0));
	printf("ft: [%d]\n", ft_printf("ft {%+6.3d} ", 10));
	printf("Og: [%d]\n\n",  printf("Og {%+6.3d} ", 10));
	printf("ft: [%d]\n", ft_printf("/!\\% 5d/!\\ - ", 1) - 9);
	printf("Og: [%d]\n",    printf("/!\\% 5d/!\\ - ", 1) - 9);
	printf("ft: [%d]\n", ft_printf("/!\\% 25.20d/!\\ - ", 0) - 9);
	printf("Og: [%d]\n",    printf("/!\\% 25.20d/!\\ - ", 0) - 9);
	// printf("ft: [%d]\n", ft_printf("!%c!", (char)0));
	// printf("ft: [%d]\n", ft_printf("!%c!", (char)0));
	printf("ft: [%d]\n", ft_printf("PP% 5.4dCC - ", 1) - 7);
	printf("Og: [%d]\n",    printf("PP% 5.4dCC - ", 1) - 7);
	printf("ft: [%d]\n", ft_printf("42,% 32.44d,42 - ", 1) - 9);
	printf("Og: [%d]\n",    printf("42,% 32.44d,42 - ", 1) - 9);
	printf("ft: [%d]\n", ft_printf("/!\\% 25.20d/!\\ - ", 1) - 9);
	printf("Og: [%d]\n",    printf("/!\\% 25.20d/!\\ - ", 1) - 9);
	printf("ft: [%d]\n", ft_printf("/!\\% 25.20d/!\\ - ", 0) - 9);
	printf("Og: [%d]\n",    printf("/!\\% 25.20d/!\\ - ", 0) - 9);
	printf("ft: [%d]\n", ft_printf("/!\\% 020d/!\\ - ", 1) - 9);
	printf("Og: [%d]\n",    printf("/!\\% 020d/!\\ - ", 1) - 9);
	// printf("ft: [%d]\n", ft_printf("ft {%s} ", "\0\0 ola nulos"));
	// printf("Og: [%d]\n",    printf("Og {%s} ", "\0\0 ola nulos"));
	// printf("ft: [%d]\n", ft_printf("!%c!", (char)0));
	// printf("Og: [%d]\n",    printf("!%c!", (char)0));
	// printf("ft: [%d]\n", ft_printf("ft {%.0i} ", 0));
	// printf("Og: [%d]\n",    printf("Og {%.0i} ", 0));
	// //printf("ft: [%d]\n", ft_printf("ft {%s} ", (char *)NULL));
	// //printf("Og: [%d]\n", printf("Og {%s} ", (char *)NULL));
	printf("ft: [%d]\n", ft_printf("ft {%10.0d} ", 0));
	printf("Og: [%d]\n", printf("Og {%10.0d} ", 0));
	printf("ft: [%d]\n", ft_printf("ft {% -5d} %% -5d ", 0));
	printf("Og: [%d]\n", printf("Og {% -5d} %% -5d ", 0));
	printf("  ft: [%d]\n", ft_printf("ft {% -5d} ", -32));
	printf("  Og: [%d]\n", printf("Og {% -5d} ", -32));
	printf("  ft: [%d]\n", ft_printf("ft {% 6.6d} ", 0));
	printf("  Og: [%d]\n",    printf("Og {% 6.6d} ", 0));

	/*ft_printf("\n-- -[1.2.3]c '0', 0, '1' --\n");
	printf("lenft -> %d\n", ft_printf("ft ->| %-1c {%-2c} %-3c |\n", '0', 0, '1'));
	printf("lenOg -> %d\n", printf("OG ->| %-1c {%-2c} %-3c |\n", '0', 0, '1'));

	ft_printf("\n-- -[1.2.3]c '2', '1' ,0 --\n");
	printf("lenft -> %d\n", ft_printf("ft ->| %-1c %-2c {%3c} |\n", '2', '1', 0));
	printf("lenOg -> %d\n", printf("OG ->| %-1c %-2c {%3c} |\n", '2', '1', 0));

	printf("\n-- -[1.2.3]c 0, '1', '2' --\n");
	printf("\nlenft -> %d\n", ft_printf("ft ->{ |%-2c| %-2c {%-3c} |\n", 0, '1', '2'));
	printf("\nlenOG -> %d\n", printf("OG ->{ |%-2c| %-2c {%-3c} |\n", 0, '1', '2'));


	ft_printf("\n--spec c '0', 0, '1' --\n");
	printf("lenft -> %d\n", ft_printf("ft ->| %c %c %c |\n", '0', 0, '1'));
	printf("lenOg -> %d\n", printf("OG ->| %c %c %c |\n", '0', 0, '1'));

	ft_printf("\n--spec c '2', '1' 0 --\n");
	printf("lenft -> %d\n", ft_printf("ft ->| %c %c %c |\n", '2', '1', 0));
	printf("lenOg -> %d\n", printf("OG ->| %c %c %c |\n", '2', '1', 0));

	ft_printf("\n--spec c 0, '1', '2' --\n");
	printf("lenft -> %d\n", ft_printf("ft ->| %c %c %c |\n", 0, '1', '2'));
	printf("lenOg -> %d\n", printf("OG ->| %c %c %c |\n", 0, '1', '2'));*/
/*
	ft_printf("\n-- for 10.6i, '-32' --\n");
	ft_printf("ft -> |%10.6i|\n", -32);
	printf("OG -> |%10.6i|\n", -3);
	ft_printf("\n-- for 07i, '-52' --\n");
	ft_printf("ft -> |%07i|\n", -54);
	printf("OG -> |%07i|\n", -54);
	ft_printf("\n -- for 10.5i, '-216' --\n");
	ft_printf("ft -> |%10.5i|\n", -216);
	printf("OG -> |%10.5i|\n", -216);
	ft_printf("\n -- for 3.7i, '-2375' --\n");
	ft_printf("ft -> |%3.7i|\n", -2375);
	printf("OG -> |%3.7i|\n", -2375);*/
	//printf("OG -> |%k%j|\n");
	//printf("-- printed char count --\nft -> %d\nOG -> %d\n", ftf, pf);
	
	//ft_printf("ft -> {% -10d}\n", -101);
	//printf("OG -> {%-10d}\n", -101);
	//ft_printf("ft -> %#x\n", 0);
	//printf("OG -> %#x\n", 0);
	//ft_printf("ft -> %#x %#x %#x %#x %#x %#x %#x\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	//printf("OG -> %#x %#x %#x %#x %#x %#x %#x", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	//ft_printf("ft -> %#X\n", 0);
	//printf("OG -> %#X\n", 0);
	//ft_printf("ft -> %#X %#X %#X %#X %#X %#X %#X\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	//printf("OG -> %#X %#X %#X %#X %#X %#X %#X\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	//ft_printf("ft -> %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%%%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%\n", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0);
	//printf("OG -> %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%%%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%\n", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0);

	//ft_printf("\n-- for 02d, '-1' --\n");
	//ft_printf("ft -> |%02d|\n", -1);
	//printf("OG -> |%02d|\n", -1);

	//ft_printf("\n-- for 01d, '-1' --\n");
	/*ft_printf("ft -> [% -10d]\n", -94);
	printf("OG -> [% -10d]\n", -94);*/
/*	ft_printf("1ft -> [%5c]1\n", 0);
	printf("1OG -> [%5c]1\n", 0);
	ft_printf("2ft -> [%-5c]2\n", 0);
	printf("2OG -> [%-5c]2\n", 0);*/
	return 0;
}
