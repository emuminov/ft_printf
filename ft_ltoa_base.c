/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuminov <emuminov@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 12:20:15 by emuminov          #+#    #+#             */
/*   Updated: 2023/12/07 00:56:33 by emuminov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_count_digits_base_l(long n, size_t base_l)
{
	unsigned long	nbr;
	int			d;

	nbr = n;
	d = (nbr == 0);
	while (nbr > 0)
	{
		nbr /= base_l;
		d++;
	}
	return (d);
}

char	*ft_ltoa_base(const char *base, long n)
{
	int				d;
	unsigned long	nbr;
	size_t			base_l;
	short			is_neg;
	char			*str;

	base_l = ft_strlen(base);
	if (!base_l)
		return (0);
	d = ft_count_digits_base_l(n, base_l);
	is_neg = (n < 0);
	str = malloc(sizeof(char) * (d + is_neg + 1));
	if (!str)
		return (0);
	if (is_neg)
		str[0] = '-';
	nbr = n;
	str[d + is_neg] = '\0';
	while (d--)
	{
		str[d + is_neg] = base[(nbr % base_l)];
		nbr /= base_l;
	}
	return (str);
}

static int	ft_count_digits_base_ul(unsigned long n, size_t base_l)
{
	int			d;

	d = (n == 0);
	while (n > 0)
	{
		n /= base_l;
		d++;
	}
	return (d);
}

char	*ft_ultoa_base(const char *base, unsigned long n)
{
	int				d;
	size_t			base_l;
	char			*str;

	base_l = ft_strlen(base);
	if (!base_l)
		return (0);
	d = ft_count_digits_base_ul(n, base_l);
	str = malloc(sizeof(char) * (d + 1));
	if (!str)
		return (0);
	str[d] = '\0';
	while (d--)
	{
		str[d] = base[(n % base_l)];
		n /= base_l;
	}
	return (str);
}
