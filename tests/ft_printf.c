/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuminov <emuminov@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 21:32:32 by emuminov          #+#    #+#             */
/*   Updated: 2023/12/07 12:59:06 by emuminov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

#include "../ft_printf.h"

#define printf_test(input, format_str, ...) \
{ \
	printf("TESTING INPUT: %s\n", input); \
	int printf_output = printf(format_str __VA_OPT__(,) __VA_ARGS__); \
	int ft_printf_output = ft_printf(format_str __VA_OPT__(,) __VA_ARGS__); \
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
		red("basic test\n");
		printf("--------------------------------\n");
		printf_test("(nothing)", "1, 2, 3, -d test, testing, 0.4s sound, 1, 2, 3xp, sound, -*dtest\n");
	}

	{
		red("char test\n");
		printf("--------------------------------\n");
		printf_test("a", "hello! %c hehe\n", 'a');
		printf_test("a, b", "hello! %c %c hehe\n", 'a', 'b');
		printf_test("c", "%c\n", 'c');
		printf_test("-200", "%c\n", -200);
		printf_test("-256", "%c\n", -256);
		printf_test("256", "%c\n", 256);
		printf_test("-400", "%c\n", -400);
		printf_test("400", "%c\n", 400);
		printf_test("\0, '1', '0'", "%c%c%c\n", '\0', '1', '0');
	}

	{
		red("\nstring test\n");
		printf("--------------------------------\n");
		printf_test("ohoho", "hello! %s hehe\n", "ohoho");
		printf_test("(empty string)", "hello! %s hehe\n", "");
		printf_test("(empty string)", "%sa\n", "");
		printf_test("(empty string)", "%s", "");
		printf_test("NULL", "NULL %s NULL\n", NULL)
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
		printf_test("LONG_MIN, LONG_MAX", "%p %p\n", LONG_MIN, (void*) LONG_MAX);
	}

	{
		red("\nunsigned int test\n");
		printf("--------------------------------\n");
		printf_test("4294967295", "hello! %u hehe\n", UINT_MAX);
		printf_test("4", "hello! %u hehe\n", 4);
		printf_test("-4", "hello! %u hehe\n", -4);
		printf_test("UINT_MAX", "hello! %u hehe\n", UINT_MAX);
		printf_test("UINT_MAX", "hello! %u hehe\n", UINT_MAX + 1);
	}

	{
		red("\nlowercase hexadecimal test\n");
		printf("--------------------------------\n");
		printf_test("100", "hello! %x hehe\n", 100);
		printf_test("UINT_MAX", "hello! %x hehe\n", UINT_MAX);
		printf_test("UINT_MAX + 1", "hello! %x hehe\n", UINT_MAX + 1);
		printf_test("UINT_MAX + 2", "hello! %x hehe\n", UINT_MAX + 2);
		printf_test("-12", "hello! %x hehe\n", -12);
		printf_test("3735929054u", "the password is %x\n", 3735929054u)
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
		printf_test("(nothing)", "%%\n");
		printf_test("(nothing)", "hello! %% hehe\n");
		printf_test("100", "hello! %% hehe %d\n", 100);
		printf_test("%%c%%s%%p%%d%%i%%u%%x%%X%%", "%%c%%s%%p%%d%%i%%u%%x%%X%%\n");
	}

	{
		red("\nmultiple args test\n");
		printf("--------------------------------\n");
		printf_test("NULL, hello, INT_MAX, &printf, h", "%p %s %d %p %% %c %X\n", NULL, "hello", INT_MAX, &printf, 'h', INT_MIN);
	}

	{
		red("\nNULL format test\n");
		printf("--------------------------------\n");
		printf_test("(nothing, to NULL format string)", NULL);
		printf_test("a, b (to NULL format string)", NULL, 'a', 'b');
	}

	{
		red("\nnon-existent flags test\n");
		printf("--------------------------------\n");
		printf_test("(nothing)", "%л %ш %ж %й %в %с %Ч\n");
	}
}
