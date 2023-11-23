/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuminov <emuminov@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 21:32:32 by emuminov          #+#    #+#             */
/*   Updated: 2023/11/23 11:55:33 by emuminov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

#include "../src/ft_printf.h"
#include "../lib/libft.h"

int	main(void)
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

	printf("\nstring test\n");
	int printf5 = printf("hello! %s hehe\n", "ohoho");
	int printf6 = ft_printf("hello! %s hehe\n", "ohoho");
	printf("printf ohoho is:       %d\n", printf5);
	printf("ft_printf ohoho is:    %d\n", printf6);

	printf("\nint test\n");
	int printf7 = printf("hello! %d hehe\n", 21);
	int printf8 = ft_printf("hello! %d hehe\n", 21);
	int printf9 = printf("hello! %d hehe\n", INT_MIN);
	int printf10 = ft_printf("hello! %d hehe\n", INT_MIN);
	printf("printf 21 is:         %d\n", printf7);
	printf("ft_printf 21 is:      %d\n", printf8);
	printf("printf INT_MIN is:    %d\n", printf9);
	printf("ft_printf INT_MIN is: %d\n", printf10);

	printf("\nsigned decimal test\n");
	int printf11 = printf("hello! %i hehe\n", 21);
	int printf12 = ft_printf("hello! %i hehe\n", 21);
	printf("printf 21 is:         %i\n", printf11);
	printf("ft_printf 21 is:      %i\n", printf12);

	printf("\npointers test\n");
	int printf13 = printf("hello! %p hehe\n", NULL);
	int printf14 = ft_printf("hello! %p hehe\n", NULL);
	int printf15 = printf("hello! %p hehe\n", "hehe");
	int printf16 = ft_printf("hello! %p hehe\n", "hehe");
	printf("printf NULL is:       %i\n", printf13);
	printf("ft_printf NULL is:    %i\n", printf14);
	printf("printf char * is:     %i\n", printf15);
	printf("ft_printf char * is:  %i\n", printf16);

	printf("\nunsigned int test\n");
	int printf17 = printf("hello! %u hehe\n", 4);
	int printf18 = ft_printf("hello! %u hehe\n", 4);
	int printf19 = printf("hello! %u hehe\n", -4);
	int printf20 = ft_printf("hello! %u hehe\n", -4);
	printf("printf 4 is:       %i\n", printf17);
	printf("ft_printf 4 is:    %i\n", printf18);
	printf("printf -4 is:      %i\n", printf19);
	printf("ft_printf -4 is:   %i\n", printf20);

	printf("\nlowercase hexadecimal test\n");
	int printf21 = printf("hello! %x hehe\n", 100);
	int printf22 = ft_printf("hello! %x hehe\n", 100);
	int printf23 = printf("hello! %x hehe\n", UINT_MAX);
	int printf24 = ft_printf("hello! %x hehe\n", UINT_MAX);
	int printf25 = printf("hello! %x hehe\n", UINT_MAX + 1);
	int printf26 = ft_printf("hello! %x hehe\n", UINT_MAX + 1);
	int printf27 = printf("hello! %x hehe\n", UINT_MAX + 2);
	int printf28 = ft_printf("hello! %x hehe\n", UINT_MAX + 2);
	int printf29 = printf("hello! %x hehe\n", -12);
	int printf30 = ft_printf("hello! %x hehe\n", -12);
	printf("printf 100 is:                %i\n", printf21);
	printf("ft_printf 100 is:             %i\n", printf22);
	printf("printf UINT_MAX is:           %i\n", printf23);
	printf("ft_printf UINT_MAX is:        %i\n", printf24);
	printf("printf UINT_MAX + 1 is:       %i\n", printf25);
	printf("ft_printf UINT_MAX + 1 is:    %i\n", printf26);
	printf("printf UINT_MAX + 2 is:       %i\n", printf27);
	printf("ft_printf UINT_MAX + 2 is:    %i\n", printf28);
	printf("printf -12 is:                %i\n", printf29);
	printf("ft_printf -12 is:             %i\n", printf30);

	printf("\nuppercase hexadecimal test\n");
	int printf31 = printf("hello! %X hehe\n", 100);
	int printf32 = ft_printf("hello! %X hehe\n", 100);
	int printf33 = printf("hello! %X hehe\n", UINT_MAX);
	int printf34 = ft_printf("hello! %X hehe\n", UINT_MAX);
	int printf35 = printf("hello! %X hehe\n", UINT_MAX + 1);
	int printf36 = ft_printf("hello! %X hehe\n", UINT_MAX + 1);
	int printf37 = printf("hello! %X hehe\n", UINT_MAX + 2);
	int printf38 = ft_printf("hello! %X hehe\n", UINT_MAX + 2);
	int printf39 = printf("hello! %X hehe\n", -12);
	int printf40 = ft_printf("hello! %X hehe\n", -12);
	printf("printf 100 is:                %i\n", printf31);
	printf("ft_printf 100 is:             %i\n", printf32);
	printf("printf UINT_MAX is:           %i\n", printf33);
	printf("ft_printf UINT_MAX is:        %i\n", printf34);
	printf("printf UINT_MAX + 1 is:       %i\n", printf35);
	printf("ft_printf UINT_MAX + 1 is:    %i\n", printf36);
	printf("printf UINT_MAX + 2 is:       %i\n", printf37);
	printf("ft_printf UINT_MAX + 2 is:    %i\n", printf38);
	printf("printf -12 is:                %i\n", printf39);
	printf("ft_printf -12 is:             %i\n", printf40);

	printf("\npersentage sign test\n");
	int printf41 = printf("hello! %% hehe\n");
	int printf42 = ft_printf("hello! %% hehe\n");
	int printf43 = printf("hello! %% hehe %d\n", 100);
	int printf44 = ft_printf("hello! %% hehe %d\n", 100);
	printf("printf %% is:                %i\n", printf41);
	printf("ft_printf %% is:             %i\n", printf42);
	printf("printf %% 100 is:            %i\n", printf43);
	printf("ft_printf %% 100 is:         %i\n", printf44);
}
