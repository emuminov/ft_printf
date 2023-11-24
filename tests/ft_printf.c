/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuminov <emuminov@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 21:32:32 by emuminov          #+#    #+#             */
/*   Updated: 2023/11/24 20:36:27 by emuminov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

#include "../ft_printf.h"

#define printf_test(input, format_str, args...) \
{ \
	printf("TESTING INPUT: %s\n", input); \
	int printf_output = printf(format_str, args); \
	int ft_printf_output = ft_printf(format_str, args); \
	printf("printf len:   \t\t%d\n", printf_output); \
	printf("ft_printf len:\t\t%d\n", ft_printf_output); \
	printf("\n"); \
}

#define red(str) \
	printf("\033[1;31m"); \
	printf(str); \
	printf("\033[1;0m");

int	main(void)
{
	{
		red("char test\n");
		// printf("\033[1;31mchar test\033[1;0m\n");
		printf("--------------------------------\n");
		printf_test("a", "hello! %c hehe\n", 'a');
		printf_test("a, b", "hello! %c %c hehe\n", 'a', 'b');
		printf_test("c", "%c\n", 'c');
		printf_test("-200", "%c\n", -200);
		printf_test("-256", "%c\n", -256);
		printf_test("256", "%c\n", 256);
		printf_test("-400", "%c\n", -400);
		printf_test("400", "%c\n", 400);
	}

	{
		red("\nstring test\n");
		printf("--------------------------------\n");
		printf_test("ohoho", "hello! %s hehe\n", "ohoho");
		printf_test("(empty string)", "hello! %s hehe\n", "");
		printf_test("(empty string)", "%sa\n", "");
		printf_test("(empty string)", "%s", "");
	}

	{
		int i = 0;
		int overflow1 = INT_MIN;
		int overflow2 = INT_MAX;
		while (i < 4)
		{
			overflow1--;
			overflow2++;
			i++;
		}
		red("\nint test\n");
		printf("--------------------------------\n");
		printf_test("42", "hello! %d hehe\n", 42);
		printf_test("0", "hello! %d hehe\n", 0);
		printf_test("INT_MIN", "hello! %d hehe\n", INT_MIN);
		printf_test("INT_MIN - 3", "hello! %d hehe\n", overflow1);
		printf_test("INT_MAX + 3", "hello! %d hehe\n", overflow2);
	}

	{
		int i = 0;
		int overflow1 = INT_MIN;
		int overflow2 = INT_MAX;
		while (i < 4)
		{
			overflow1--;
			overflow2++;
			i++;
		}
		red("\nsigned decimal test\n");
		printf("--------------------------------\n");
		printf_test("42", "hello! %i hehe\n", 42);
		printf_test("0", "hello! %i hehe\n", 0);
		printf_test("INT_MIN", "hello! %i hehe\n", INT_MIN);
		printf_test("INT_MIN - 3", "hello! %i hehe\n", overflow1);
		printf_test("INT_MAX + 3", "hello! %i hehe\n", overflow2);
	}

	{
		red("\npointers test\n");
		printf("--------------------------------\n");
		printf_test("NULL", "hello! %p hehe\n", NULL);
		printf_test("hehe", "hello! %p hehe\n", "hehe");
	}

	{
		red("\nunsigned int test\n");
		printf("--------------------------------\n");
		printf_test("4", "hello! %u hehe\n", 4);
		printf_test("-4", "hello! %u hehe\n", -4);
	}

	{
		red("\nlowercase hexadecimal test\n");
		printf("--------------------------------\n");
		printf_test("100", "hello! %x hehe\n", 100);
		printf_test("UINT_MAX", "hello! %x hehe\n", UINT_MAX);
		printf_test("UINT_MAX + 1", "hello! %x hehe\n", UINT_MAX + 1);
		printf_test("UINT_MAX + 2", "hello! %x hehe\n", UINT_MAX + 2);
		printf_test("-12", "hello! %x hehe\n", -12);
	}

	{
		red("\nuppercase hexadecimal test\n");
		printf("--------------------------------\n");
		printf_test("100", "hello! %X hehe\n", 100);
		printf_test("UINT_MAX", "hello! %X hehe\n", UINT_MAX);
		printf_test("UINT_MAX + 1", "hello! %X hehe\n", UINT_MAX + 1);
		printf_test("UINT_MAX + 2", "hello! %X hehe\n", UINT_MAX + 2);
		printf_test("-12", "hello! %X hehe\n", -12);
	}

	{
		red("\npersentage sign test\n");
		printf("--------------------------------\n");
		printf_test("(nothing)", "hello! %% hehe\n", 0);
		printf_test("100", "hello! %% hehe %d\n", 100);
	}

	{
		red("\nmultiple args test\n");
		printf("--------------------------------\n");
		printf_test("NULL, hello, INT_MAX, &printf, h", "%p %s %d %p %% %c %X\n", NULL, "hello", INT_MAX, &printf, 'h', INT_MIN);
	}
}
