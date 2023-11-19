/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuminov <emuminov@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 21:32:35 by emuminov          #+#    #+#             */
/*   Updated: 2023/11/18 21:32:35 by emuminov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	args;

	va_start(args, str);

	return (0);
}
