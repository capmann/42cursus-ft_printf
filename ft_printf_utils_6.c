/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarteau <cmarteau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 19:33:01 by cmarteau          #+#    #+#             */
/*   Updated: 2020/07/04 01:06:58 by cmarteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_format(char format, t_argu arg, char *flags, int sc)
{
	int count;

	count = 0;
	if (format == 'c')
		count += ft_convert_s(arg, 'c', flags, sc);
	if (format == 's')
	{
		if (arg.s == NULL && flags[0] == '.' &&
		flags[1] == '0' && ft_strlen(flags) == 2)
			return (0);
		if (arg.s == NULL)
			arg.s = "(null)";
		count += ft_convert_s(arg, 's', flags, sc);
	}
	if (format == 'd' || format == 'i')
		count += ft_convert_i(arg, flags, sc);
	if (format == 'u')
		count += ft_convert_u(arg, flags, sc);
	if (format == 'X' || format == 'x' || format == 'p')
		count += ft_convert_x(arg, format, flags, sc);
	if (format == '%')
		count += ft_convert_s(arg, 'c', flags, sc);
	return (count);
}

t_argu	ft_function(va_list *ap, char format)
{
	t_argu arg;

	ft_init(&arg);
	if (format == 'c')
	{
		arg.c = va_arg(*ap, int);
		arg.s = &arg.c;
	}
	if (format == 's')
		arg.s = va_arg(*ap, char *);
	if (format == 'd' || format == 'i')
		arg.i = va_arg(*ap, int);
	if (format == 'u')
		arg.u = va_arg(*ap, unsigned int);
	if (format == 'X' || format == 'x' || format == 'p')
		arg.l = va_arg(*ap, unsigned long);
	if (format == '%')
	{
		arg.c = '%';
		arg.s = &arg.c;
	}
	return (arg);
}

char	*ft_flagsait(va_list *ap, char *flags)
{
	char	*flags2;
	char	*flags3;

	flags3 = NULL;
	flags2 = NULL;
	if (ft_search(flags, '*') >= 0)
	{
		flags2 = ft_star(flags, va_arg(*ap, int));
		if (ft_search(flags2, '*') >= 0)
			flags3 = ft_star(flags2, va_arg(*ap, int));
	}
	else
		return (ft_strcpy(flags));
	if (flags3 != NULL)
		return (flags3);
	else
		return (flags2);
}

int		ft_test(char format, char *flags)
{
	if (format != 'p' && format != 'x' && format != 'X' && format != 'i'
	&& format != 'd' && format != 's' && ((flags[0] == '.' &&
	ft_strlen(flags) == 1) ||
	(flags[1] == '0' && flags[2] < '0' && flags[2] > '9')))
		return (0);
	return (1);
}

int		ft_test2(char format)
{
	if (format != 'c' && format != 'x' && format != 'X' && \
	format != '%' && format != 's' && format != 'd' && \
	format != 'i' && format != 'p' && format != 'u')
		return (0);
	return (1);
}
