/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkflags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarteau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 22:23:08 by cmarteau          #+#    #+#             */
/*   Updated: 2020/07/04 00:40:36 by cmarteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_nblen(long n)
{
	int count;

	count = 1;
	if (n < 0)
		count = 2;
	while (n >= 10 || n <= -10)
	{
		n /= 10;
		count++;
	}
	return (count);
}

int	ft_nblen_u(unsigned int n)
{
	int count;

	count = 1;
	while (n >= 10)
	{
		n /= 10;
		count++;
	}
	return (count);
}

int	ft_nblen_xx(unsigned long n, char c)
{
	unsigned int	count;
	unsigned int	nbr;

	nbr = (unsigned int)n;
	if (c == 'p')
	{
		count = 3;
		while (n >= 16)
		{
			n /= 16;
			count++;
		}
	}
	else
	{
		count = 1;
		while (nbr >= 16)
		{
			nbr /= 16;
			count++;
		}
	}
	return (count);
}

int	ft_putchar(char c, int i)
{
	int d;

	d = 0;
	while (i != 0)
	{
		write(1, &c, 1);
		i--;
		d++;
	}
	return (d);
}

int	ft_putstr(char *s, int d)
{
	int i;

	i = 0;
	if (d == -1)
		return (0);
	if (*s && d != 0)
	{
		while (s[i] && d > 0)
		{
			ft_putchar(s[i], 1);
			i++;
			d--;
		}
		return (i);
	}
	else
	{
		while (s[i])
		{
			ft_putchar(s[i], 1);
			i++;
		}
		return (i);
	}
}
