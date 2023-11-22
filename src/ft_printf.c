/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuminov <emuminov@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 21:32:35 by emuminov          #+#    #+#             */
/*   Updated: 2023/11/22 23:40:51 by emuminov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>

#include "../lib/libft.h"
#include "ft_printf.h"

static void	ft_putnbr_unsigned_fd(unsigned int n, int fd)
{
	long	nbr;

	nbr = (long) n;
	if (nbr < 0)
	{
		ft_putchar_fd('-', fd);
		nbr = -nbr;
	}
	if (nbr >= 10)
	{
		ft_putnbr_fd((nbr / 10), fd);
		ft_putnbr_fd((nbr % 10), fd);
	}
	if (nbr < 10)
	{
		ft_putchar_fd(nbr + '0', fd);
	}
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
	ft_putstr_fd("0x", 0);
	ft_putstr_fd(hex, 0);
	l = ft_strlen(hex);
	free(hex);
	return (l + 2);
}

static void ft_puthex_ui(int toupper, va_list args)
{
	size_t	i;
	unsigned int arg = va_arg(args, unsigned int);
	char *hex = ft_ltoa_base("0123456789abcdef", (long) arg);
	if (!hex)
	{
		ft_putstr_fd("(nil)", 0);
		return ;
	}
	if (toupper)
	{
		i = 0;
		while (hex[i])
		{
			hex[i] = ft_toupper(hex[i]);
			i++;
		}
	}
	ft_putstr_fd(hex, 0);
	free(hex);
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
		count = ft_putnbr_unsigned_fd(va_arg(args, unsigned int), 0);
	else if (flag == 'p')
		count = ft_puthex_ptr(args);
	else if (flag == 'x')
		ft_puthex_ui(0, args);
	else if (flag == 'X')
		ft_puthex_ui(1, args);
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
