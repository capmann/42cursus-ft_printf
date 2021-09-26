/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarteau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 21:54:18 by cmarteau          #+#    #+#             */
/*   Updated: 2020/07/03 22:32:13 by cmarteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_putnbr(long n)
{
	long	nbr;
	int		len;

	len = ft_nblen(n);
	if (n < 0)
	{
		ft_putchar('-', 1);
		nbr = (n * -1);
	}
	else
		nbr = n;
	if (nbr > 9)
		ft_putnbr(nbr / 10);
	ft_putchar((char)(nbr % 10 + 48), 1);
	return (len);
}

int		ft_putnbr_u(unsigned int n)
{
	if (n > 9)
		ft_putnbr_u(n / 10);
	ft_putchar((char)(n % 10 + 48), 1);
	return (ft_nblen_u(n));
}

int		ft_putnbr_xx(unsigned long n, char c)
{
	if (n > 15)
		ft_putnbr_xx(n / 16, c);
	ft_putchar((char)(n % 16 + 48), 1);
	return (ft_nblen_xx(n, c));
}

int		ft_itoahex(unsigned long n, char a)
{
	unsigned long	nbr;
	int				count;

	if (a == 'p')
		nbr = (unsigned long)n;
	else
		nbr = (unsigned int)n;
	if (nbr > 15)
		ft_itoahex(nbr / 16, a);
	(a == 'X') ? ft_putchar(HEXAUP[nbr % 16], 1) \
	: ft_putchar(HEXA[nbr % 16], 1);
	count = 1;
	while (nbr > 15)
	{
		nbr /= 16;
		count++;
	}
	return (count);
}

char	*ft_substr(const char *s, int start, size_t len)
{
	int		i;
	char	*memory;

	i = 0;
	if (start > ft_strlen((char *)s) || start == -1)
	{
		if (!(memory = malloc(1)))
			return (0);
		memory[0] = 0;
		return (memory);
	}
	if (!(memory = malloc(sizeof(char) * (len + 1))))
		return (0);
	while (len-- > 0)
	{
		memory[i] = s[i + start];
		i++;
	}
	memory[i] = '\0';
	return (memory);
}
