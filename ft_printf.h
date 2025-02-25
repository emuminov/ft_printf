/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuminov <emuminov@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 21:32:37 by emuminov          #+#    #+#             */
/*   Updated: 2023/12/07 00:55:57 by emuminov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "libft/libft.h"

char	*ft_ltoa_base(const char *base, long n);
char	*ft_ultoa_base(const char *base, unsigned long n);
int		ft_putnbr(va_list args);
int		ft_putnbr_unsigned(va_list args);
int		ft_puthex_ptr(va_list args);
int		ft_puthex_ui(int toupper, va_list args);
int		ft_putstr_arg(va_list args);
int		ft_printf(const char *str, ...);
#endif
