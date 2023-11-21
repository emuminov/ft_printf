/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuminov <emuminov@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 21:32:35 by emuminov          #+#    #+#             */
/*   Updated: 2023/11/21 23:14:02 by emuminov         ###   ########.fr       */
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

static void ft_puthex(va_list args)
{
	void *arg = va_arg(args, void *);
	if (!arg)
	{
		ft_putstr_fd("(nil)", 0);
		return ;
	}
	char *hex = ft_ltoa_base("0123456789abcdef", (long) arg);
	if (!hex)
	{
		ft_putstr_fd("(nil)", 0);
		return ;
	}
	ft_putstr_fd("0x", 0);
	ft_putstr_fd(hex, 0);
	free(hex);
}

void	ft_format(char flag, va_list args)
{
	if (flag == 'c')
		ft_putchar_fd(va_arg(args, int), 0);
	else if (flag == 's')
		ft_putstr_fd(va_arg(args, char *), 0);
	else if (flag == 'd' || flag == 'i')
		ft_putnbr_fd(va_arg(args, int), 0);
	else if (flag == 'u')
		ft_putnbr_unsigned_fd(va_arg(args, unsigned int), 0);
	else if (flag == 'p')
		ft_puthex(args);
}

int		ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;

	va_start(args, str); i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			ft_format(str[i + 1], args);
			i++;
		}
		else
			ft_putchar_fd(str[i], 0);
		i++;
	}
	va_end(args);
	return (0);
}
