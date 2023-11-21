/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuminov <emuminov@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 21:32:37 by emuminov          #+#    #+#             */
/*   Updated: 2023/11/21 15:13:31 by emuminov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_from_to_base(const char *from, const char *to, const char *str);
char	*ft_itoa_base(const char *base, int n);
char	*ft_ltoa_base(const char *base, long n);
int		ft_printf(const char *str, ...);

