/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <manmaria@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 14:19:34 by manmaria          #+#    #+#             */
/*   Updated: 2025/04/30 17:16:38 by mipinhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>

//NOTE: printf format
//  %[flags][width][.precision]specifier

int	main()
{
	int	i = 42;
	//|||0xffffffd6|||
	printf("|||%#-011.8x|||\n", i);
	printf("|||%10c|||\n", '5');
	//printf("|||%0+10d|||\n", i);
//	printf("|||%#-9.8x||\n", i);
//	printf("|||%08.7d|||\n", i);
	/*printf("|||%d|||\n", i);
	printf("|||%10d|||\n", i);
	printf("|||%10d|||\n", i);
	printf("|||%lu|||\n", k);
	printf("|||%0+10d|||\n", i);
	printf("|||%p|||\n", &i);
	printf("|||%s|||\n", "abcde");*/
	//printf("|||% s|||\n\n", "abcde");

	//printf("\n\n|||%010d|||\n", i); // fills n_width with 0's
	//printf("|||%10.4d|||\n", i); // preappends (.n - nbr_len) times 0's;
	//printf("|||%.4i|||\n\n", -i); //ignores 0 flag, prio is precision field

	//printf("|||%25p|||\n", &i);
	//printf("|||%#x|||\n", 42);
//	printf("Left-justified: %-10d\n", 99);
//	printf("Forced sign: %+d\n", 99);
//	printf("Forced sign: %d\n\n", 99);
//	printf("name %s, age %i, time %i%.2f\n", "Dino", 15, 0, 4.20);
	/*
	printf("Width flag %%[n]d adds spaces (n - len_nbr) to the left\n");
	printf("if (n - len_nbr) <= 0, adds no spaces\n\n");
	printf("Width:[8]%8d\n", 123);
	printf("Width:[7]%7d\n", 123);
	printf("Width:[6]%6d\n", 123);
	printf("Width:[5]%5d\n", 123);
	printf("Width:[4]%4d\n", 123);
	printf("Width:[3]%3d\n", 123);
	printf("Width:[2]%2d\n", 123);
	*//*
	printf("\nPrecision flag %%.[n]f\nfor float nbr 3.14159\n\n");
	printf("Precision:[.5] %.5f\n", 3.14159);
	printf("Precision:[.4] %.4f\n", 3.14159);
	printf("Precision:[.3] %.3f\n", 3.14159);
	printf("Precision:[.2] %.2f\n", 3.14159);
	printf("Precision:[.1] %.1f\n", 3.14159);
	printf("Precision:[.0] %.0f\n", 3.14159);
	*/
	return (0);
}
