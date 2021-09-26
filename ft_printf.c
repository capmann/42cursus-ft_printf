/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarteau <cmarteau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 19:33:01 by cmarteau          #+#    #+#             */
/*   Updated: 2020/07/04 01:14:20 by cmarteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_yo(char *flags)
{
	if ((ft_strlen(flags) == 2 && ((flags[0] == '0' && flags[1] == '.') ||
	(flags[0] == '-' && flags[1] == '.') || (flags[0] == '.' &&
	flags[1] == '0'))) || (ft_strlen(flags) == 3 && ((flags[0] == '-' &&
	flags[1] == '0' && flags[2] == '.') || (flags[0] == '0' &&
	flags[1] == '.' && flags[2] == '0') || (flags[0] == '-' &&
	flags[1] == '.' && flags[2] == '0'))) || (ft_strlen(flags) == 4 &&
	((flags[0] == '-' || flags[0] == '0') && flags[1] == '0' &&
	flags[2] == '.' && flags[3] == '0'))
	|| (ft_strlen(flags) == 1 && flags[0] == '.'))
		return (1);
	return (0);
}

void	ft_init(t_argu *arg)
{
	arg->c = 'd';
	arg->s = NULL;
	arg->i = 0;
	arg->u = 0;
	arg->p = 0;
	arg->l = 0;
}

int		ft_count(const char *format, int i, va_list *ap)
{
	int		d;
	int		count;
	char	*flags;
	char	*blink;

	i++;
	d = 0;
	count = 0;
	while (ft_test2(format[i]) == 0)
	{
		i++;
		d++;
	}
	blink = ft_substr(format, i - d, d);
	flags = ft_flagsait(ap, blink);
	if (ft_test(format[i], flags) == 0)
		return (0);
	count += ft_format(format[i], ft_function(ap, format[i]), \
	flags, ft_flags_parsing(flags));
	i++;
	free(flags);
	return (count);
}

int		ft_ion(const char *format, int i)
{
	i++;
	while (ft_test2(format[i]) == 0)
		i++;
	return (i + 1);
}

int		ft_printf(const char *format, ...)
{
	int		i;
	int		count;
	va_list ap;

	i = 0;
	count = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			count += ft_count(format, i, &ap);
			i = ft_ion(format, i);
		}
		if (format[i] && format[i] != '%')
		{
			ft_putchar(format[i], 1);
			i++;
			count++;
		}
	}
	return (count);
	va_end(ap);
}
