/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarteau <cmarteau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 19:33:01 by cmarteau          #+#    #+#             */
/*   Updated: 2020/07/04 01:11:37 by cmarteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_flags_i(char *str, t_argu arg, int sc)
{
	int	count;
	int	i;
	int	len;
	int	p;
	int	w;

	count = 0;
	i = ft_search(str, '.');
	p = ft_atoi_plus(str, i);
	w = ft_atoi_plus(str, 0);
	len = ft_nblen(arg.i);
	if (p >= len && (sc == 4 || sc == 6 || (sc == 5 && p >= w)))
		count += (arg.i < 0) ? ft_putchar('-', 1) +
		ft_putchar('0', p - len + 1) : ft_putchar('0', p - len);
	if ((sc == 1 && w >= len) || (sc == 5 && p < len && w >= len))
		count += (arg.i < 0) ? ft_putchar(' ', w - len) +
		ft_putchar('-', 1) : ft_putchar(' ', w - len);
	if (sc == 3 && w > len)
		count += (arg.i >= 0) ? ft_putchar('0', w - len) :
		ft_putchar('-', 1) + ft_putchar('0', w - len);
	if (sc == 5 && len <= p && p < w)
		count += (arg.i < 0) ? ft_putchar(' ', w - p - 1) +
		ft_putchar('-', 1) + ft_putchar('0', p - len + 1) : \
		ft_putchar(' ', w - p) + ft_putchar('0', p - len);
	return (count);
}

int	ft_flags_u(char *str, t_argu arg, int sc)
{
	int	count;
	int	i;
	int	len;
	int	p;
	int	w;

	count = 0;
	i = ft_search(str, '.');
	p = ft_atoi_plus(str, i);
	w = ft_atoi_plus(str, 0);
	len = ft_nblen_u(arg.u);
	if ((sc == 1 && w >= len) || (sc == 5 && p <= len && len < w))
		return (count += ft_putchar(' ', w - len));
	if (sc == 3 && w > len)
		return (count += ft_putchar('0', w - len));
	if (p > len && (sc == 4 || (sc == 5 && p >= w) || sc == 6))
		return (count += ft_putchar('0', p - len));
	if (sc == 5 && p < w && w > len && p > len)
		return (count += ft_putchar(' ', w - p) + ft_putchar('0', p - len));
	return (0);
}

int	ft_flags_p(char *str, t_argu arg, int sc)
{
	int	count;
	int	len;
	int	p;
	int	w;

	count = 0;
	p = ft_atoi_plus(str, ft_search(str, '.'));
	w = ft_atoi_plus(str, 0);
	len = ft_nblen_xx(arg.l, 'p');
	if (w > len && arg.l >= 0 && (sc == 1 || (sc == 5 && p < len)))
		return (ft_putchar(' ', w - len) + ft_putstr("0x", 2));
	count += ft_putstr("0x", 2);
	if (sc == 3 && w > len && arg.l >= 0)
		count += ft_putchar('0', w - len);
	if ((sc == 4 && p >= len) || (sc == 5 && ((w < len && len < p) ||
	(len < w && w < p))) || (sc == 6 && ((w < len && len < p) ||
	(p >= len && w >= len))))
		count += ft_putchar('0', p - len);
	if (sc == 5 && len < p && p < w && w > len)
		count += ft_putchar(' ', w - len) + ft_putstr("0x", 2) +
		ft_putchar('0', p - len);
	return (count);
}

int	ft_flags_xx(char *str, t_argu arg, int sc)
{
	int	count;
	int	i;
	int	len;
	int	p;
	int	w;

	count = 0;
	i = ft_search(str, '.');
	p = ft_atoi_plus(str, i);
	w = ft_atoi_plus(str, 0);
	len = ft_nblen_xx(arg.l, 'x');
	if ((sc == 1 && w > len) || (sc == 5 && p <= len && len < w))
		return (count += ft_putchar(' ', w - len));
	if (sc == 3 && w > len)
		return (count += ft_putchar('0', w - len));
	if (p > len && (sc == 4 || (sc == 5 && p >= w) || sc == 6))
		return (count += ft_putchar('0', p - len));
	if (sc == 5 && p < w && w > len && p > len)
		return (count += ft_putchar(' ', w - p) + ft_putchar('0', p - len));
	return (0);
}

int	ft_flags_s(char *str, t_argu arg, int sc, char c)
{
	int	count;
	int	i;
	int	len;
	int	w;

	count = 0;
	i = ft_search(str, '.');
	w = ft_atoi_plus(str, 0);
	len = (c == 'c') ? 1 : ft_strlen(arg.s);
	if (arg.s[0] == '%' && sc == 3)
		return (count += ft_putchar('0', w - len));
	if (c == 'c' && arg.s[0] == '%' && sc == 5 && i >= 0 &&
	str[i + 1] == '0' && w >= len)
		return (count += ft_putchar(' ', w - len));
	if ((sc == 1 || sc == 3) && i >= 0 && str[i + 1] == '\0')
		return (count += ft_putchar(' ', w));
	if (sc == 1 && w > len)
		return (count += ft_putchar(' ', w - len));
	if (sc == 5 && ft_atoi_plus(str, i) < w && ft_atoi_plus(str, i) <= len)
		return (count += ft_putchar(' ', w - ft_atoi_plus(str, i)));
	if (sc == 5 && ft_atoi_plus(str, i) >= len && w > len)
		return (count += ft_putchar(' ', w - len));
	return (0);
}
