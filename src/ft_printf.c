/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuminov <emuminov@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 21:32:35 by emuminov          #+#    #+#             */
/*   Updated: 2023/11/23 11:48:49 by emuminov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>

#include "../lib/libft.h"
#include "ft_printf.h"

static int	ft_putnbr_unsigned_fd(va_list args)
{
	size_t	i;
	char	*str;

	str = ft_ltoa_base("0123456789", va_arg(args, unsigned int));
	if (!str)
	{
		ft_putstr_fd("(nil)", 0);
		return (5);
	}
	i = 0;
	while (str[i])
	{
		i++;
	}
	write(0, str, i);
	free(str);
	return (i);
}

static int ft_puthex_ptr(va_list args)
{
	size_t	l;
	void	*arg;

	arg = va_arg(args, void *);
	if (!arg)
	{
		ft_putstr_fd("(nil)", 0);
		return (5);
	}
	char *hex = ft_ltoa_base("0123456789abcdef", (long) arg);
	if (!hex)
	{
		ft_putstr_fd("(nil)", 0);
		return (5);
	}
	l = ft_strlen(hex);
	write(0, "0x", 2);
	write(0, hex, l);
	free(hex);
	return (l + 2);
}

static int ft_puthex_ui(int toupper, va_list args)
{
	size_t	i;

	char *hex = ft_ltoa_base("0123456789abcdef", va_arg(args, unsigned int));
	if (!hex)
	{
		ft_putstr_fd("(nil)", 0);
		return (5);
	}
	i = 0;
	while (hex[i])
	{
		if (toupper)
			hex[i] = ft_toupper(hex[i]);
		i++;
	}
	write(0, hex, i);
	free(hex);
	return (i);
}

static int	ft_putstr_arg(va_list args)
{
	size_t		l;
	const char	*str;

	str = va_arg(args, const char *);
	l = ft_strlen(str);
	write(0, str, l);
	return (l);
}

static int	ft_putchar_arg(va_list args)
{
	ft_putchar_fd(va_arg(args, int), 0);
	return (1);
}

static int	ft_putnbr_arg(va_list args)
{
	char	*str;
	size_t	l;

	str = ft_itoa(va_arg(args, int));
	if (!str)
		return (0);
	l = ft_strlen(str);
	write(0, str, l);
	free(str);
	return (l);
}

int	ft_format(char flag, va_list args)
{
	int	count;

	count = 1;
	if (flag == 'c')
		count = ft_putchar_arg(args);
	else if (flag == 's')
		count = ft_putstr_arg(args);
	else if (flag == 'd' || flag == 'i')
		count = ft_putnbr_arg(args);
	else if (flag == 'u')
		count = ft_putnbr_unsigned_fd(args);
	else if (flag == 'p')
		count = ft_puthex_ptr(args);
	else if (flag == 'x')
		count = ft_puthex_ui(0, args);
	else if (flag == 'X')
		count = ft_puthex_ui(1, args);
	else if (flag == '%')
		ft_putchar_fd('%', 0);
	return (count);
}

int		ft_printf(const char *str, ...)
{
	va_list	args;
	size_t	i;
	size_t	count;

	va_start(args, str);
	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			count += ft_format(str[i + 1], args);
			i++;
		}
		else
		{
			ft_putchar_fd(str[i], 0);
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}
