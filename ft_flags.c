/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarteau <cmarteau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 19:33:01 by cmarteau          #+#    #+#             */
/*   Updated: 2020/07/04 01:02:01 by cmarteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_zero(char *flags)
{
	int	zero;

	if (flags[0] == '0')
		zero = 1;
	else
		(zero = 0);
	return (zero);
}

int	ft_minus(char *flags)
{
	int	minus;

	if ((flags[0] == '-' && flags[1] != '.') || (flags[1] == '-'))
		minus = 1;
	else
		minus = 0;
	return (minus);
}

int	ft_width(char *flags)
{
	int	width;
	int i;
	int j;

	i = 0;
	j = ft_search(flags, '.');
	while (flags[i] && (flags[i] < '1' || flags[i] > '9'))
		i++;
	if (flags[i] >= '1' && flags[i] <= '9' && (j < 0 || i < j))
		width = 1;
	else
		width = 0;
	return (width);
}

int	ft_preci(char *flags)
{
	int	preci;
	int	i;

	if ((i = ft_search(flags, '.')) >= 0 && ((flags[i + 1] >= '0' \
	&& flags[i + 1] <= '9')))
		preci = 1;
	else
		preci = 0;
	return (preci);
}

int	ft_flags_parsing(char *flags)
{
	int	z;
	int	m;
	int	w;
	int	p;
	int a;

	z = ft_zero(flags);
	m = ft_minus(flags);
	w = ft_width(flags);
	p = ft_preci(flags);
	if (w == 0 && p == 0)
		a = 0;
	if (p == 0 && w == 1 && m == 0 && z == 0)
		a = 1;
	if ((p == 0 && w == 1 && m == 1) && (z == 0 || z == 1))
		a = 2;
	if (p == 0 && w == 1 && m == 0 && z == 1)
		a = 3;
	if (p == 1 && w == 0)
		a = 4;
	if (p == 1 && w == 1 && m == 0)
		a = 5;
	if (p == 1 && w == 1 && m == 1)
		a = 6;
	return (a);
}
