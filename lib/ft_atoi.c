/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuminov <emuminov@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:50:50 by emuminov          #+#    #+#             */
/*   Updated: 2023/11/13 10:48:12 by emuminov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int		result;
	short	sign;
	size_t	i;

	sign = 1;
	result = 0;
	i = 0;
	while (nptr[i] == '\t' || nptr[i] == ' ' || nptr[i] == '\r'
		|| nptr[i] == '\v' || nptr[i] == '\n' || nptr[i] == '\f')
		i++;
	if (nptr[i] == '-')
	{
		sign = -sign;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	while (nptr[i])
	{
		if (!ft_isdigit(nptr[i]))
			break ;
		result = (result * 10) + nptr[i++] - '0';
	}
	return (result * sign);
}
