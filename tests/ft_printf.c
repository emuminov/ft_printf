/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuminov <emuminov@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 21:32:32 by emuminov          #+#    #+#             */
/*   Updated: 2023/11/23 15:35:52 by emuminov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

#include "../src/ft_printf.h"
#include "../lib/libft.h"

int	main(void)
{
	{
		printf("char test\n");
		int printf1 = printf("hello! %c hehe\n", 'a');
		int printf2 = ft_printf("hello! %c hehe\n", 'a');
		int printf3 = ft_printf("hello! %c %c hehe\n", 'a', 'b');
		int printf4 = ft_printf("hello! %c %c hehe\n", 'a', 'b');
		printf("printf a is:         %d\n", printf1);
		printf("ft_printf a is:      %d\n", printf2);
		printf("printf a b is:       %d\n", printf3);
		printf("ft_printf a b is:    %d\n", printf4);
	}

	{
		printf("\nstring test\n");
		int printf1 = printf("hello! %s hehe\n", "ohoho");
		int printf2 = ft_printf("hello! %s hehe\n", "ohoho");
		printf("printf ohoho is:       %d\n", printf1);
		printf("ft_printf ohoho is:    %d\n", printf2);
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
		printf("\nint test\n");
		int printf1 = printf("hello! %d hehe\n", 21);
		int printf2 = ft_printf("hello! %d hehe\n", 21);
		int printf3 = printf("hello! %d hehe\n", INT_MIN);
		int printf4 = ft_printf("hello! %d hehe\n", INT_MIN);
		int printf5 = printf("hello! %d hehe\n", overflow1);
		int printf6 = ft_printf("hello! %d hehe\n", overflow1);
		int printf7 = printf("hello! %d hehe\n", overflow2);
		int printf8 = ft_printf("hello! %d hehe\n", overflow2);
		printf("printf 21 is:             %d\n", printf1);
		printf("ft_printf 21 is:          %d\n", printf2);
		printf("printf INT_MIN is:        %d\n", printf3);
		printf("ft_printf INT_MIN is:     %d\n", printf4);
		printf("printf INT_MIN - 4 is:    %d\n", printf5);
		printf("ft_printf INT_MIN - 4 is: %d\n", printf6);
		printf("printf INT_MAX + 4 is:    %d\n", printf7);
		printf("ft_printf INT_MAX + 4 is: %d\n", printf8);
	}

	{
		printf("\nsigned decimal test\n");
		int printf1 = printf("hello! %i hehe\n", 21);
		int printf2 = ft_printf("hello! %i hehe\n", 21);
		printf("printf 21 is:         %i\n", printf1);
		printf("ft_printf 21 is:      %i\n", printf2);
	}

	{
		printf("\npointers test\n");
		int printf1 = printf("hello! %p hehe\n", NULL);
		int printf2 = ft_printf("hello! %p hehe\n", NULL);
		int printf3 = printf("hello! %p hehe\n", "hehe");
		int printf4 = ft_printf("hello! %p hehe\n", "hehe");
		printf("printf NULL is:       %i\n", printf1);
		printf("ft_printf NULL is:    %i\n", printf2);
		printf("printf char * is:     %i\n", printf3);
		printf("ft_printf char * is:  %i\n", printf4);
	}

	{
		printf("\nunsigned int test\n");
		int printf1 = printf("hello! %u hehe\n", 4);
		int printf2 = ft_printf("hello! %u hehe\n", 4);
		int printf3 = printf("hello! %u hehe\n", -4);
		int printf4 = ft_printf("hello! %u hehe\n", -4);
		printf("printf 4 is:       %i\n", printf1);
		printf("ft_printf 4 is:    %i\n", printf2);
		printf("printf -4 is:      %i\n", printf3);
		printf("ft_printf -4 is:   %i\n", printf4);
	}

	{
		printf("\nlowercase hexadecimal test\n");
		int printf1 = printf("hello! %x hehe\n", 100);
		int printf2 = ft_printf("hello! %x hehe\n", 100);
		int printf3 = printf("hello! %x hehe\n", UINT_MAX);
		int printf4 = ft_printf("hello! %x hehe\n", UINT_MAX);
		int printf5 = printf("hello! %x hehe\n", UINT_MAX + 1);
		int printf6 = ft_printf("hello! %x hehe\n", UINT_MAX + 1);
		int printf7 = printf("hello! %x hehe\n", UINT_MAX + 2);
		int printf8 = ft_printf("hello! %x hehe\n", UINT_MAX + 2);
		int printf9 = printf("hello! %x hehe\n", -12);
		int printf10 = ft_printf("hello! %x hehe\n", -12);
		printf("printf 100 is:                %i\n", printf1);
		printf("ft_printf 100 is:             %i\n", printf2);
		printf("printf UINT_MAX is:           %i\n", printf3);
		printf("ft_printf UINT_MAX is:        %i\n", printf4);
		printf("printf UINT_MAX + 1 is:       %i\n", printf5);
		printf("ft_printf UINT_MAX + 1 is:    %i\n", printf6);
		printf("printf UINT_MAX + 2 is:       %i\n", printf7);
		printf("ft_printf UINT_MAX + 2 is:    %i\n", printf8);
		printf("printf -12 is:                %i\n", printf9);
		printf("ft_printf -12 is:             %i\n", printf10);
	}

	{
		printf("\nuppercase hexadecimal test\n");
		int printf1 = printf("hello! %X hehe\n", 100);
		int printf2 = ft_printf("hello! %X hehe\n", 100);
		int printf3 = printf("hello! %X hehe\n", UINT_MAX);
		int printf4 = ft_printf("hello! %X hehe\n", UINT_MAX);
		int printf5 = printf("hello! %X hehe\n", UINT_MAX + 1);
		int printf6 = ft_printf("hello! %X hehe\n", UINT_MAX + 1);
		int printf7 = printf("hello! %X hehe\n", UINT_MAX + 2);
		int printf8 = ft_printf("hello! %X hehe\n", UINT_MAX + 2);
		int printf9 = printf("hello! %X hehe\n", -12);
		int printf10 = ft_printf("hello! %X hehe\n", -12);
		printf("printf 100 is:                %i\n", printf1);
		printf("ft_printf 100 is:             %i\n", printf2);
		printf("printf UINT_MAX is:           %i\n", printf3);
		printf("ft_printf UINT_MAX is:        %i\n", printf4);
		printf("printf UINT_MAX + 1 is:       %i\n", printf5);
		printf("ft_printf UINT_MAX + 1 is:    %i\n", printf6);
		printf("printf UINT_MAX + 2 is:       %i\n", printf7);
		printf("ft_printf UINT_MAX + 2 is:    %i\n", printf8);
		printf("printf -12 is:                %i\n", printf9);
		printf("ft_printf -12 is:             %i\n", printf10);
	}

	{
		printf("\npersentage sign test\n");
		int printf1 = printf("hello! %% hehe\n");
		int printf2 = ft_printf("hello! %% hehe\n");
		int printf3 = printf("hello! %% hehe %d\n", 100);
		int printf4 = ft_printf("hello! %% hehe %d\n", 100);
		printf("printf %% is:                %i\n", printf1);
		printf("ft_printf %% is:             %i\n", printf2);
		printf("printf %% 100 is:            %i\n", printf3);
		printf("ft_printf %% 100 is:         %i\n", printf4);
	}
}
