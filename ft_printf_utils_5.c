/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarteau <cmarteau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 19:33:01 by cmarteau          #+#    #+#             */
/*   Updated: 2020/07/04 00:49:38 by cmarteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_rightflags_i(char *str, t_argu arg, int sc)
{
	int count;
	int i;
	int j;
	int p;
	int w;

	count = 0;
	j = ((str[0] == '0' && str[1] == '-') ? 2 : 1);
	i = ((sc == 2) ? 1 : ft_search(str, '.'));
	p = ft_atoi_plus(str, i);
	w = ft_atoi_plus(str, j);
	if (sc == 2 && p > ft_nblen(arg.i))
		return (count += ft_putchar(' ', p - ft_nblen(arg.i)));
	if (sc == 6 && ft_nblen(arg.i) <= p && p < w && arg.i < 0)
		return (count += ft_putchar(' ', w - p - 1));
	if (sc == 6 && ft_nblen(arg.i) <= p && p < w)
		return (count += ft_putchar(' ', w - p));
	if (sc == 6 && p < w && w > ft_nblen(arg.i))
		return (count += ft_putchar(' ', w - ft_nblen(arg.i)));
	return (0);
}

int	ft_rightflags_u(char *str, t_argu arg, int sc)
{
	int count;
	int i;
	int j;
	int p;
	int w;

	count = 0;
	j = ((str[0] == '0' && str[1] == '-') ? 2 : 1);
	i = ((sc == 2) ? 1 : ft_search(str, '.'));
	p = ft_atoi_plus(str, i);
	w = ft_atoi_plus(str, j);
	if (sc == 2 && p > ft_nblen_u(arg.u))
		return (count += ft_putchar(' ', p - ft_nblen_u(arg.u)));
	if (sc == 6 && ft_nblen_u(arg.u) < p && p < w)
		return (count += ft_putchar(' ', w - p));
	if (sc == 6 && p < w && w > ft_nblen_u(arg.u))
		return (count += ft_putchar(' ', w - ft_nblen(arg.u)));
	return (0);
}

int	ft_rightflags_xx(char *str, t_argu arg, char c, int sc)
{
	int count;
	int i;
	int j;
	int p;
	int w;

	count = 0;
	j = ((str[0] == '0' && str[1] == '-') ? 2 : 1);
	i = ((sc == 2) ? 1 : ft_search(str, '.'));
	p = ft_atoi_plus(str, i);
	w = ft_atoi_plus(str, j);
	if (sc == 2 && p > ft_nblen_xx(arg.l, c))
		return (count += ft_putchar(' ', p - ft_nblen_xx(arg.l, c)));
	if (sc == 6 && ft_nblen_xx(arg.l, c) < p && p < w)
		return (count += ft_putchar(' ', w - p));
	if (sc == 6 && p < w && w > ft_nblen_xx(arg.l, c))
		return (count += ft_putchar(' ', w - ft_nblen_xx(arg.l, c)));
	return (0);
}

int	ft_rightflags_s(char *str, t_argu arg, int sc, char c)
{
	int count;
	int	len;
	int	p;
	int	m;

	count = 0;
	p = ft_atoi_plus(str, ft_search(str, '.'));
	m = ft_atoi_plus(str, ft_search(str, '-'));
	len = (c == 'c') ? 1 : ft_strlen(arg.s);
	if (sc == 6 && m >= len && p == 0 && c == 'c')
		return (count += ft_putchar(' ', m - 1));
	if ((sc == 6 && m >= len && p == 0) || (ft_search(str, '.') >= 0 &&
	sc == 2 && str[ft_search(str, '.') + 1] == 0))
		return (count += ft_putchar(' ', m));
	if ((sc == 2 && m > len && (ft_search(str, '.') < 0 ||
	str[ft_search(str, '.') + 1] == '-')) || (sc == 6 && m > len && p > len))
		return (count += ft_putchar(' ', m - len));
	if (sc == 6 && m >= p && m > len)
		return (count += ft_putchar(' ', m - p));
	if ((sc == 2 || sc == 6) && p > len && m > len)
		return (count += ft_putchar(' ', p - len));
	if (sc == 6 && m > p && p < len)
		return (count += ft_putchar(' ', m - p));
	return (0);
}

int	ft_checkflags_strunc(char *str, t_argu arg)
{
	int count;
	int i;

	count = 0;
	i = ft_search(str, '.');
	if (!*str)
		return (0);
	if (i >= 0 && str[i + 1] >= '1' && str[i + 1] <= '9')
	{
		if (ft_atoi_plus(str, i) < ft_strlen(arg.s))
			return (count += ft_atoi_plus(str, i));
		return (0);
	}
	if (i >= 0 && str[i + 1] == '0' && \
	str[i + 2] >= '1' && str[i + 2] <= '9')
	{
		if (ft_atoi_plus(str, i + 1) < ft_strlen(arg.s))
			return (count += ft_atoi_plus(str, i + 1));
	}
	if (i >= 0 && str[i + 1] == '0' && arg.s[0] != '(' && arg.s[1] != 'n' && \
	arg.s[2] != 'u' && arg.s[3] != 'l' && arg.s[4] != 'l' && arg.s[5] != ')')
		return (-1);
	if (i >= 0 && str[i + 1] == '\0')
		return (-1);
	return (0);
}
