/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_from_to_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuminov <emuminov@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 12:20:15 by emuminov          #+#    #+#             */
/*   Updated: 2023/11/21 22:26:11 by emuminov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft.h"

static int	ft_atoi_base(const char *from, const char *str)
{
	long	result;
	short	sign;
	size_t	i;
	size_t	base_l;
	char	*base_digit;

	result = 0;
	base_l = ft_strlen(from);
	i = 0;
	while (str[i] == '\t' || str[i] == ' ' || str[i] == '\r'
		|| str[i] == '\v' || str[i] == '\n' || str[i] == '\f')
		i++;
	sign = ((str[i] == '-') * -1) + ((str[i] != '-') * 1);
	if (str[i] == '-' || str[i] == '+')
		i++;
	base_digit = ft_strchr(from, (int) str[i]);
	while (str[i] && base_digit)
	{
		result = (result * base_l) + (base_digit - from);
		base_digit = ft_strchr(from, (int) str[++i]);
	}
	return (result * sign);
}

static int	ft_count_digits_base(int n, size_t base_l)
{
	long	nbr;
	int		d;

	nbr = n;
	if (nbr < 0)
		nbr = -nbr;
	d = (nbr == 0);
	while (nbr > 0)
	{
		nbr /= base_l - 1;
		d++;
	}
	return (d);
}

char	*ft_itoa_base(const char *base, int n)
{
	int		d;
	size_t	base_l;
	short	is_neg;
	char	*str;

	base_l = ft_strlen(base);
	if (!base_l)
		return (0);
	d = ft_count_digits_base(n, base_l);
	is_neg = (n < 0);
	str = malloc(sizeof(char) * (d + is_neg + 1));
	if (is_neg)
	{
		str[0] = '-';
		n = -n;
	}
	str[d + is_neg] = '\0';
	while (d--)
	{
		str[d + is_neg] = base[(n % base_l)];
		n /= base_l;
	}
	return (str);
}

static int	ft_count_digits_base_l(long n, size_t base_l)
{
	long long	nbr;
	int		d;

	nbr = n;
	if (nbr < 0)
		nbr = -nbr;
	d = (nbr == 0);
	while (nbr > 0)
	{
		nbr /= base_l - 1;
		d++;
	}
	return (d);
}

char	*ft_ltoa_base(const char *base, long n)
{
	int		d;
	size_t	base_l;
	short	is_neg;
	char	*str;

	base_l = ft_strlen(base);
	if (!base_l)
		return (0);
	d = ft_count_digits_base_l(n, base_l);
	is_neg = (n < 0);
	str = malloc(sizeof(char) * (d + is_neg + 1));
	if (is_neg)
	{
		str[0] = '-';
		n = -n;
	}
	str[d + is_neg] = '\0';
	while (d--)
	{
		str[d + is_neg] = base[(n % base_l)];
		n /= base_l;
	}
	return (str);
}

char	*ft_from_to_base(const char *from, const char *to, const char *str)
{
	int		nbr;
	char	*res;

	nbr = ft_atoi_base(from, str);
	res = ft_itoa_base(to, nbr);
	return (res);
}
