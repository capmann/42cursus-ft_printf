/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarteau <cmarteau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 19:33:01 by cmarteau          #+#    #+#             */
/*   Updated: 2020/07/04 01:01:50 by cmarteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_convert_s(t_argu arg, char c, char *flags, int sc)
{
	int count;

	count = 0;
	count += ft_flags_s(flags, arg, sc, c);
	if (c == 'c')
	{
		write(1, &arg.s[0], 1);
		count++;
	}
	else if (ft_search(flags, '.') >= 0 &&
	flags[ft_search(flags, '.') + 1] == '0')
		count += 0;
	else
		count += ft_putstr(arg.s, ft_checkflags_strunc(flags, arg));
	if (sc != 0)
		count += ft_rightflags_s(flags, arg, sc, c);
	return (count);
}

int	ft_convert_i(t_argu arg, char *flags, int sc)
{
	int count;
	int neg;

	count = 0;
	neg = 0;
	if (ft_yo(flags) == 1 && arg.i == 0)
		return (0);
	count += ft_flags_i(flags, arg, sc);
	if (arg.i < 0 && (((sc == 5 || sc == 6 || sc == 4 || sc == 1
	|| sc == 3) && count != 0)))
	{
		neg = 1;
		arg.i = arg.i * (-1);
	}
	if (arg.i == 0 && (((sc == 5 || sc == 6) &&
	flags[ft_search(flags, '.') + 1] == '0') || ((sc == 1 || sc == 2)
	&& flags[ft_search(flags, '.') - 1] == '1'
	&& !flags[ft_search(flags, '.') + 1])))
		count += ft_putchar(' ', 1);
	else
		count += ft_putnbr(arg.i);
	arg.i = (neg == 1) ? arg.i * (-1) : arg.i;
	if (sc != 0)
		count += ft_rightflags_i(flags, arg, sc);
	return (count);
}

int	ft_convert_u(t_argu arg, char *flags, int sc)
{
	int count;

	count = 0;
	if (ft_yo(flags) == 1 && arg.u == 0)
		return (0);
	count += ft_flags_u(flags, arg, sc);
	if (arg.u == 0 && flags[0] == '.' && flags[1] == '0' &&
	ft_strlen(flags) == 2)
		return (count += 0);
	if (arg.u == 0 && (((sc == 2 || sc == 1) && \
	(ft_search(flags, '.') >= 0 && flags[ft_search(flags, '.') + 1] != '-'))
	|| ((sc == 5 || sc == 6) && flags[ft_search(flags, '.') + 1] == '0')))
		count += ft_putchar(' ', 1);
	else
		count += ft_putnbr_u(arg.u);
	if (sc != 0)
		count += ft_rightflags_u(flags, arg, sc);
	return (count);
}

int	ft_convert_x(t_argu arg, char c, char *flags, int sc)
{
	int count;

	count = 0;
	if (ft_yo(flags) && !(unsigned int)arg.l)
		return (0);
	if (c == 'p')
		count += ft_flags_p(flags, arg, sc);
	else
		count += ft_flags_xx(flags, arg, sc);
	if ((c == 'p' && arg.l == 0 && ((sc == 0 && \
	ft_search(flags, '.') >= 0) || (sc == 1 && \
	ft_search(flags, '.') >= 0) || (sc == 4 && flags[1] == '0'))) ||
	(arg.l == 0 && flags[0] == '.' && flags[1] == '0' && ft_strlen(flags) == 2))
		return (count += 0);
	if ((unsigned int)arg.l == 0 && (((sc == 2 || sc == 1) && \
	(ft_search(flags, '.') >= 0 && flags[ft_search(flags, '.') + 1] != '-')) ||
	((sc == 5 || sc == 6) && flags[ft_search(flags, '.') + 1] == '0')))
		count += ft_putchar(' ', 1);
	else
		count += ft_itoahex(arg.l, c);
	if (sc != 0)
		count += ft_rightflags_xx(flags, arg, c, sc);
	return (count);
}
